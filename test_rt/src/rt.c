#include <stdlib.h>
#include <math.h>
#include "rt.h"

// t_vec3f				*add_vector(t_vec3f *a, t_vec3f *b)
// {
// 	t_vec3f			*c;

// 	c = (t_vec3f *)malloc(sizeof(t_vec3f));
// 	c.x = a.x + b.x;
// 	c.y = a.y + b.y;
// 	c.z = a.z + b.z;
// 	return (c);
// }

// t_vec3f				*mult_vector(t_vec3f *a, float b)
// {
// 	t_vec3f			*c;

// 	c = (t_vec3f *)malloc(sizeof(t_vec3f));
// 	c.x = a.x * b;
// 	c.y = a.y * b;
// 	c.z = a.z * b;
// 	return (c);
// }

t_mlx				*new_mlx()
{
	t_mlx			*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGTH);
	mlx->data = mlx_get_data_addr(mlx->img, &(mlx->color), &(mlx->size), &(mlx->endian));
	return (mlx);
}

t_env				*env_init()
{
	t_env			*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->mlx = new_mlx();
	return (env);
}

void				add_sphere(t_env *env)
{
	env->object.x = 0;
	env->object.y = 0;
	env->object.z = -10;
	env->object.r = 0.7;
}

void				cam_init(t_env *env)
{
	env->cam.pos.x = 0;
	env->cam.pos.y = 0;
	env->cam.pos.z = 0;
	env->cam.dir.x = 0;
	env->cam.dir.y = 0;
	env->cam.dir.z = -1;

}

// void				test_mlx(t_mlx *mlx)
// {
// 	int				i = 0;
// 	int				j = 0;

// 	while (j <= 50)
// 	{
// 		i = 0;
// 		while (i <= 100)
// 		{
// 			mlx_pixel_put(mlx->ptr, mlx->win, i + 375, j + 295, 0x00500000);
// 			i++;
// 		}
// 		j++;
// 	}
// }

void				quit(t_env *env)
{
	mlx_destroy_window(env->mlx->ptr, env->mlx->win);
	exit(0);
}

int					key_hook(int k, t_env *env)
{
	if (k == 53)
		quit(env);
	return (0);
}

int					intersect(t_vec3f *point, t_env *env)
{
	float			a;
	float			b;
	float			c;
	float			det;
	float			t1;
	float			t2;

	a = point->x * point->x + point->y * point->y + point->z * point->z;
	b = 2 * (point->x * (-env->object.x) + point->y * (-env->object.y) + point->z * (-env->object.z));
	c = env->object.x * env->object.x + env->object.y * env->object.y + env->object.z * env->object.z - env->object.r * env->object.r;
	det = b * b - 4 * a * c;
	if (det < 0)
		return (0);
	if (det == 0)
	{
		t1 = - (b / (2 * a));
		return (t1);
	}
	if (det > 0)
	{
		t1 = (-b + sqrt(det)) / (2 * a);
		t2 = (-b - sqrt(det)) / (2 * a);
		t1 = (t1 > t2 ? t1 : t2);
		return ((t1 - 10) * 100);
	}
	return (0);
}

t_vec3f				*normalise(t_vec3f *a)
 {
 	double		len;

 	len = sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
 	a->x /= len;
 	a->y /= len;
 	a->z /= len;
 	return (a);
 }

int					point_calc(t_env *env, t_vec3f *upleft, t_vec3f *point, int x, int y)
{
	int				color;
	float			t;

	color = 0;
	point->x = upleft->x - ((float)(0.50 / (float)WIDTH) * x);
	point->y = upleft->y - ((float)(0.35 / (float)HEIGTH) * y);
	point->z = upleft->z;
	point = normalise(point);
	if ((t = intersect(point, env)))
	{
		color += (int)(3 * t) << 16;
		color += (int)(3 * t) << 8;
		color += (int)(3 * t);
		return (color);
	}
	else
		return (0x00990000);
}

t_vec3f				*upleft_calc()
{
	t_vec3f			*upleft;

	upleft = (t_vec3f *)malloc(sizeof(t_vec3f));
	upleft->x = 0.25;
	upleft->y = 0.175;
	upleft->z = -2;
	return (upleft);
}

void				render(t_env *env)
{
	t_vec3f			*upleft;
	t_vec3f			*point;
	int				x;
	int				y;
	int				color;

	y = 0;
	point = (t_vec3f *)malloc(sizeof(t_vec3f));
	upleft = upleft_calc();
	while (y <= HEIGTH)
	{
		x = 0;
		while (x <= WIDTH)
		{
			color = point_calc(env, upleft, point, x, y);
			mlx_pixel_put(env->mlx->ptr, env->mlx->win, x, y, color);
			x++;
		}
		y++;
	}
}

int					main()
{
	t_env			*env;

	env = env_init();
	env->mlx->win = mlx_new_window(env->mlx->ptr, WIDTH, HEIGTH, "RT");
	cam_init(env);
	add_sphere(env);
	render(env);
	mlx_key_hook(env->mlx->win, key_hook, env);
	mlx_loop(env->mlx->ptr);
	return (0);
}