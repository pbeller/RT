#include "xopt.h"

t_xopt				*xopt_new(void)
{
	t_xopt			*xopt;

	xopt = twl_malloc_x0(sizeof(t_xopt));
	xopt->file_argument = NULL;
	return (xopt);
}
