#include "shape.h"
/*
t_ray rotation_x(t_object *object, t_ray *ray)
{
	t_ray		r;
	float angle;
	angle = object->rot_x * M_PI / 180 ;

	r.ori.x = ray->ori.x;
	r.ori.y = cos(angle) * ray->ori.y - sin(angle) * ray->ori.z;
	r.ori.z = ray->ori.y * sin(angle) + ray->ori.z * cos(angle);
	r.dir.x = ray->dir.x;
	r.dir.y = cos(angle)*ray->dir.y - sin(angle)*ray->dir.z;
	r.dir.z = sin(angle)*ray->dir.y + cos(angle)* ray->dir.z;// presque bon apart pi/2
	return (r);
}*/

int			rotation_x(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_ray		rotated_r;
	float		sin_theta;
	float		cos_theta;
	t_vector	p;
	t_vector	normal;

	sin_theta = sin(object->rot_x);
	cos_theta = cos(object->rot_x);
	rotated_r.ori.x = ray->ori.x;
	rotated_r.ori.y = cos_theta * ray->ori.y + sin_theta * ray->ori.z;
	rotated_r.ori.z = -sin_theta * ray->ori.y + cos_theta * ray->ori.z;
	rotated_r.dir.x = ray->dir.x;
	rotated_r.dir.y = cos_theta * ray->dir.y + sin_theta * ray->dir.z;
	rotated_r.dir.z = -sin_theta * ray->dir.y + cos_theta * ray->dir.z;
	if (rotation_y(object, &rotated_r, rec, closest))
	{
		p = rec->p;
		normal = rec->normal;
		rec->p.y = cos_theta * p.y - sin_theta * p.z;
		rec->p.z = sin_theta * p.y + cos_theta * p.z;
		rec->normal.y = cos_theta * normal.y - sin_theta * normal.z;
		rec->normal.z = sin_theta * normal.y + cos_theta * normal.z;
		return (1);
	}
	return (0);
}

int			rotation_y(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_ray		rotated_r;
	float		sin_theta;
	float		cos_theta;
	t_vector	p;
	t_vector	normal;

	sin_theta = sin(object->rot_y);
	cos_theta = cos(object->rot_y);
	rotated_r.ori.x = cos_theta * ray->ori.x - sin_theta * ray->ori.z;
	rotated_r.ori.y = ray->ori.y;
	rotated_r.ori.z = sin_theta * ray->ori.x + cos_theta * ray->ori.z;
	rotated_r.dir.x = cos_theta * ray->dir.x - sin_theta * ray->dir.z;
	rotated_r.dir.y = ray->dir.y;
	rotated_r.dir.z = sin_theta * ray->dir.x + cos_theta * ray->dir.z;
	if (rotation_z(object, &rotated_r, rec, closest))
	{
		p = rec->p;
		normal = rec->normal;
		rec->p.x = cos_theta * p.x + sin_theta * p.z;
		rec->p.z = -sin_theta * p.x + cos_theta * p.z;
		rec->normal.x = cos_theta * normal.x + sin_theta * normal.z;
		rec->normal.z = -sin_theta * normal.x + cos_theta * normal.z;
		return (1);
	}
	return (0);
}

int			rotation_z(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_ray		rotated_r;
	float		sin_theta;
	float		cos_theta;
	t_vector	p;
	t_vector	normal;

	sin_theta = sin(object->rot_z);
	cos_theta = cos(object->rot_z);
	rotated_r.ori.x = cos_theta * ray->ori.x + sin_theta * ray->ori.y;
	rotated_r.ori.y = -sin_theta * ray->ori.x + cos_theta * ray->ori.y;
	rotated_r.ori.z = ray->ori.z;
	rotated_r.dir.x = cos_theta * ray->dir.x + sin_theta * ray->dir.y;
	rotated_r.dir.y = -sin_theta * ray->dir.x + cos_theta * ray->dir.y;
	rotated_r.dir.z = ray->dir.z;
	if (object_hit(object, &rotated_r, rec, closest))
	{
		p = rec->p;
		normal = rec->normal;
		rec->p.x = cos_theta * p.x - sin_theta * p.y;
		rec->p.y = sin_theta * p.x + cos_theta * p.y;
		rec->normal.x = cos_theta * normal.x - sin_theta * normal.y;
		rec->normal.y = sin_theta * normal.x + cos_theta * normal.y;
		return (1);
	}
	return (0);
}

int decoupage(t_object *object, t_ray r, t_hit_rec *rec, float closest,float temp0,float temp1,char axe)
{
	float niv_coup;
	niv_coup = -0.7;
	float axe0;
	float axe1;
	axe0 = 0;
	axe1 = 0;
	if(axe == 'x')
	{
		axe0 = r.ori.x + temp0 * r.dir.x;
		axe1 = r.ori.x + temp1 * r.dir.x;
	}
	if(axe == 'y')
	{
		axe0 = r.ori.y + temp0 * r.dir.y;
		axe1 = r.ori.y + temp1 * r.dir.y;
	}
	if(axe == 'z')
	{
		axe0 = r.ori.z + temp0 * r.dir.z;
		axe1 = r.ori.z + temp1 * r.dir.z;
	}
	if(axe != 'x' && axe != 'y' && axe != 'z')
	{
		axe0 = 0;
		axe1 = 0;
	}
	if (axe0 < niv_coup)
	{
		if(axe1 <niv_coup)
			return (0);
		else
		{
			float th = temp0 + (temp1 - temp0) * (axe0 + 1) / (axe0-axe1);
			if(th <= 0)
				return (0);
			if(th < closest && th > MIN_CLOSEST)
			{
				rec->t = th;
				point_at(&r, th, &rec->p);
				rec->normal.x = 0;
				rec->normal.y = -1;
				rec->normal.z = 0;
				return (1);
			}
		}
	}
	else if(axe0 >= -object->radius && axe0 <= object->radius)
	{
		if(temp0 <= 0)
			return (0);
		if(temp0 < closest && temp0 > MIN_CLOSEST)
		{
			rec->t = temp0;
			point_at(&r, temp0, &rec->p);
			rec->normal.x = (rec->p.x)/object->radius;
			rec->normal.y = 0;
			rec->normal.z = (rec->p.z)/object->radius;
			return (1);
		}
	}
	else if (axe0 > object->radius)
	{
		if(axe1 > object->radius)
			return 0;
		else
		{
			float th = temp0 + (temp1-temp0) * (axe0 - 1) / (axe0-axe1);
			if(th <= 0)
				return(0);
			if(th < closest && th > MIN_CLOSEST)
			{
				rec->t = th;
				point_at(&r, th, &rec->p);
				rec->normal.x = 0;
				rec->normal.y = 1;
				rec->normal.z = 0;
				return (1);
			}
		}
	}
	return (0);
}