#include "camera.h"
#include "twl_stdio.h"

void				camera_print(t_camera *camera)
{
	twl_printf("====== Camera print ======\n");
	twl_printf("pos_x: %f\n", camera->pos_x);
	twl_printf("pos_y: %f\n", camera->pos_y);
	twl_printf("pos_z: %f\n", camera->pos_z);
	twl_printf("dir_x: %f\n", camera->dir_x);
	twl_printf("dir_y: %f\n", camera->dir_y);
	twl_printf("dir_z: %f\n", camera->dir_z);
	twl_printf("fov  : %f\n", camera->fov);
	twl_printf("up_x : %f\n", camera->up_x);
	twl_printf("up_y : %f\n", camera->up_y);
	twl_printf("up_z : %f\n", camera->up_z);
}
