#include <stdlib.h>
#include "rt.h"

void				add_light()
{
	t_light			*light;

	light = (t_light *)malloc(sizeof(t_light));
	light->pos.x = 5;
	light->pos.y = 5;
	light->pos.z = -2;
	light->color = 0x000000FF;
}