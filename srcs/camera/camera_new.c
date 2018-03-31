#include "camera.h"
#include "twl_xstdlib.h"

t_camera			*camera_new()
{
	t_camera		*camera;

	camera = twl_malloc_x0(sizeof(t_camera));
	camera->pos_x = 0.0;
	camera->pos_y = 0.0;
	camera->pos_z = 0.0;
	camera->dir_x = 0.0;
	camera->dir_y = 0.0;
	camera->dir_z = 0.0;
	camera->fov = 0.0;
	camera->up_x = 0.0;
	camera->up_y = 0.0;
	camera->up_z = 0.0;
	return (camera);
}
