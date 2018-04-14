#include "shape.h"

int			translate(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest)
{
	t_ray	moved_r;

	moved_r.ori.x = ray->ori.x - object->pos.x;
	moved_r.ori.y = ray->ori.y - object->pos.y;
	moved_r.ori.z = ray->ori.z - object->pos.z;
	moved_r.dir.x = ray->dir.x;
	moved_r.dir.y = ray->dir.y;
	moved_r.dir.z = ray->dir.z;
	if (rotation_x(object, &moved_r, rec, closest))
	{
		rec->p.x += object->pos.x;
		rec->p.y += object->pos.y;
		rec->p.z += object->pos.z;
		return (1);
	}
	return (0);
}
