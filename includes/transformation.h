#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H

#include "rt.h"

t_ray	rotation_x(t_object *object, t_ray *ray);
t_ray	rotation_y(t_object *object, t_ray *ray);
t_ray	rotation_z(t_object *object, t_ray *ray);
int		 decoupage(t_object *object, t_ray r, t_hit_rec *rec, float closest,float temp0,float temp1,char axe);


#endif