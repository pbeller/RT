#include <math.h>
#include <stdlib.h>
#include "rt.h"

float				intersect(t_vec3f *point, t_env *env)
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
		return (t1);
	}
	return (0);
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
		t = (t - 10) * 100;
		//color += (int)(3 * t) << 16;
		//color += (int)(3 * t) << 8;
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