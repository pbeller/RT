#ifndef __OBJECT_H__
# define __OBJECT_H__

#include "twl_dict.h"
#include "twl_lst.h"

typedef struct 		s_object
{
	char			*type;
	int				red;
	int				green;
	int				blue;
	float			pos_x;
	float			pos_y;
	float			pos_z;
	float			rot_x;
	float			rot_y;
	float			rot_z;
	float			radius;
	float			ambient;
	float			diffuse;
	float			specular;
	float			reflection;
	float			refraction;
}					t_object;

t_object			*object_new();
void				object_del(t_object *object);
void				objects_del(t_lst *objects);

void				build_object_from_dict(t_object *object, t_dict *dict);
void 				add_object_to_list_from_dict(t_lst *objects, t_dict *object);


void				objects_print(t_lst *objects);
void				object_print(t_object *object);
#endif
