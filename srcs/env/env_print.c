#include "env.h"

void 				env_print(t_env *env)
{
	camera_print(env->camera);
	lights_print(env->lights);
	objects_print(env->objects);
}
