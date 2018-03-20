
#include "mlx.h"
#include "env.h"
#include "parser.h"

int 				main(int ac, char **av)
{
	t_env			*env;

	env = env_new();
	if (ac > 1)
		fill_env_with_file_path(env, av[1]);
	env_print(env);
	env_del(env);
	return (0);

}
