#include <stdlib.h>
#include <math.h>
#include "rt.h"

void				quit(t_env *env)
{
	mlx_destroy_window(env->mlx->ptr, env->mlx->win);
	exit(0);
}

int					key_hook(int k, t_env *env)
{
	if (k == 53)
		quit(env);
	return (0);
}

int					main()
{
	t_env			*env;

	env = env_init();
	render(env);
	mlx_key_hook(env->mlx->win, key_hook, env);
	mlx_loop(env->mlx->ptr);
	return (0);
}