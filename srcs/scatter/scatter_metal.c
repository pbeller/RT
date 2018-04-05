#include "scatter.h"

int			scatter_metal(const t_ray *ray, t_hit_rec *rec, t_vector *attenuation, t_ray *scatter)
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