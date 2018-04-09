#ifndef RT_H
# define RT_H
# include "vector.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "camera.h"
# include "object.h"
# include "env.h"
# include <float.h>
# include <pthread.h>
# include "image.h"

# define WIN_WIDTH 900
# define WIN_HEIGH 450
# define AA_STRENGH 4
# define RAY_DEPTH 10

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

typedef struct	s_thread_arg
{
	int				j;
	t_img			*img;
	t_env			*env;
	t_ray			*ray;
    pthread_mutex_t mutex;
} 				t_thread_arg;

void	render(t_env *env);

int		scatter(const t_ray *ray, t_hit_rec *rec, t_ray *scatter);
int		hit(t_env *env, const t_ray *ray, t_hit_rec *rec);
void	init_camera(t_camera *cam, float aspect);
#endif
