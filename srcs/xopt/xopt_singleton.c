#include "xopt.h"

t_xopt				*xopt_singleton(void)
{
	static t_xopt	*xopt = NULL;

	if (!xopt)
		xopt = xopt_new();
	return (xopt);
}
