#include "rt.h"

void	destroy(t_img *img)
{
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_image(img->mlx, img->ptr);
	free(img);
}

int		clean_quit(void *parram)
{
	destroy(parram);
	exit(0);
	return (0);
}

void	put_pixel(t_img *img, int x, int y, t_vector *col)
{
	int		color;

	if (img == NULL || x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGH)
		return ;
	col->x = col->x / (float)AA_STRENGH;
	col->y = col->y / (float)AA_STRENGH;
	col->z = col->z / (float)AA_STRENGH;
	color = (int)( 255.99 * col->x) << 16;
	color += (int)( 255.99 * col->y) << 8;
	color += (int)( 255.99 * col->z);
	img->buffer[x + WIN_WIDTH * y] = color;
}

void	point_at(t_ray *ray, float t, t_vector *tmp)
{
	tmp->x = ray->dir.x * t;
	tmp->y = ray->dir.y * t;
	tmp->z = ray->dir.z * t;

	tmp->x = tmp->x + ray->ori.x;
	tmp->y = tmp->y + ray->ori.y;
	tmp->z = tmp->z + ray->ori.z;
}

void		get_ray(t_ray *ray, t_camera *cam, int i, int j)
{
	float	u;
	float	v;

	u = (float)(i + drand48()) / (float)WIN_WIDTH;
	v = (float)(j + drand48()) / (float)WIN_HEIGH;
	ray->dir.x = cam->up_left.x + u * cam->hori.x + v * cam->vert.x - cam->pos_x;
	ray->dir.y = cam->up_left.y + u * cam->hori.y + v * cam->vert.y - cam->pos_y;
	ray->dir.z = cam->up_left.z + u * cam->hori.z + v * cam->vert.z - cam->pos_z;
}