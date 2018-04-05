#include "rt.h"

t_vector	get_color(t_env *env, const t_ray *prim_ray, int depth)
{
	t_vector		color;
	float			t;
	t_hit_rec		rec;
	t_ray			sec_ray;
	t_vector		att;
	t_vector		tmp;
	t_vector		tmp2;

	if (hit(env, prim_ray, &rec))
	{
		if (depth < RAY_DEPTH && scatter(prim_ray, &rec, &att, &sec_ray))
		{
			tmp2 = get_color(env, &sec_ray, depth + 1);
			tmp.x = att.x *tmp2.x;
			tmp.y = att.y *tmp2.y;
			tmp.z = att.z *tmp2.z;
			return (tmp);
		}
		else
			return (new_vector(0, 0, 0));
	}
	else
	{
		t = 0.5 * (normalise(prim_ray->dir).y + 1.0);
		color.x = (1.0 - t) + t * 0.5;
		color.y = (1.0 - t) + t * 0.7;
		color.z = (1.0 - t) + t * 1.0;
		return (color);
	}
}

void		get_ray(t_ray *ray, t_camera *cam, int i, int j)
{
	float	u;
	float	v;

	u = (float)(i + drand48()) / (float)WIN_WIDTH;
	v = (float)(j + drand48()) / (float)WIN_HEIGH;
	ray->dir.x = cam->up_left.x + u * cam->hori.x - v * cam->vert.x - cam->pos_x;
	ray->dir.y = cam->up_left.y + u * cam->hori.y - v * cam->vert.y - cam->pos_y;
	ray->dir.z = cam->up_left.z + u * cam->hori.z - v * cam->vert.z - cam->pos_z;
}

void	*thread_fnc(void *data)
{
	int 			i;
	int				k;
	t_vector		col;
	t_thread_arg *thread_arg;
	int				j;
	t_ray			ray;

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
			col = add_vector(col, get_color(thread_arg->env, &ray, 0));
		}
		put_pixel(thread_arg->img, i, j, &col);
	}
    pthread_exit(NULL);
}

void	draw_img(t_img *img, t_env *env)
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
    pthread_mutex_init ( &thread_arg.mutex, NULL);
	while (++j < WIN_HEIGH)
		(pthread_create(&thread[j], NULL, thread_fnc, &thread_arg) != 0)
															? exit(3) : 0;
	i =-1;
	while (++i < WIN_HEIGH)
		pthread_join(thread[i], NULL);
	free(thread);
}

int					key_hook(int k, t_img *mlx)
{
	if (k == 53)
		clean_quit(mlx);
	return (0);
}

void	render(t_env *env)
{
	t_img	*img;

	(!(img = (t_img*)malloc(sizeof(t_img)))) ? exit(-1) : 0;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIN_WIDTH, WIN_HEIGH, "RT");
	img->ptr = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGH);
	img->buffer = (int*)mlx_get_data_addr(img->ptr, &(img->bpp), &(img->line_s),
														&(img->endian));
	mlx_hook(img->win, 17, 0, clean_quit, img);
	mlx_key_hook(img->win, key_hook, img);
	draw_img(img, env);
	mlx_put_image_to_window(img->mlx, img->win, img->ptr, 0, 0);
	mlx_loop(img->mlx);
	destroy_img(img);
}
