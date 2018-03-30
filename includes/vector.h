#ifndef VECTOR1_H
# define VECTOR1_H

# include <stdlib.h>

typedef	struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

t_vector	*new_vector(float x, float y, float z);
t_vector	add_vector(t_vector a, t_vector b);
t_vector	prod_vector(t_vector a, t_vector b);
t_vector	prod_float(t_vector a, float f);
float		scal_prod(const t_vector *a, const t_vector *b);
float		norm(const t_vector *a);
void		set_value_vector(t_vector *vect, float x, float y, float z);

t_vector		normalise(t_vector a);
#endif
