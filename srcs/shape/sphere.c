#include "shape.h"

static void	get_sphere_u_v(const t_vector *p, float *u, float *v)
{
	float	phi;
	float	theta;

	phi = atan2(p->z, p->x);
	theta = asin(p->y);
	*u = 1 - (phi + M_PI) / (2 * M_PI);
	*v = (theta + M_PI / 2) / (M_PI);
}

static int	get_values(t_object *object, const t_ray *ray, t_hit_rec *rec, float tmp)
{
	rec->t = tmp;
	point_at(ray, tmp, &rec->p);
	rec->normal.x = (rec->p.x) / object->radius;
	rec->normal.y = (rec->p.y) / object->radius;
	rec->normal.z = (rec->p.z) / object->radius;
	get_sphere_u_v(&rec->normal, &rec->u, &rec->v);
	return (1);
}

int		sphere_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_vector	oc;
	float		a;
	float		b;
	float		c;
	float		tmp;
	t_ray		r;

	r = *ray;
	oc.x = r.ori.x;
	oc.y = r.ori.y;
	oc.z = r.ori.z;
	a = scal_prod(&r.dir, &r.dir);
	b = scal_prod(&oc, &r.dir);
	c = scal_prod(&oc, &oc) - (object->radius * object->radius);
	tmp = b*b - a*c;
	if (tmp > 0)
	{
		tmp = (-b - sqrt(b*b - a*c)) / a;
		if (0.001 < tmp && tmp < closest)
			return (get_values(object, &r, rec, tmp));
		tmp = (-b + sqrt(b*b - a*c)) / a;
		if (0.001 < tmp && tmp < closest)
			return (get_values(object, &r, rec, tmp));
	}
	return (0);
}

int		sphere_coup_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
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
	oc.x = r.ori.x;
	oc.y = r.ori.y;
	oc.z = r.ori.z;
	a = scal_prod(&r.dir, &r.dir);
	b = scal_prod(&oc, &r.dir);
	c = scal_prod(&oc, &oc) - (object->radius * object->radius);
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