#include <stdlib.h>
#include "rt.h"

t_env				*env_init()
{
	t_env			*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->mlx = new_mlx();
	cam_init(env);
	add_sphere(env);
	add_light();
	return (env);
}