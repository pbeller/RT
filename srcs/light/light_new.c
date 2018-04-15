#include "light.h"
#include "twl_xstdlib.h"

t_light				*light_new()
{
	t_light			*light;

	light = twl_malloc_x0(sizeof(t_light));
	light->pos.x = 0.0;
	light->pos.y = 0.0;
	light->pos.z = 0.0;
	light->intensity = 0.0;
	light->red = 0.0;
	light->green = 0.0;
	light->blue = 0.0;
	return (light);
}
