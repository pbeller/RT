//#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

	LIB POUR MATRICES 4x4 DE DOUBLES
	FONCTIONS OPERATIONNELLES:

	-m_unity => creation + malloc d'une matrice unitaire 4x4
	-m_scalaire => produit matrice 4x4 par un scalaire
	-m_prod => produit matriciel de 2 matrices 4x4
	-m_add => addition de 2 matrices 4x4
	-m_transpose => transposée d'une matrice 4x4
	-m_print => affichage d'une matrice 4x4
	-m_pivot_seek => recherche index du pivot de Gauss dans une matrice 4x4
	-m_fill => remplit une matrice 4x4 depuis un array[16]
	
	FONCTIONS PAS A LA NORME:
	
	

	FONCTIONS EN COURS DE DEV:

	-m_inverse => calcul de l'inverse d'une matrice 4x4 par elimination de Gauss/Jordan
	-m_det44 => calcul du determinant d'une matrice 4x4

	FONCTIONS MANQUANTES:

	-transformation d'un vecteur par matrice de transfo
	-multVecMatrix
	-multDirMatrix
*/

double 				**m_unity()
{
	double			**unity;
	int				i;
	int				j;

	unity = (double **)malloc(sizeof(double *) * 4);
	j = 0;
	while (j <= 3)
	{
		i = 0;
		unity[j] = (double *)malloc(sizeof(double) * 4);
		while (i <= 3)
		{
			if (i == j)
				unity[j][i] = 1;
			else
				unity[j][i] = 0;
			i++;
		}
		j++;
	}
	return (unity);
}

double		**m_scalaire(double **matrix, double n)
{
	int		i;
	int		j;

	j = 0;
	while(j <= 3)
	{
		i = 0;
		while (i <= 3)
		{
			matrix[j][i] *= n;
			i++;
		}
		j++;
	}
	return (matrix);
}

double		**m_prod(double **a, double **b)
{
	double	**ret;
	int		i;
	int		j;

	j = 0;
	ret = m_unity();
	while (j <= 3)
	{
		i = 0;
		while (i <= 3)
		{
			ret[j][i] = a[j][0] * b[0][i] + a[j][1] * b[1][i] +\
			a[j][2] * b[2][i] + a[j][3] * b[3][i];
			i++;
		}
		j++;
	}
	return (ret);
}

float		**m_fill(float **matrix, float *data)
{
	int		i;
	int		j;

	matrix = (float **)malloc(sizeof(float *) * 4);
	j = 0;
	while (j <= 3)
		matrix[j++] = (float *)malloc(sizeof(float) * 4);
	j = 0;
	while (j <= 3)
	{
		i = 0;
		while (i <= 3)
		{
			matrix[j][i] = data[4 * j + i];
			i++;
		}
		j++;
	}
	return (matrix);
}

double				**m_add(double **a, double **b)
{
	int				i;
	int				j;

	j = 0;
	while (j <= 3)
	{
		i = 0;
		while (i <= 3)
		{
			a[j][i] += b[j][i];
			i++;
		}
		j++;
	}
	return (a);
}

double				**m_transpose(double **a)
{
	int				i;
	int				j;
	double			tmp;

	j = 0;
	i = 0;
	while (j <= 3)
	{
		while (i <= 3)
		{
			tmp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tmp;
			i++;
		}
		j++;
		i = j;
	}
	return (a);
}

// double				m_det44(double **a)
// {
// 	double			det;

// 	det = (a[0][0] * a[1][1] * a[2][2] * a[3][3] +\
// 			a[0][1] * a[1][2] * a[2][3] * a[3][0] +\
// 			a[0][2] * a[1][3] * a[2][0] * a[3][1] +\
// 			a[0][3] * a[1][0] * a[2][1] * a[3][2]) -\
// 			(a[0][2] * a[1][1] * a[2][0] * a[3][3] +\
// 			a[0][1] * a[1][0] * a[2][3] * a[3][2] +\
// 			a[0][0] * a[1][3] * a[2][2] * a[3][1] +\
// 			a[0][3] * a[1][2] * a[2][1] * a[3][0]);
// 	return (det);
// }

void				m_print(float **matrix)
{
	int				i;
	int				j;

	j = 0;
	while (j <= 3)
	{
		i = 0;
		while (i <= 3)
		{
			printf("%f ", matrix[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

// void				m_vecmatrix(double **matrix, t_vector *src, t_vector *dst)
// {

// }

// int					m_pivot_seek(double **matrix, int j, int r)
// {
// 	double			pivot;
// 	int				i;
// 	int				k;

// 	i = r;
// 	k = 0;
// 	pivot = fabs(matrix[i][j]);
// 	while (i <= 3)
// 	{
// 		if (pivot < fabs(matrix[i][j]))
// 		{
// 			pivot = fabs(matrix[i][j]);
// 			k = i;
// 		}
// 		i++;
// 	}
// 	printf("%d\n", k);
// 	return (k);
// }

// float				**m_inverse(float **matrix)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		pivot;
// 	float	f;
// 	float	pivotsize;
// 	float	tmp;
// 	float	**inv;

// 	i = 0;
// 	inv = (float **)malloc(sizeof(float *) * 4);
// 	while (i <= 3)
// 	{
// 		inv[i] = (float *)malloc(sizeof(float) * 4);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 3)
// 	{
// 		pivot = i;
// 		pivotsize = fabs(matrix[i][i]);
// 		j = i + 1;
// 		while (j < 4)
// 		{
// 			tmp = fabs(matrix[j][i]);
// 			if (tmp > pivotsize)
// 			{
// 				pivot = j;
// 				pivotsize = tmp;
// 			}
// 			j++;
// 		}
// 		if (pivotsize == 0)
// 			return (matrix);
// 		if (pivot != i)
// 		{
// 			j = 0;
// 			while (j < 4)
// 			{
// 				tmp = matrix[i][j];
// 				matrix[i][j] = matrix[pivot][j];
// 				matrix[pivot][j] = tmp;

// 				tmp = inv[i][j];
// 				inv[i][j] = inv[pivot][j];
// 				inv[pivot][j] = tmp;
// 				j++;
// 			}
// 		}
// 		j = i + 1;
// 		while (j < 4)
// 		{
// 			f = matrix[j][i] / matrix[i][i];
// 			k = 0;
// 			while (k < 4)
// 			{
// 				matrix[j][k] -= f * matrix[i][k];
// 				inv[j][k] -= f * inv[i][k];
// 				k++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	i = 3;
// 	while (i >= 0)
// 	{
// 		if ((f = matrix[i][i]) == 0)
// 			return(matrix);
// 		j = 0;
// 		while (j < 4)
// 		{
// 			matrix[i][j] /= f;
// 			inv[i][j] /= f;
// 			j++;
// 		}
// 		j = 0;
// 		while (j < i)
// 		{
// 			f = matrix[j][i];
// 			k = 0;
// 			while (k < 4)
// 			{
// 				matrix[j][k] -= f* matrix[i][k];
// 				inv[j][k] -= f * inv[i][k];
// 				k++;
// 			}
// 			j++;
// 		}
// 		i--;
// 	}
// 	return (inv);
// }

// double				**m_inverse(double **matrix)
// {
// 	double			**inv;
// 	double			pivot;
// 	int				r;
// 	int				j;
// 	int				k;

// 	inv = m_unity();
// 	j = 0;
// 	r = 0;
// 	while (j <= 3)
// 	{
// 		pivot = m_pivot_seek(matrix, j, r);
// 		j++;
// 	}
// 	return (inv);
// }

float				**m_inverse(float **matrix)
{
	
}

int					main()
{
	float			**matrix;
	float			**matrix_2;
	double			**matrix_3;
	double			**matrix_4;
	double			*line0;
	double			*line1;
	double			*line2;
	double			*line3;
	float			data[16] = {1,2,1,1,4,1,1,1,1,1,5,1,1,1,1,-2};
	double			det;

	matrix = m_fill(matrix, data);
	m_print(matrix);
	printf("\n");

	matrix_2 = m_inverse(matrix);
	m_print(matrix_2);
	// det = m_det44(matrix);
	// printf("%f\n", det);

	// line0 = (double *)malloc(sizeof(double) * 4);
	// line1 = (double *)malloc(sizeof(double) * 4);
	// line2 = (double *)malloc(sizeof(double) * 4);
	// line3 = (double *)malloc(sizeof(double) * 4);

	// line0[0] = 1;
	// line0[1] = 2;
	// line0[2] = 3;
	// line0[3] = 4;
	// line1[0] = 4;
	// line1[1] = 3;
	// line1[2] = 2;
	// line1[3] = 1;
	// line2[0] = 3;
	// line2[1] = 4;
	// line2[2] = 1;
	// line2[3] = 2;
	// line3[0] = 2;
	// line3[1] = 1;
	// line3[2] = 4;
	// line3[3] = 3;
	// matrix = m_fill(line0, line1, line2, line3, matrix);
	// m_print(matrix);
	// printf("\n");


	// line0[0] = 4;
	// line0[1] = 3;
	// line0[2] = 2;
	// line0[3] = 1;
	// line1[0] = 1;
	// line1[1] = 2;
	// line1[2] = 3;
	// line1[3] = 4;
	// line2[0] = 2;
	// line2[1] = 1;
	// line2[2] = 3;
	// line2[3] = 4;
	// line3[0] = 3;
	// line3[1] = 1;
	// line3[2] = 4;
	// line3[3] = 2;
	// matrix_2 = m_fill(line0, line1, line2, line3, matrix_2);
	// m_print(matrix_2);
	// printf("\n");

	// matrix[0][0] = 1;
	// matrix[0][1] = 2;
	// matrix[0][2] = 3;
	// matrix[0][3] = 4;
	// matrix[1][0] = 4;
	// matrix[1][1] = 3;
	// matrix[1][2] = 2;
	// matrix[1][3] = 1;
	// matrix[2][0] = 3;
	// matrix[2][1] = 4;
	// matrix[2][2] = 1;
	// matrix[2][3] = 2;
	// matrix[3][0] = 2;
	// matrix[3][1] = 1;
	// matrix[3][2] = 4;
	// matrix[3][3] = 3;
	// matrix = m_transpose(matrix);
	// matrix = m_unity();
	// matrix_2 = m_unity();
	// matrix_3 = m_add(matrix, matrix_2);
	// matrix_4 = m_inverse(matrix_3);
	// m_print(matrix);
	// matrix_2 = m_unity();
	// matrix_3 = m_prod(matrix, matrix_2);
	// matrix = m_scalaire(matrix, 2);
	// m_print(matrix);
	return (0);
}