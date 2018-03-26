#include "light.h"


static void			print_fn(void *elem)
{
	light_print((t_light *)elem);
}


void				lights_print(t_lst *lights)
{
	twl_lst_iter0(lights, print_fn);
}
