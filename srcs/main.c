
#include "env.h"
#include "parser.h"
#include "xopt.h"

int 				main(int ac, char **av)
{
	t_env			*env;

	xopt_init(xopt_singleton(), av);
	env = env_new();
	if (ac > 1)
		fill_env_with_file_path(env, av[1]);
	env_print(env);
	env_del(env);
	xopt_del(xopt_singleton());
	return (0);

}
