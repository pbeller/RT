#include "rt.h"

void	destroy_img(t_img *img)
{
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_image(img->mlx, img->ptr);
	free(img);
}

int		clean_quit(void *parram)
{
	destroy_img(parram);
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
	col->x = sqrt(col->x);
	col->y = sqrt(col->y);
	col->z = sqrt(col->z);
	col->x = (col->x > 1) ? 1 : col->x;
	col->y = (col->y > 1) ? 1 : col->y;
	col->z = (col->z > 1) ? 1 : col->z;
	color = (int)( 255.99 * col->x) << 16;
	color += (int)( 255.99 * col->y) << 8;
	color += (int)( 255.99 * col->z);
	img->buffer[x + WIN_WIDTH * y] = color;
}