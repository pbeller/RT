#include "object.h"
#include "utils.h"
#include <stdlib.h>
#include "twl_dict.h"

void				build_object_from_dict(t_object *object, t_dict *dict)
{
	char			*ret_val;

	ret_val = dict_get_with_default(dict, "type", "0");
	object->type = twl_strdup(ret_val);
	ret_val = dict_get_with_default(dict, "red", "0");
	object->red = atoi(ret_val);
	ret_val = dict_get_with_default(dict, "green", "0");
	object->green = atoi(ret_val);
	ret_val = dict_get_with_default(dict, "blue", "0");
	object->blue = atoi(ret_val);
	ret_val = dict_get_with_default(dict, "pos_x", "0");
	object->pos_x = atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos_y", "0");
	object->pos_y = atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos_z", "0");
	object->pos_z = atof(ret_val);
	ret_val = dict_get_with_default(dict, "rot_x", "0");
	object->rot_x = atof(ret_val);
	ret_val = dict_get_with_default(dict, "rot_y", "0");
	object->rot_y = atof(ret_val);
	ret_val = dict_get_with_default(dict, "rot_z", "0");
	object->rot_z = atof(ret_val);
	ret_val = dict_get_with_default(dict, "ambient", "0");
	object->ambient = atof(ret_val);
	ret_val = dict_get_with_default(dict, "diffuse", "0");
	object->diffuse = atof(ret_val);
	ret_val = dict_get_with_default(dict, "specular", "0");
	object->specular = atof(ret_val);
	ret_val = dict_get_with_default(dict, "reflection", "0");
	object->reflection = atof(ret_val);
	ret_val = dict_get_with_default(dict, "refraction", "0");
	object->refraction = atof(ret_val);
}
