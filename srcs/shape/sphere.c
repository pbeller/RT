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
	rec->normal.x = (rec->p.x - object->pos_x) / object->radius;
	rec->normal.y = (rec->p.y - object->pos_y) / object->radius;
	rec->normal.z = (rec->p.z - object->pos_z) / object->radius;
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
/*	r.ori.x -= object->pos_x;
	r.ori.y -= object->pos_y;
	r.ori.z -= object->pos_z;*/
	r = rotation_x(object, &r);
	r = rotation_y(object, &r);
	r = rotation_z(object, &r);
/*	r.ori.x += object->pos_x;
	r.ori.y += object->pos_y;
	r.ori.z += object->pos_z;*/
//	r = homothetie(&r,1,1,1);
	oc.x = r.ori.x - object->pos_x;
	oc.y = r.ori.y - object->pos_y;
	oc.z = r.ori.z - object->pos_z;
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
	int niv_coup;

	r = *ray;
	niv_coup = 0;
	r = rotation_x(object, &r);
	r = rotation_y(object, &r);
	r = rotation_z(object, &r);
//	r = homothetie(&r,1,2,1);
	oc.x = r.ori.x - object->pos_x;
	oc.y = r.ori.y - object->pos_y;
	oc.z = r.ori.z - object->pos_z;
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
	float y0 = r.ori.y + temp0 * r.dir.y - object->pos_y;
	float y1 = r.ori.y + temp1 * r.dir.y -  object->pos_y;
	if (y0 < niv_coup)
	{
		if(y1 <niv_coup)
			return (0);
		else
		{
			float th = temp0 + (temp1 - temp0) * (y0 + 1) / (y0-y1);
			if(th <= 0)
				return (0);
			if(th < closest && th > 0.001 )
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
	else if(y0 >= -object->radius && y0 <= object->radius)
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
	else if (y0 > object->radius)
	{
		if(y1 > object->radius)
			return 0;
		else
		{
			float th = temp0 + (temp1-temp0) * (y0 - 1) / (y0-y1);
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