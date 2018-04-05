#include "shape.h"

static int	get_values(t_object *object, const t_ray *ray, t_hit_rec *rec, float tmp)
{
	rec->t = tmp;
	point_at(ray, tmp, &rec->p);
	rec->normal.x = (rec->p.x - object->pos_x) / object->radius;
	rec->normal.y = (rec->p.y - object->pos_y) / object->radius;
	rec->normal.z = (rec->p.z - object->pos_z) / object->radius;
	return (1);
}

int			sphere_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
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