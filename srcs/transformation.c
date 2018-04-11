#include "transformation.h"

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