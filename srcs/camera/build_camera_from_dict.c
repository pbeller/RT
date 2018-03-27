#include "camera.h"
#include <stdlib.h>
#include "twl_stdio.h"

void				build_camera_from_dict(t_camera *camera, t_dict *dict)
{
	char 			*ret_val;

	ret_val = twl_dict_get(dict, "pos_x");
	camera->pos_x = atof(ret_val);
	ret_val = twl_dict_get(dict, "pos_y");
	camera->pos_y = atof(ret_val);
	ret_val = twl_dict_get(dict, "pos_z");
	camera->pos_z = atof(ret_val);
	ret_val = twl_dict_get(dict, "dir_x");
	camera->dir_x = atof(ret_val);
	ret_val = twl_dict_get(dict, "dir_y");
	camera->dir_y = atof(ret_val);
	ret_val = twl_dict_get(dict, "dir_z");
	camera->dir_z = atof(ret_val);
	ret_val = twl_dict_get(dict, "fov");
	camera->fov = atof(ret_val);
	ret_val = twl_dict_get(dict, "up_x");
	camera->up_x = atof(ret_val);
	ret_val = twl_dict_get(dict, "up_y");
	camera->up_y = atof(ret_val);
	ret_val = twl_dict_get(dict, "up_z");
	camera->up_z = atof(ret_val);
}
