#include "vector.h"
#include <math.h>

t_vector	normalise(t_vector a)
{
	float	len;

	len = norm(&a);
	a.x /= len;
	a.y /= len;
	a.z /= len;
	return (a);
}

t_vector	new_vector(float x, float y, float z)
{
	t_vector	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

void	set_value_vector(t_vector *vect, float x, float y, float z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}

float		norm(const t_vector *a)
{
	return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}