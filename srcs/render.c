#include "rt.h"
#include "texture.h"

static t_vector	background_color(int is_sky, const t_ray *prim_ray)
{
	t_vector	color;
	float		t;

	if (is_sky)
	{
		t = 0.5 * (normalise(prim_ray->dir).y + 1.0);
		color.x = (1.0 - t) + t * 0.5;
		color.y = (1.0 - t) + t * 0.7;
		color.z = (1.0 - t) + t * 1.0;
	}
	else
		color = new_vector(0,0,0);
	return (color);
}

t_vector		get_color(t_env *env, const t_ray *prim_ray, int depth)
{
	t_hit_rec		rec;
	t_ray			sec_ray;
	t_vector		emited;

	if (hit(env, prim_ray, &rec))
	{
		if (rec.obj_ptr->diffuse > 0)
		{
			emited.x = rec.obj_ptr->diffuse * rec.obj_ptr->red;
			emited.y = rec.obj_ptr->diffuse * rec.obj_ptr->green;
			emited.z = rec.obj_ptr->diffuse * rec.obj_ptr->blue;
		}
		else
			emited = new_vector(0,0,0);
		if (depth < RAY_DEPTH && scatter(prim_ray, &rec, &sec_ray))
			return (get_texture(&rec, get_color(env, &sec_ray, depth + 1)));
		else
			return (emited);
	}
	else
		return (background_color(SKY_BACKGROUND, prim_ray));
}

static void		get_ray(t_ray *ray, t_camera *cam, int i, int j)
{
	float	u;
	float	v;

	u = (float)(i + drand48()) / (float)WIN_WIDTH;
	v = (float)(j + drand48()) / (float)WIN_HEIGH;
	ray->dir.x = cam->up_left.x + u * cam->hori.x - v * cam->vert.x - cam->pos_x;
	ray->dir.y = cam->up_left.y + u * cam->hori.y - v * cam->vert.y - cam->pos_y;
	ray->dir.z = cam->up_left.z + u * cam->hori.z - v * cam->vert.z - cam->pos_z;
}

void			*thread_fnc(void *data)
{
	int 			i;
	int				k;
	t_vector		col;
	t_thread_arg *thread_arg;
	int				j;
	t_ray			ray;
	t_vector		test;

	thread_arg = (t_thread_arg*)data;
	pthread_mutex_lock(&thread_arg->mutex);
	j = thread_arg->j;
	thread_arg->j += 1;
	ray = *thread_arg->ray;
	pthread_mutex_unlock(&thread_arg->mutex);
	i = -1;
	while (++i < WIN_WIDTH)
	{
		k = -1;
		set_value_vector(&col, 0, 0, 0);
		while (++k < AA_STRENGH)
		{
			get_ray(&ray, thread_arg->env->camera, i, j);
			test = get_color(thread_arg->env, &ray, 0);
			col = add_vector(col, test);
		}
		put_pixel(thread_arg->img, i, j, &col);
	}
    pthread_exit(NULL);
}

void			draw_img(t_img *img, t_env *env)
{
	t_ray			ray;
	t_thread_arg	thread_arg;
	pthread_t		*thread;
	int				i;
	int				j;

	(!(thread = (pthread_t*)malloc(sizeof(pthread_t) * WIN_HEIGH)))
														? exit(-1) : 0;
	thread_arg.ray = &ray;
	thread_arg.env = env;
	thread_arg.img = img;
	init_camera(env->camera, (float)WIN_WIDTH / (float)WIN_HEIGH);
	ray.ori.x = env->camera->pos_x;
	ray.ori.y = env->camera->pos_y;
	ray.ori.z = env->camera->pos_z;
	thread_arg.j = 0;
	j = -1;
    pthread_mutex_init (&thread_arg.mutex, NULL);
	while (++j < WIN_HEIGH)
		(pthread_create(&thread[j], NULL, thread_fnc, &thread_arg) != 0)
															? exit(3) : 0;
	i =-1;
	while (++i < WIN_HEIGH)
		pthread_join(thread[i], NULL);
	free(thread);
}