#include "object.h"
#include "twl_xstdlib.h"

t_object			*object_new()
{
	t_object		*object;

	object = twl_malloc_x0(sizeof(t_object));
	object->red = 0;
	object->green = 0;
	object->blue = 0;
	object->pos_x = 0.0;
	object->pos_y = 0.0;
	object->pos_z = 0.0;
	object->rot_x = 0.0;
	object->rot_y = 0.0;
	object->rot_z = 0.0;
	object->ambient = 0.0;
	object->diffuse = 0.0;
	object->specular = 0.0;
	object->reflection = 0.0;
	object->refraction = 0.0;
	return (object);
}
