#include <stdlib.h>
#include "rt.h"

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
	//free (point);
}