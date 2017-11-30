#ifndef __CAMERA_H_
# define __CAMERA_H_

# include "twl_dict.h"

typedef struct  s_camera
{
	float 			pos_x;
	float 			pos_y;
	float 			pos_z;
	float 			dir_x;
	float 			dir_y;
	float 			dir_z;
}					t_camera;

t_camera			*camera_new();
void				camera_del(t_camera *camera);

void				build_camera_from_dict(t_camera *camera, t_dict *dict);
void				camera_print(t_camera *camera);

#endif
