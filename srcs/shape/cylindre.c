#include "shape.h"

int		cylindre_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest) // Not possible to change cylinder H ?
{
	t_vector	oc;
	float		a;
	float		b;
	float		c;
	float		temp1;
	float		temp0;
	float		discrim;

	oc.x = ray->ori.x - object->pos_x;
	oc.y = 0;
	oc.z = ray->ori.z - object->pos_z;
	a = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z;
	b = (oc.x * ray->dir.x + oc.z * ray->dir.z);
	c = (oc.x * oc.x + oc.y * oc.y +  oc.z * oc.z) - object->radius * object->radius;
	discrim = b*b - a*c;
	closest = FLT_MAX;
	if (discrim < 0)
		return (0);
	temp0 = (-b + sqrtf(b*b - a*c)) / a;
	temp1 = (-b - sqrtf(b*b - a*c)) / a;
	if(temp0 > temp1)
	{
		float tmp = temp0;
		temp0 = temp1;
		temp1 = tmp;
	}
	float y0 = ray->ori.y + temp0 * ray->dir.y - object->pos_y;
	float y1 = ray->ori.y + temp1 * ray->dir.y -  object->pos_y;
	if (y0 < -1 )
	{
		if(y1 <-1)
			return (0);
		else
		{
			float th = temp0 + (temp1 - temp0) * (y0 + 1) / (y0-y1);
			if(th <= 0)
				return (0);
			if(th < closest && th > 0.001)
			{
				rec->t = th;
				point_at(ray, th, &rec->p);
				rec->normal.x = 0;
				rec->normal.y = -1;
				rec->normal.z = 0;
				return (1);
			}
		}
	}
	else if(y0 >= -1 && y0 <= 1)
	{
		if(temp0 <= 0)
			return (0);
		if(temp0 < closest && temp0 > 0.001)
		{
			rec->t = temp0;
			point_at(ray, temp0, &rec->p);
			rec->normal.x = (rec->p.x - object->pos_x)/object->radius;
			rec->normal.y = 0;
			rec->normal.z = (rec->p.z - object->pos_z)/object->radius;
			return (1);
		}
	}
	else if (y0 >1)
	{
		if(y1 > 1)
			return 0;
		else
		{
			float th = temp0 + (temp1-temp0) * (y0 - 1) / (y0-y1);
			if(th <= 0)
				return(0);
			if(th < closest && th > 0.001)
			{
				rec->t = th;
				point_at(ray, th, &rec->p);
				rec->normal.x = 0;
				rec->normal.y = 1;
				rec->normal.z = 0;
				return (1);
			}
		}
	}
	return (0);
}