#ifndef RT_H
# define RT_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGTH 560

typedef struct 		s_vec3f
{
	float			x;
	float			y;
	float			z;
}					t_vec3f;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*data;
	int				color;
	int				size;
	int				endian;
	int				**map;
	int				map_width;
	int				map_heigth;
}					t_mlx;

typedef struct 		s_light
{
	t_vec3f			pos;
	//t_vec3f			*dir;
	int				color;
}					t_light;

typedef struct 		s_object
{
	float			x;
	float			y;
	float			z;
	float			r;
}					t_object;

typedef struct 		s_cam
{
	t_vec3f			pos;
	t_vec3f			dir;
}					t_cam;

typedef struct 		s_env
{
	t_mlx			*mlx;
	t_object		object;
	t_cam			cam;
	t_light			*light;
}					t_env;

float				intersect(t_vec3f *point, t_env *env);
int					point_calc(t_env *env, t_vec3f *upleft, t_vec3f *point, int x, int y);
t_vec3f				*upleft_calc();

void				cam_init(t_env *env);
t_env				*env_init();
t_mlx				*new_mlx();
void				add_sphere(t_env *env);
void				add_light();

void				render(t_env *env);

t_vec3f				*normalise(t_vec3f *a);
#endif