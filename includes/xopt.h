#ifndef XOPT_H
# define XOPT_H



# include "twl_opt.h"
# include "twl_xstdlib.h"
# include "twl_printf.h"
# include "twl_ctype.h"
# include <stdlib.h>

# include <stdlib.h>
# include <unistd.h>
# include <assert.h>

# include "twl_lst.h"
# include "twl_stdio.h"
# include "twl_xstdio.h"
# include "twl_xstdlib.h"
# include "twl_xstring.h"
# include "twl_color.h"


# define XOPT_VALID_OPTS "h"


typedef struct		s_xopt
{
	t_opt			*opt__;
	char			*file_argument;
}					t_xopt;


t_xopt				*xopt_new(void);
void				xopt_del(t_xopt *xopt);

t_xopt				*xopt_singleton(void);

void				xopt_init(t_xopt *xopt, char **av);
void				xopt_check_valid_opts(t_xopt *xopt);

# endif
