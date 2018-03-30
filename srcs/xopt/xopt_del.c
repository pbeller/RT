#include "xopt.h"

void				xopt_del(t_xopt *xopt)
{
	free(xopt->file_argument);
	free(xopt);
}
