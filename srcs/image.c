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
	col->x = sqrt(col->x / (float)AA_STRENGH);
	col->y = sqrt(col->y / (float)AA_STRENGH);
	col->z = sqrt(col->z / (float)AA_STRENGH);
	color = (int)( 255.99 * col->x) << 16;
	color += (int)( 255.99 * col->y) << 8;
	color += (int)( 255.99 * col->z);
	img->buffer[x + WIN_WIDTH * y] = color;
}