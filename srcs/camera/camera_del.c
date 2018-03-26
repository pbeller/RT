#include "camera.h"
#include <stdlib.h>

void 				camera_del(t_camera *camera)
{
	free(camera);
}
