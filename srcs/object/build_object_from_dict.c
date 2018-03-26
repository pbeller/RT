#include "object.h"
#include <stdlib.h>
#include "twl_dict.h"

void				build_object_from_dict(t_object *object, t_dict *dict)
{
	char			*ret_val;

	ret_val = twl_dict_get(dict, "type");
	object->type = twl_strdup(ret_val);
	ret_val = twl_dict_get(dict, "red");
	object->red = atoi(ret_val);
	ret_val = twl_dict_get(dict, "green");
	object->green = atoi(ret_val);
	ret_val = twl_dict_get(dict, "blue");
	object->blue = atoi(ret_val);
	ret_val = twl_dict_get(dict, "pos_x");
	object->pos_x = atof(ret_val);
	ret_val = twl_dict_get(dict, "pos_y");
	object->pos_y = atof(ret_val);
	ret_val = twl_dict_get(dict, "pos_z");
	object->pos_z = atof(ret_val);
	ret_val = twl_dict_get(dict, "rot_x");
	object->rot_x = atof(ret_val);
	ret_val = twl_dict_get(dict, "rot_y");
	object->rot_y = atof(ret_val);
	ret_val = twl_dict_get(dict, "rot_z");
	object->rot_z = atof(ret_val);
	ret_val = twl_dict_get(dict, "radius");
	object->radius = atof(ret_val);
	ret_val = twl_dict_get(dict, "ambient");
	object->ambient = atof(ret_val);
	ret_val = twl_dict_get(dict, "diffuse");
	object->diffuse = atof(ret_val);
	ret_val = twl_dict_get(dict, "specular");
	object->specular = atof(ret_val);
	ret_val = twl_dict_get(dict, "reflection");
	object->reflection = atof(ret_val);
	ret_val = twl_dict_get(dict, "refraction");
	object->refraction = atof(ret_val);
}
