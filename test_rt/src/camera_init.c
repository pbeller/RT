#include "rt.h"

void				cam_init(t_env *env)
{
	env->cam.pos.x = 0;
	env->cam.pos.y = 0;
	env->cam.pos.z = 0;
	env->cam.dir.x = 0;
	env->cam.dir.y = 0;
	env->cam.dir.z = -1;
}