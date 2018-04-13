#include "shape.h"

int		cube_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_object	tmp_obj;
	float		save_closest;

	save_closest = closest;
	tmp_obj = *object;
	tmp_obj.radius = 0;
	tmp_obj.pos_z = object->pos_z + tmp_obj.size;
	if (xy_rectangle_hit(&tmp_obj, ray, rec, closest))
		closest = rec->t;
	tmp_obj.pos_z = object->pos_z;
	tmp_obj.pos_y = object->pos_y + object->size;
	if (xz_rectangle_hit(&tmp_obj, ray, rec ,closest))
		closest = rec->t;
	tmp_obj.pos_y = object->pos_y;
	tmp_obj.pos_x = object->pos_x + object->size;
	if (yz_rectangle_hit(&tmp_obj, ray, rec ,closest))
		closest = rec->t;
	tmp_obj.radius = 1;
	tmp_obj.pos_x = object->pos_x;
	tmp_obj.pos_z = object->pos_z - object->size;
	if (xy_rectangle_hit(&tmp_obj, ray, rec ,closest))
		closest = rec->t;
	tmp_obj.pos_z = object->pos_z;
	tmp_obj.pos_y = object->pos_y - object->size;
	if (xz_rectangle_hit(&tmp_obj, ray, rec ,closest))
		closest = rec->t;
	tmp_obj.pos_y = object->pos_y;
	tmp_obj.pos_x = object->pos_x - object->size;
	if (yz_rectangle_hit(&tmp_obj, ray, rec ,closest))
		closest = rec->t;
	return (closest != save_closest);
}

int		xy_rectangle_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	float	t;
	float	x;
	float	y;
	float	coord[4];

	t = (object->pos_z - ray->ori.z) / ray->dir.z;
	if (t < MIN_CLOSEST || t > closest)
		return (0);
	x = ray->ori.x + t * ray->dir.x;
	y = ray->ori.y + t * ray->dir.y;
	coord[0] = object->pos_x - object->size;
	coord[1] = object->pos_x + object->size;
	coord[2] = object->pos_y - object->size;
	coord[3] = object->pos_y + object->size;
	if (x < coord[0] || x > coord[1] || y < coord[2] || y > coord[3])
		return (0);
	rec->u = (x - coord[0]) / (coord[1] - coord[0]);
	rec->v = (y - coord[2]) / (coord[3] - coord[2]);
	rec->t = t;
	point_at(ray, t, &rec->p);
	rec->normal = (object->radius > 0) ? new_vector(0, 0, -1) : new_vector(0, 0, 1);
	return (1);
}

int		yz_rectangle_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	float	t;
	float	z;
	float	y;
	float	coord[4];

	t = (object->pos_x - ray->ori.x) / ray->dir.x;
	if (t < MIN_CLOSEST || t > closest)
		return (0);
	z = ray->ori.z + t * ray->dir.z;
	y = ray->ori.y + t * ray->dir.y;
	coord[0] = object->pos_y - object->size;
	coord[1] = object->pos_y + object->size;
	coord[2] = object->pos_z - object->size;
	coord[3] = object->pos_z + object->size;
	if (y < coord[0] || y > coord[1] || z < coord[2] || z > coord[3])
		return (0);
	rec->u = (y - coord[0]) / (coord[1] - coord[0]);
	rec->v = (z - coord[2]) / (coord[3] - coord[2]);
	rec->t = t;
	point_at(ray, t, &rec->p);
	rec->normal = (object->radius > 0) ? new_vector(-1, 0, 0) : new_vector(1, 0, 0);
	return (1);
}

int		xz_rectangle_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	float	t;
	float	x;
	float	z;
	float	coord[4];

	t = (object->pos_y - ray->ori.y) / ray->dir.y;
	if (t < MIN_CLOSEST || t > closest)
		return (0);
	x = ray->ori.x + t * ray->dir.x;
	z = ray->ori.z + t * ray->dir.z;
	coord[0] = object->pos_x - object->size;
	coord[1] = object->pos_x + object->size;
	coord[2] = object->pos_z - object->size;
	coord[3] = object->pos_z + object->size;
	if (x < coord[0] || x > coord[1] || z < coord[2] || z > coord[3])
		return (0);
	rec->u = (x - coord[0]) / (coord[1] - coord[0]);
	rec->v = (z - coord[2]) / (coord[3] - coord[2]);
	rec->t = t;
	point_at(ray, t, &rec->p);
	rec->normal = (object->radius > 0) ? new_vector(0, -1, 0) : new_vector(0, 1, 0);
	return (1);
}
/*
int		cube_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_object	tmp_obj;

	tmp_obj.pos_x = object->pos_x;
	tmp_obj.pos_y = object->pos_y;
	tmp_obj.pos_z = object->pos_z;
	tmp_obj.size = object->size;
	tmp_obj.radius = 0;
	tmp_obj.pos_z = object->pos_z + tmp_obj.size;
	if (xy_rectangle_hit(&tmp_obj, ray, rec, closest) == 1)
		closest = rec->t;
	tmp_obj.pos_z = object->pos_z;
	tmp_obj.pos_y = object->pos_y + object->size;
	if (xz_rectangle_hit(&tmp_obj, ray, rec ,closest) == 1)
		closest = rec->t;
	tmp_obj.pos_y = object->pos_y;
	tmp_obj.pos_x = object->pos_x + object->size;
	if (yz_rectangle_hit(&tmp_obj, ray, rec ,closest) == 1)
		closest = rec->t;
	tmp_obj.radius = 1;
	tmp_obj.pos_x = object->pos_x;
	tmp_obj.pos_z = object->pos_z - object->size;
	if (xy_rectangle_hit(&tmp_obj, ray, rec ,closest) == 1)
		closest = rec->t;
	tmp_obj.pos_z = object->pos_z;
	tmp_obj.pos_y = object->pos_y - object->size;
	if (xz_rectangle_hit(&tmp_obj, ray, rec ,closest) == 1)
		closest = rec->t;
	tmp_obj.pos_y = object->pos_y;
	tmp_obj.pos_x = object->pos_x - object->size;
	if (yz_rectangle_hit(&tmp_obj, ray, rec ,closest) == 1)
		closest = rec->t;
	return (closest == rec->t);
}*/