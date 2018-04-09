#include "scatter.h"


t_vector	reflect(t_vector	dir, t_vector	*normal)
{
	t_vector	ret;
	float		dot;

	dot = scal_prod(&dir, normal);
	ret.x = dir.x - 2 * dot * normal->x;
	ret.y = dir.y - 2 * dot * normal->y;
	ret.z = dir.z - 2 * dot * normal->z;
	return (ret);
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

int			scatter(const t_ray *ray, t_hit_rec *rec, t_ray *scatter)
{
	if (rec->obj_ptr->refraction > 0)
		return (scatter_dielectric(ray, rec, scatter));
	if (rec->obj_ptr->reflection > 0)
		return (scatter_metal(ray, rec, scatter));
	return (scatter_lamberian(rec, scatter));
}