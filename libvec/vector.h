#ifndef VECTOR_H
# define VECTOR_H

typedef	struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

t_vector	*add_vector(t_vector *a, t_vector *b);
t_vector	prod_vector(t_vector *a, t_vector *b);
double		scal_prod(t_vector *a, t_vector *b);
double		norm(t_vector *a);

t_vector		*normalise(t_vector *a);
#endif
