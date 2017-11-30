#include "light.h"

void				add_light_to_list_from_dict(t_lst *lights, t_dict *light)
{
	t_light			*new_light;

	new_light = light_new();
	build_light_from_dict(new_light, light);
	twl_lst_push_back(lights, new_light);
}
