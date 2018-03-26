#include "light.h"

void				lights_del(t_lst *lights)
{
	twl_lst_del(lights, light_del);
}
