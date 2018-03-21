#include "light.h"
#include "utils.h"
#include <stdlib.h>

void				build_light_from_dict(t_light *light, t_dict *dict)
{
	char			*ret_val;

	ret_val = dict_get_with_default(dict, "pos_x", "0");
	light->pos_x = atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos_y", "0");
	light->pos_y = atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos_z", "0");
	light->pos_z = atof(ret_val);
	ret_val = dict_get_with_default(dict, "intensity", "0");
	light->intensity = atof(ret_val);
	ret_val = dict_get_with_default(dict, "red", "0");
	light->red = atof(ret_val);
	ret_val = dict_get_with_default(dict, "green", "0");
	light->green = atof(ret_val);
	ret_val = dict_get_with_default(dict, "blue", "0");
	light->blue = atof(ret_val);
}
