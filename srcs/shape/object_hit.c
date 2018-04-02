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
	else
		return (0);
}

int			hit(t_env *env, const t_ray *ray, t_hit_rec *rec)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;
	int				hit;
	float			closest;
	t_hit_rec		tmp_rec;

	hit = 0;
	closest = FLT_MAX;
	elem = env->objects->head;
	while (elem)
	{
		next = elem->next;
		if (object_hit(elem->data, ray, &tmp_rec, closest))
		{
			hit = 1;
			*rec = tmp_rec;
			closest = rec->t;
			rec->obj_ptr = elem->data;
		}
		elem = next;
	}
	return (hit);
}
