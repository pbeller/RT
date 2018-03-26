#include "rt.h"

int	get_values(t_object *object, t_ray *ray, t_hit_rec *rec, float tmp)
{
	rec->t = tmp;
	point_at(ray, tmp, &rec->p);
	rec->normal.x = (rec->p.x - object->pos_x) / object->radius;
	rec->normal.y = (rec->p.y - object->pos_y) / object->radius;
	rec->normal.z = (rec->p.z - object->pos_z) / object->radius;
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
		if (0.0 < tmp && tmp < closest)
			return (get_values(object, ray, rec, tmp));
		tmp = (-b + sqrt(b*b - a*c)) / a;
		if (0.0 < tmp && tmp < closest)
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

t_vector	get_color(t_env *env, t_ray *ray)
{
	t_vector		color;
	float			t;
	t_hit_rec		rec;
	t_vector		target;
	t_vector		rand_unit_vect;
	t_ray			tmp_ray;

	if (hit(env, ray, &rec))
	{
		rand_unit_vect = random_in_unit_sphere();
		tmp_ray.ori.x = rec.p.x;
		tmp_ray.ori.y = rec.p.y;
		tmp_ray.ori.z = rec.p.z;
		target.x = tmp_ray.ori.x + rec.normal.x + rand_unit_vect.x;
		target.y = tmp_ray.ori.y + rec.normal.y + rand_unit_vect.y;
		target.z = tmp_ray.ori.z + rec.normal.z + rand_unit_vect.z;
		tmp_ray.dir.x = target.x - rec.p.x;
		tmp_ray.dir.y = target.y - rec.p.y;
		tmp_ray.dir.z = target.z - rec.p.z;
		return (prod_float(get_color(env, &tmp_ray), 0.5));
	}
	else
	{
		normalise(&ray->dir);
		t = 0.5 * (ray->dir.y + 1.0);
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
				tmp = get_color(env, &ray);
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