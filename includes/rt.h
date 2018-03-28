#ifndef WOLF3D_H
# define WOLF3D_H
# include "vector.h"
# include <math.h>
# include "../minilibx/includes/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "camera.h"
# include "object.h"
# include "env.h"
# include <float.h>

# define WIN_WIDTH 900
# define WIN_HEIGH 450
# define AA_STRENGH 4

typedef struct	s_img
{
	void		*ptr;
	int			*buffer;
	int			bpp;
	int			line_s;
	int			endian;
	void		*win;
	void		*mlx;
} 				t_img;

typedef struct s_ray
{
	t_vector	ori;
	t_vector	dir;
}			t_ray;

typedef struct s_hit_rec
{
	float		t;
	t_vector	p;
	t_vector	normal;
	t_object	*obj_ptr;
}				t_hit_rec;

void		render(t_env *env);
void		destroy(t_img *img);
int			clean_quit(void *parram);
void		put_pixel(t_img *img, int x, int y, t_vector *col);

void		point_at(const t_ray *ray, float t, t_vector *tmp);
void		get_ray(t_ray *ray, t_camera *camera, int i, int j);

#endif
