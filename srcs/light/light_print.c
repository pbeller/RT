#include "light.h"

#include <stdio.h>

void				light_print(t_light *light)
{
	printf("===== Light Print =====\n");
	printf("pos.x: %f\n", light->pos.x);
	printf("pos.y: %f\n", light->pos.y);
	printf("pos.z: %f\n", light->pos.z);
	printf("intensity: %f\n", light->intensity);
	printf("red: %f\n", light->red);
	printf("green: %f\n", light->green);
	printf("blue: %f\n", light->blue);
}
