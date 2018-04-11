#include "shape.h"

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
	r.dir.z = sin(angle)*ray->dir.y + cos(angle)* ray->dir.z;// presque bon apart pi/2*/
	return (r);
}

t_ray rotation_y(t_object *object, t_ray *ray)
{
	t_ray		r;
	float angle;

	angle = object->rot_y * M_PI / 180 ;
	r.ori.x = cos(angle) * ray->ori.x + sin(angle) * ray->ori.z;
	r.ori.y = ray->ori.y;
	r.ori.z = -sin(angle) * ray->ori.x + cos(angle)* ray->ori.z;
	r.dir.x = cos(angle) * ray->dir.x + sin(angle) * ray->dir.z;
	r.dir.z = -sin(angle) * ray->dir.x + cos(angle)* ray->dir.z;
	r.dir.y = ray->dir.y; //autour de y non ok
	return (r);
}

t_ray rotation_z(t_object *object, t_ray *ray)
{
	t_ray		r;
	float angle;

	angle = object->rot_z * M_PI / 180;
	r.ori.x = cos(angle) * ray->ori.x - sin(angle) * ray->ori.y;
	r.ori.y = sin(angle)*ray->ori.x + cos(angle)* ray->ori.y;
	r.ori.z = ray->ori.z;
	r.dir.x = cos(angle) * ray->dir.x - sin(angle) * ray->dir.y;
	r.dir.y = sin(angle)*ray->dir.x + cos(angle)* ray->dir.y;
	r.dir.z = ray->dir.z; //autou de z ok
	return (r);
}

t_ray homothetie(t_ray *ray,float scx, float scy, float scz)
{
	t_ray r;
	r.ori.x = ray->ori.x * scx;
	r.ori.y = ray->ori.y * scy;
	r.ori.z = ray->ori.x * scz;
	r.dir.x = ray->dir.x * scx;
	r.dir.y = ray->dir.y * scy;
	r.dir.z = ray->dir.z * scz;
	return (r);
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
		axe0 = r.ori.x + temp0 * r.dir.x - object->pos_x;
		axe1 = r.ori.x + temp1 * r.dir.x -  object->pos_x;
	}
	if(axe == 'y')
	{
		axe0 = r.ori.y + temp0 * r.dir.y - object->pos_y;
		axe1 = r.ori.y + temp1 * r.dir.y -  object->pos_y;
	}
	if(axe == 'z')
	{
		axe0 = r.ori.z + temp0 * r.dir.z - object->pos_z;
		axe1 = r.ori.z + temp1 * r.dir.z -  object->pos_z;
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
			if(th < closest && th > 0.001)
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
		if(temp0 < closest && temp0 > 0.001)
		{
			rec->t = temp0;
			point_at(&r, temp0, &rec->p);
			rec->normal.x = (rec->p.x - object->pos_x)/object->radius;
			rec->normal.y = 0;
			rec->normal.z = (rec->p.z - object->pos_z)/object->radius;
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
			if(th < closest && th > 0.001)
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