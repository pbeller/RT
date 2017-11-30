#include "env.h"
#include "twl_xstdlib.h"

t_env				*env_new()
{
	t_env			*env;

	env = twl_malloc_x0(sizeof(t_env));
	env->camera = camera_new();
	env->lights = twl_lst_new();
	env->objects = twl_lst_new();
	return (env);
}
