#ifndef SHAPE_H
# define SHAPE_H
# include "rt.h"

int			sphere_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
void		point_at(const t_ray *ray, float t, t_vector *tmp);
int			cylindre_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			tube_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			sphere_coup_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int 		decoupage(t_object *object, t_ray r, t_hit_rec *rec, float closest,float temp0,float temp1,char axe);
t_ray		rotation_x(t_object *object, t_ray *ray);
t_ray		rotation_y(t_object *object, t_ray *ray);
t_ray		rotation_z(t_object *object, t_ray *ray);
int			xy_rectangle_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			yz_rectangle_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			xz_rectangle_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);
int			cube_hit(t_object *object, const t_ray *ray, t_hit_rec *rec, float closest);

#endif
