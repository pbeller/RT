#include "light.h"
#include <stdlib.h>

void				build_light_from_dict(t_light *light, t_dict *dict)
{
	char			*ret_val;

	ret_val = twl_dict_get(dict, "pos_x");
	light->pos_x = atof(ret_val);
	ret_val = twl_dict_get(dict, "pos_y");
	light->pos_y = atof(ret_val);
	ret_val = twl_dict_get(dict, "pos_z");
	light->pos_z = atof(ret_val);
	ret_val = twl_dict_get(dict, "intensity");
	light->intensity = atof(ret_val);
	ret_val = twl_dict_get(dict, "red");
	light->red = atof(ret_val);
	ret_val = twl_dict_get(dict, "green");
	light->green = atof(ret_val);
	ret_val = twl_dict_get(dict, "blue");
	light->blue = atof(ret_val);
}
