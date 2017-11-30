#include "object.h"
#include <stdio.h>

void				object_print(t_object *object)
{
	printf("===== Print Object =====\n");
	printf("type: %s\n", object->type);
	printf("red: %d\n", object->red);
	printf("green: %d\n", object->green);
	printf("blue: %d\n", object->blue);
	printf("pos_x: %f\n", object->pos_x);
	printf("pos_y: %f\n", object->pos_y);
	printf("pos_z: %f\n", object->pos_z);
	printf("rot_x: %f\n", object->rot_x);
	printf("rot_y: %f\n", object->rot_y);
	printf("rot_z: %f\n", object->rot_z);
	printf("ambient: %f\n", object->ambient);
	printf("diffuse: %f\n", object->diffuse);
	printf("specular: %f\n", object->specular);
	printf("reflection: %f\n", object->reflection);
	printf("refraction: %f\n", object->refraction);
}
