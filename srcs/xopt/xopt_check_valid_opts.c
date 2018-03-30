#include "xopt.h"

void				xopt_check_valid_opts(t_xopt *xopt)
{
	char			*first_not_valid_opt;

	first_not_valid_opt = twl_opt_check_invalid_opts(xopt->opt__);
	if (first_not_valid_opt)
	{
		twl_xprintf("Invalid Option: %s\n", first_not_valid_opt);
	}
}
