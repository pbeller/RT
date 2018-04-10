#include "scatter.h"

static int		refract(const t_vector *v, t_vector *n, float ni_over_nt, t_vector *refracted)
{
	t_vector		uv;
	float			dt;
	float			discr;

	uv = normalise(*v);
	dt = scal_prod(&uv, n);
	discr = 1.0 - ni_over_nt * ni_over_nt * (1.0 - (dt * dt));
	if (discr > 0)
	{
		refracted->x = ni_over_nt * (uv.x - (n->x * dt)) - n->x * sqrt(discr);
		refracted->y = ni_over_nt * (uv.y - (n->y * dt)) - n->y * sqrt(discr);
		refracted->z = ni_over_nt * (uv.z - (n->z * dt)) - n->z * sqrt(discr);
		return (1);
	}
	else
	{
		refracted->x = 0;
		refracted->y = 0;
		refracted->z = 0;
		return (0);
	}
}

static float	schlick(float cosine, float ref_idx)
{
	float	r0;

	r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0 * r0;
	return (r0 + (1 - r0) * pow((1 - cosine), 5));
}

int				scatter_dielectric(const t_ray *ray, t_hit_rec *rec, t_ray *scatter)
{
	t_vector	outward_normal;
	t_vector	reflected;
	float		ni_over_nt;
	t_vector	refracted;
	float		reflect_prob;
	float		cosine;
	t_vector		rand_unit_vect;

	rand_unit_vect = random_in_unit_sphere();
	reflected = reflect(ray->dir, &rec->normal);
	if (scal_prod(&ray->dir, &rec->normal) > 0)
	{
		outward_normal.x = -rec->normal.x;
		outward_normal.y = -rec->normal.y;
		outward_normal.z = -rec->normal.z;
		ni_over_nt = rec->obj_ptr->refraction;
		cosine = ni_over_nt * scal_prod(&ray->dir, &rec->normal) / norm(&ray->dir);
	}
	else
	{
		outward_normal.x = rec->normal.x;
		outward_normal.y = rec->normal.y;
		outward_normal.z = rec->normal.z;
		ni_over_nt = 1.0 / rec->obj_ptr->refraction;
		cosine = -scal_prod(&ray->dir, &rec->normal) / norm(&ray->dir);

	}
	if (refract(&ray->dir, &outward_normal, ni_over_nt, &refracted))
		reflect_prob = schlick(cosine, rec->obj_ptr->refraction);
	else
		reflect_prob = 1.0;
	if (drand48() < reflect_prob)
	{
		scatter->ori.x = rec->p.x;
		scatter->ori.y = rec->p.y;
		scatter->ori.z = rec->p.z;
		scatter->dir.x = reflected.x + (1 - rec->obj_ptr->reflection) * rand_unit_vect.x;
		scatter->dir.y = reflected.y + (1 - rec->obj_ptr->reflection) * rand_unit_vect.y;
		scatter->dir.z = reflected.z + (1 - rec->obj_ptr->reflection) * rand_unit_vect.z;
	}
	else
	{
		scatter->ori.x = rec->p.x;
		scatter->ori.y = rec->p.y;
		scatter->ori.z = rec->p.z;
		scatter->dir.x = refracted.x + (1 - rec->obj_ptr->transparence) * rand_unit_vect.x;
		scatter->dir.y = refracted.y + (1 - rec->obj_ptr->transparence) * rand_unit_vect.y;
		scatter->dir.z = refracted.z + (1 - rec->obj_ptr->transparence) * rand_unit_vect.z;
	}
	return (1);
}