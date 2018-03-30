#ifndef __UTILS_H__
# define __UTILS_H__

# include "twl_dict.h"
# include "xopt.h"
# include "twl_stdio.h"
# include "twl_xstdio.h"


void				*dict_get_with_default(t_dict *dict, char *key, void *def);
char 				*read_raw_input();

#endif
