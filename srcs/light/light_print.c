#include "light.h"

#include <stdio.h>

void				light_print(t_light *light)
{
	printf("===== Light Print =====\n");
	printf("pos_x: %f\n", light->pos_x);
	printf("pos_y: %f\n", light->pos_y);
	printf("pos_z: %f\n", light->pos_z);
	printf("intensity: %f\n", light->intensity);
	printf("red: %f\n", light->red);
	printf("green: %f\n", light->green);
	printf("blue: %f\n", light->blue);
}
