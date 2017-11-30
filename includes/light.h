#ifndef __LIGHT_H__
# define __LIGHT_H__

#include "twl_lst.h"
#include "twl_dict.h"


typedef				struct s_light
{
	float			pos_x;
	float			pos_y;
	float			pos_z;
	float			intensity;
	float			red;
	float			green;
	float			blue;
}					t_light;

t_light				*light_new();
void				light_del(t_light *light);
void				lights_del(t_lst *light);


void				build_light_from_dict(t_light *light, t_dict *dict);
void 				add_light_to_list_from_dict(t_lst *lst, t_dict *dict);


void				lights_print(t_lst *lights);
void				light_print(t_light *light);
#endif
