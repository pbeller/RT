#include "shape.h"

int		tube_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_vector	oc;
	float		a;
	float		b;
	float		c;
	float		tmp;
	t_ray		r;
	
	r = *ray;
	r = rotation_x(object, &r);
	r = rotation_y(object, &r);
	r = rotation_z(object, &r);
	oc.x = r.ori.x - object->pos_x;
	oc.y = 0;
	oc.z = r.ori.z - object->pos_z;
	a = r.dir.x * r.dir.x + r.dir.z * r.dir.z;
	b = (oc.x * r.dir.x + oc.z * r.dir.z);
	c = (oc.x * oc.x + oc.y * oc.y + oc.z * oc.z) - object->radius * object->radius;
	tmp = b*b - a*c;
	closest = FLT_MAX;
	if (tmp > 0)
	{	
	rec->normal.x = (rec->p.x - object->pos_x) / object->radius;
	rec->normal.y = -1;
	rec->normal.z = (rec->p.z - object->pos_z) / object->radius;

		tmp = (-b - sqrt(b*b - a*c)) / a;
		if (0.001 < tmp && tmp < closest)
		{rec->t = tmp;
			point_at(&r, tmp, &rec->p);
			return (1);
		}
		tmp = (-b + sqrt(b*b - a*c)) / a;
		if (0.001 < tmp && tmp < closest)
		{rec->t = tmp;
			point_at(&r, tmp, &rec->p);
			return (1);
		}
	}
	return (0);
}