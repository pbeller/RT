#ifndef __ENV_H__
# define __ENV_H__
# include "camera.h"
# include "light.h"
# include "object.h"
# include "twl_arr.h"
# include "twl_lst.h"
# include "utils.h"

# define VALIDE_TYPE "camera,light,plane,sphere,cylindre"

typedef struct  s_env
{
	t_camera		*camera;
	t_lst			*lights;
	t_lst			*objects;

}					t_env;

t_env				*env_new();
void				env_fill(t_env *env);
void				env_del(t_env *env);

void				env_print(t_env *env);


#endif
