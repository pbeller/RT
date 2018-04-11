#ifndef TRANSFORMATION_H
# define TRANSFORMATION_H

#include "rt.h"

t_ray rotation_x(t_object *object, t_ray *ray);
t_ray rotation_y(t_object *object, t_ray *ray);
t_ray rotation_z(t_object *object, t_ray *ray);


#endif