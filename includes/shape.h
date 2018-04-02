#ifndef SHAPE_H
# define SHAPE_H
# include "rt.h"

int			sphere_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
void		point_at(const t_ray *ray, float t, t_vector *tmp);
#endif
