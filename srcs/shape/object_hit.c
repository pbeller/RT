#include "shape.h"

void		point_at(const t_ray *ray, float t, t_vector *tmp)
{
	tmp->x = ray->dir.x * t;
	tmp->y = ray->dir.y * t;
	tmp->z = ray->dir.z * t;

	tmp->x = tmp->x + ray->ori.x;
	tmp->y = tmp->y + ray->ori.y;
	tmp->z = tmp->z + ray->ori.z;
}

static int	object_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	if (twl_strcmp(object->type, "sphere") == 0)
		return (sphere_hit(object, ray, rec, closest));
	if(twl_strcmp(object->type, "cylindre") == 0)
		return (cylindre_hit(object,ray,rec,closest));
	if(twl_strcmp(object->type, "tube") == 0)
		return (tube_hit(object,ray,rec,closest));
	if(twl_strcmp(object->type, "cube") == 0)
		return (cube_hit(object,ray,rec,closest));
	if(twl_strcmp(object->type, "x_rectangle") == 0)
		return (yz_rectangle_hit(object,ray,rec,closest));
	if(twl_strcmp(object->type, "y_rectangle") == 0)
		return (xz_rectangle_hit(object,ray,rec,closest));
	if(twl_strcmp(object->type, "z_rectangle") == 0)
		return (xy_rectangle_hit(object,ray,rec,closest));
	return(0);
}

int			translate(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_ray	moved_r;

	moved_r.ori.x = ray->ori.x - object->pos_x;
	moved_r.ori.y = ray->ori.y - object->pos_y;
	moved_r.ori.z = ray->ori.z - object->pos_z;
	moved_r.dir.x = ray->dir.x;
	moved_r.dir.y = ray->dir.y;
	moved_r.dir.z = ray->dir.z;
	if (object_hit(object, &moved_r, rec, closest))
	{
		rec->p.x += object->pos_x;
		rec->p.y += object->pos_y;
		rec->p.z += object->pos_z;
		return (1);
	}
	return (0);
}

int			hit(t_env *env, const t_ray *ray, t_hit_rec *rec)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;
	int				hit;
	float			closest;

	hit = 0;
	closest = FLT_MAX;
	elem = env->objects->head;
	while (elem)
	{
		next = elem->next;
		if (translate(elem->data, ray, rec, closest))
		{
			hit = 1;
			closest = rec->t;
			rec->obj_ptr = elem->data;
		}
		elem = next;
	}
	return (hit);
}
