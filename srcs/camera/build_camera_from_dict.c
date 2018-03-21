#include "camera.h"
#include "utils.h"
#include <stdlib.h>
#include "twl_stdio.h"

void				build_camera_from_dict(t_camera *camera, t_dict *dict)
{
	char 			*ret_val;

	ret_val = dict_get_with_default(dict, "pos_x", "0");
	camera->pos_x = atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos_y", "0");
	camera->pos_y = atof(ret_val);
	ret_val = dict_get_with_default(dict, "pos_z", "0");
	camera->pos_z = atof(ret_val);
	ret_val = dict_get_with_default(dict, "dir_x", "0");
	camera->dir_x = atof(ret_val);
	ret_val = dict_get_with_default(dict, "dir_y", "0");
	camera->dir_y = atof(ret_val);
	ret_val = dict_get_with_default(dict, "dir_z", "0");
	camera->dir_z = atof(ret_val);
}
