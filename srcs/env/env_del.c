#include "env.h"
#include <stdlib.h>

void				env_del(t_env *env)
{
	camera_del(env->camera);
	lights_del(env->lights);
	objects_del(env->objects);
	free(env);
}
