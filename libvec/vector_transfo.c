#include "vector.h"

t_vector		*normalise(t_vector *a)
 {
 	double		len;

 	len = norm(a);
 	a->x /= len;
 	a->y /= len;
 	a->z /= len;
 	return (a);
 }
