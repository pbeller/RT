#include <stdlib.h>
#include "rt.h"

t_mlx				*new_mlx()
{
	t_mlx			*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGTH);
	mlx->data = mlx_get_data_addr(mlx->img, &(mlx->color),\
		&(mlx->size), &(mlx->endian));
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGTH, "RT");
	return (mlx);
}