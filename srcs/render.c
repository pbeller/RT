#include "rt.h"

int	get_values(t_object *object, t_ray *ray, t_hit_rec *rec, float tmp)
{
	rec->t = tmp;
	point_at(ray, tmp, &rec->p);
	rec->normal.x = (rec->p.x - object->pos_x) / object->radius;
	rec->normal.y = (rec->p.y - object->pos_y) / object->radius;
	rec->normal.z = (rec->p.z - object->pos_z) / object->radius;
	rec->obj_ptr = object;
	return (1);
}

int		sphere_hit(t_object *object, t_ray *ray, t_hit_rec *rec, float closest)
{
	t_vector	oc;
	float		a;
	float		b;
	float		c;
	float		tmp;

	oc.x = ray->ori.x - object->pos_x;
	oc.y = ray->ori.y - object->pos_y;
	oc.z = ray->ori.z - object->pos_z;
	a = scal_prod(&ray->dir, &ray->dir);
	b = scal_prod(&oc, &ray->dir);
	c = scal_prod(&oc, &oc) - (object->radius * object->radius);
	tmp = b*b - a*c;
	if (tmp > 0)
	{
		tmp = (-b - sqrt(b*b - a*c)) / a;
		if (0.001 < tmp && tmp < closest)
			return (get_values(object, ray, rec, tmp));
		tmp = (-b + sqrt(b*b - a*c)) / a;
		if (0.001 < tmp && tmp < closest)
			return (get_values(object, ray, rec, tmp));
	}
	return (0);
}

int		object_hit(t_object *object, t_ray *ray, t_hit_rec *rec, float closest)
{
	if (twl_strcmp(object->type, "sphere") == 0)
		return (sphere_hit(object, ray, rec, closest));
	else
		return (0);
}

int		hit(t_env *env, t_ray *ray, t_hit_rec *rec)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;
	int				hit;
	float			closest;
	t_hit_rec		tmp_rec;

	hit = 0;
	closest = FLT_MAX;
	elem = env->objects->head;
	while (elem)
	{
		next = elem->next;
		if (object_hit(elem->data, ray, &tmp_rec, closest))
		{
			hit = 1;
			*rec = tmp_rec;
			closest = rec->t;
		}
		elem = next;
	}
	return (hit);
}

t_vector	random_in_unit_sphere()
{
	t_vector	p;

	do
	{
		set_value_vector(&p, 2.0*drand48()-1, 2.0*drand48()-1, 2.0*drand48()-1);
	}
	while(scal_prod(&p ,&p) >= 1.0);
	return (p);
}

int			scatter_lamberian(t_ray *ray, t_hit_rec *rec, t_vector *attenuation, t_ray *scatter)
{
	t_vector		target;
	t_vector		rand_unit_vect;

	rand_unit_vect = random_in_unit_sphere();
	scatter->ori.x = rec->p.x;
	scatter->ori.y = rec->p.y;
	scatter->ori.z = rec->p.z;
	target.x = scatter->ori.x + rec->normal.x + rand_unit_vect.x;
	target.y = scatter->ori.y + rec->normal.y + rand_unit_vect.y;
	target.z = scatter->ori.z + rec->normal.z + rand_unit_vect.z;
	scatter->dir.x = target.x - rec->p.x;
	scatter->dir.y = target.y - rec->p.y;
	scatter->dir.z = target.z - rec->p.z;
	attenuation->x = rec->obj_ptr->red / (float)255;
	attenuation->y = rec->obj_ptr->green / (float)255;
	attenuation->z = rec->obj_ptr->blue / (float)255;
	(void)ray;
	return (1);
}

t_vector	reflect(t_vector	dir, t_vector	*normal)
{
	t_vector	ret;
	float		dot;

	dot = scal_prod(&dir, normal);
	ret.x = dir.x - 2 * dot * normal->x;
	ret.y = dir.y - 2 * dot * normal->y;
	ret.z = dir.z - 2 * dot * normal->z;
	return (ret);
}

int			scatter_metal(t_ray *ray, t_hit_rec *rec, t_vector *attenuation, t_ray *scatter)
{
	t_vector		reflected;
	t_vector		rand_unit_vect;

	rand_unit_vect = random_in_unit_sphere();

	reflected = reflect(normalise(ray->dir), &rec->normal);
	scatter->ori.x = rec->p.x;
	scatter->ori.y = rec->p.y;
	scatter->ori.z = rec->p.z;
	scatter->dir.x = reflected.x + (1 - rec->obj_ptr->reflection) * rand_unit_vect.x;
	scatter->dir.y = reflected.y + (1 - rec->obj_ptr->reflection) * rand_unit_vect.y;
	scatter->dir.z = reflected.z + (1 - rec->obj_ptr->reflection) * rand_unit_vect.z;
	attenuation->x = rec->obj_ptr->red / (float)255;
	attenuation->y = rec->obj_ptr->green / (float)255;
	attenuation->z = rec->obj_ptr->blue / (float)255;
	return (scal_prod(&scatter->dir, &rec->normal) > 0);
}

int			refract(t_vector *v, t_vector *n, float ni_over_nt, t_vector *refracted)
{
	t_vector		uv;
	float			dt;
	float			discr;

	uv = normalise(*v);
	dt = scal_prod(&uv, n);
	discr = 1.0 - ni_over_nt * ni_over_nt * (1.0 - (dt * dt));
	if (discr > 0)
	{
		refracted->x = ni_over_nt * (v->x - (n->x * dt)) - n->x * sqrt(discr);
		refracted->y = ni_over_nt * (v->y - (n->y * dt)) - n->y * sqrt(discr);
		refracted->z = ni_over_nt * (v->z - (n->z * dt)) - n->z * sqrt(discr);
		return (1);
	}
	else
		return (0);
}

int			scatter_dielectric(t_ray *ray, t_hit_rec *rec, t_vector *attenuation, t_ray *scatter)
{
	t_vector	outward_normal;
	t_vector	reflected;
	float		ni_over_nt;
	t_vector	refracted;

	reflected = reflect(ray->dir, &rec->normal);
	attenuation->x = rec->obj_ptr->red / (float)255;
	attenuation->y = rec->obj_ptr->green / (float)255;
	attenuation->z = rec->obj_ptr->blue / (float)255;
	if (scal_prod(&ray->dir, &rec->normal) > 0)
	{
		outward_normal.x = -rec->normal.x;
		outward_normal.y = -rec->normal.y;
		outward_normal.z = -rec->normal.z;
		ni_over_nt = rec->obj_ptr->refraction;
	}
	else
	{
		outward_normal.x = rec->normal.x;
		outward_normal.y = rec->normal.y;
		outward_normal.z = rec->normal.z;
		ni_over_nt = 1.0 / rec->obj_ptr->refraction;
	}
	if (refract(&ray->dir, &outward_normal, ni_over_nt, &refracted))
	{
		scatter->ori.x = rec->p.x;
		scatter->ori.y = rec->p.y;
		scatter->ori.z = rec->p.z;
		scatter->dir.x = refracted.x;
		scatter->dir.y = refracted.y;
		scatter->dir.z = refracted.z;
	}
	else
	{
		scatter->ori.x = rec->p.x;
		scatter->ori.y = rec->p.y;
		scatter->ori.z = rec->p.z;
		scatter->dir.x = reflected.x;
		scatter->dir.y = reflected.y;
		scatter->dir.z = reflected.z;
		return (0);
	}
	return (1);
}

int			scatter(t_ray *ray, t_hit_rec *rec, t_vector *attenuation, t_ray *scatter)
{
	if (rec->obj_ptr->reflection > 0)
		return (scatter_metal(ray, rec, attenuation, scatter));
	if (rec->obj_ptr->refraction > 0)
		return (scatter_dielectric(ray, rec, attenuation, scatter));
	return (scatter_lamberian(ray, rec, attenuation, scatter));
}

t_vector	empty_vect()
{
	t_vector	vector;
	vector.x = 0;
	vector.y = 0;
	vector.z = 0;
	return (vector);
}

t_vector	get_color(t_env *env, t_ray *prim_ray, int depth)
{
	t_vector		color;
	float			t;
	t_hit_rec		rec;
	t_ray			sec_ray;
	t_vector		att;
	t_vector		tmp;
	t_vector		tmp2;

	if (hit(env, prim_ray, &rec))
	{
		if (depth < 50 && scatter(prim_ray, &rec, &att, &sec_ray))
		{
			tmp2 = get_color(env, &sec_ray, depth + 1);
			tmp.x = att.x *tmp2.x;
			tmp.y = att.y *tmp2.y;
			tmp.z = att.z *tmp2.z;
			return (tmp);
		}
		else
			return (empty_vect());
	}
	else
	{
		prim_ray->dir = normalise(prim_ray->dir);
		t = 0.5 * (prim_ray->dir.y + 1.0);
		color.x = (1.0 - t) + t * 0.5;
		color.y = (1.0 - t) + t * 0.7;
		color.z = (1.0 - t) + t * 1.0;
		return (color);
	}
}

void	draw_img(t_img *img, t_env *env)
{
	int			i;
	int			j;
	int			k;
	t_ray		ray;
	t_vector	col;
	t_vector	tmp;

	env->camera->up_left = new_vector(-2, 1, -1);
	env->camera->hori = new_vector(4, 0, 0);
	env->camera->vert = new_vector(0, 2, 0);
	ray.ori.x = env->camera->pos_x;
	ray.ori.y = env->camera->pos_y;
	ray.ori.z = env->camera->pos_z;
	j = -1;
	while (++j < WIN_HEIGH)
	{
		i = -1;
		while (++i < WIN_WIDTH)
		{
			k = -1;
			set_value_vector(&col, 0, 0, 0);
			while (++k < AA_STRENGH)
			{
				get_ray(&ray, env->camera, i, j);
				tmp = get_color(env, &ray, 0);
				col = add_vector(col, tmp);
			}
			put_pixel(img, i, j, &col);
		}
	}
}

void	render(t_env *env)
{
	t_img	*img;

	(!(img = (t_img*)malloc(sizeof(t_img)))) ? exit(-1) : 0;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIN_WIDTH, WIN_HEIGH, "RT");
	img->ptr = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGH);
	img->buffer = (int*)mlx_get_data_addr(img->ptr, &(img->bpp), &(img->line_s),
														&(img->endian));
	mlx_hook(img->win, 17, 0, clean_quit, img);
	draw_img(img, env);
	mlx_put_image_to_window(img->mlx, img->win, img->ptr, 0, 0);
	mlx_loop(img->mlx);
	destroy(img);
}