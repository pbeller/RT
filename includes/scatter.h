#ifndef SCATTER_H
# define SCATTER_H
# include "rt.h"

int			scatter_dielectric(const t_ray *ray, t_hit_rec *rec, t_ray *scatter);
int			scatter_lamberian(t_hit_rec *rec, t_ray *scatter);
int			scatter_metal(const t_ray *ray, t_hit_rec *rec, t_ray *scatter);
t_vector	reflect(t_vector	dir, t_vector	*normal);
t_vector	random_in_unit_sphere();
#endif
