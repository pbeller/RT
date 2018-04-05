#include "scatter.h"

int			scatter_lamberian(const t_ray *ray, t_hit_rec *rec, t_vector *attenuation, t_ray *scatter)
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