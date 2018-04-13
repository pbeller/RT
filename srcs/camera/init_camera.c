#include "vector.h"
#include "camera.h"
# include <math.h>

void	init_camera(t_camera *cam, float aspect)
{
	float		theta;
	float		half_height;
	float		half_width;
	t_vector	u;
	t_vector	v;
	t_vector	w;

	theta = cam->fov * M_PI / 180;
	half_height = tan(theta / 2);
	half_width = aspect * half_height;
	w.x = cam->pos.x - cam->dir_x;
	w.y = cam->pos.y - cam->dir_y;
	w.z = cam->pos.z - cam->dir_z;
	w = normalise(w);
	u = prod_vector(new_vector(cam->up_x, cam->up_y, cam->up_z), w);
	u = normalise(u);
	v = prod_vector(w, u);

	cam->up_left.x = -half_width;
	cam->up_left.y = half_height;
	cam->up_left.z = -1.0;

	cam->up_left.x = cam->pos.x - half_width * u.x + half_height * v.x - w.x;
	cam->up_left.y = cam->pos.y - half_width * u.y + half_height * v.y - w.y;
	cam->up_left.z = cam->pos.z - half_width * u.z + half_height * v.z - w.z;

	cam->hori.x = 2.0 * half_width * u.x;
	cam->hori.y = 2.0 * half_width * u.y;
	cam->hori.z = 2.0 * half_width * u.z;

	cam->vert.x = 2.0 * half_height * v.x;
	cam->vert.y = 2.0 * half_height * v.y;
	cam->vert.z = 2.0 * half_height * v.z;
}


/*
static void	set_side_value(t_vector *side, float nb, const t_vector *vect)
{
	side->x = 2.0 * nb * vect->x;
	side->y = 2.0 * nb * vect->y;
	side->z = 2.0 * nb * vect->z;
}

void	init_camera(t_camera *cam, float aspect)
{
	float		half_height;
	float		half_width;
	t_vector	u;
	t_vector	v;
	t_vector	dist;

	half_height = cam->fov * M_PI / 180;
	half_height = tan(half_height / 2);
	half_width = aspect * half_height;
	set_value_vector(&dist, cam->pos.x - cam->dir_x, cam->pos.y - cam->dir_y,
													cam->pos.z - cam->dir_z);
	dist = normalise(dist);
	u = normalise(prod_vector(new_vector(cam->up_x, cam->up_y, cam->up_z), dist));
	v = prod_vector(dist, u);
	cam->up_left.x = cam->pos.x - half_width * u.x + half_height * v.x - dist.x;
	cam->up_left.y = cam->pos.y - half_width * u.y + half_height * v.y - dist.y;
	cam->up_left.z = cam->pos.z - half_width * u.z + half_height * v.z - dist.z;
	set_side_value(&cam->hori, half_width, &u);
	set_side_value(&cam->vert, half_height, &v);
}*/