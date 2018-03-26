#include "light.h"
#include <stdlib.h>

void				light_del(t_light *light)
{
	free(light);
}
