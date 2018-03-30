
#include "env.h"
#include "xopt.h"

int 				main(int ac, char **av)
{
	t_env			*env;

	xopt_init(xopt_singleton(), av);
	env = env_new();
	env_print(env);

	/* INSERT YOUR CODE HERE */

	env_del(env);
	xopt_del(xopt_singleton());
	return (0);
	(void)ac;

}
