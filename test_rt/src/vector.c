#include <math.h>
#include "rt.h"

t_vec3f				*normalise(t_vec3f *a)
 {
 	double		len;

 	len = sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
 	a->x /= len;
 	a->y /= len;
 	a->z /= len;
 	return (a);
 }
