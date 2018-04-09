#ifndef TEXTURE_H
# define TEXTURE_H

#include "rt.h"

t_vector	get_texture(const t_hit_rec *rec, t_vector ret);
t_vector	get_constant_texture(const t_hit_rec *rec, t_vector ret);
t_vector	get_xpm_texture(const t_hit_rec *rec, t_vector ret);
void		set_texture(const t_env *env, t_img *img);

#endif