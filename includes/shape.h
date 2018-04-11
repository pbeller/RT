#ifndef SHAPE_H
# define SHAPE_H
# include "rt.h"
# include "transformation.h"

int			sphere_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
void		point_at(const t_ray *ray, float t, t_vector *tmp);
int			cylindre_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			tube_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			sphere_coup_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);

#endif
