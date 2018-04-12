#include "shape.h"

int		cylindre_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_vector	oc;
	float		a;
	float		b;
	float		c;
	float		temp1;
	float		temp0;
	float		discrim;
	t_ray		r;

	r = *ray;
	r.ori.x -= object->pos_x;
	r.ori.y -= object->pos_y;
	r.ori.z -= object->pos_z;
	r = rotation_x(object, &r);
	r = rotation_y(object, &r);
	r = rotation_z(object, &r);
	r.ori.x += object->pos_x;
	r.ori.y += object->pos_y;
	r.ori.z += object->pos_z;
	oc.x = r.ori.x - object->pos_x;
	oc.y = 0;
	oc.z = r.ori.z - object->pos_z;
	a = r.dir.x * r.dir.x + r.dir.z * r.dir.z;
	b = (oc.x * r.dir.x + oc.z * r.dir.z);
	c = (oc.x * oc.x + oc.y * oc.y +  oc.z * oc.z) - object->radius * object->radius;
	discrim = b*b - a*c;
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
	return (decoupage(object,r,rec,closest,temp0,temp1,'y'));
}