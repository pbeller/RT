#include "vector.h"
#include <math.h>

t_vector	*add_vector(t_vector *a, t_vector *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	return (a);
}

t_vector	prod_vector(t_vector *a, t_vector *b)
{
	t_vector	c;

	c.x = a->y * b->z - b->y * a->z;
	c.y = a->z * b->x - b->z * a->x;
	c.z = a->x * b->y - b->x * a->y;
	return (c);
}

double		scal_prod(t_vector *a, t_vector *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

double		norm(t_vector *a)
{
	return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}
