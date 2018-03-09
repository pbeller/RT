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

	FONCTIONS PAS A LA NORME:
	
	-m_fill => remplit une matrice 4x4 a partir de 4 lignes (4 arguments max par fonction)

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

double		**m_fill(double *l_0, double *l_1, double *l_2, double *l_3,\
	double **matrix)
{
	int		i;

	matrix = (double **)malloc(sizeof(double *) * 4);
	i = 0;
	while (i <= 3)
		matrix[i++] = (double *)malloc(sizeof(double) * 4);
	i = 0;
	while (i <= 3)
	{
		matrix[0][i] = l_0[i];
		matrix[1][i] = l_1[i];
		matrix[2][i] = l_2[i];
		matrix[3][i] = l_3[i];
		i++;
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

double				m_det44(double **a)
{
	double			det;

	det = (a[0][0] * a[1][1] * a[2][2] * a[3][3] +\
			a[0][1] * a[1][2] * a[2][3] * a[3][0] +\
			a[0][2] * a[1][3] * a[2][0] * a[3][1] +\
			a[0][3] * a[1][0] * a[2][1] * a[3][2]) -\
			(a[0][2] * a[1][1] * a[2][0] * a[3][3] +\
			a[0][1] * a[1][0] * a[2][3] * a[3][2] +\
			a[0][0] * a[1][3] * a[2][2] * a[3][1] +\
			a[0][3] * a[1][2] * a[2][1] * a[3][0]);
	return (det);
}

void				m_print(double **matrix)
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

int					m_pivot_seek(double **matrix, int j, int r)
{
	double			pivot;
	int				i;
	int				k;

	i = r;
	k = 0;
	pivot = fabs(matrix[i][j]);
	while (i <= 3)
	{
		if (pivot < fabs(matrix[i][j]))
		{
			pivot = fabs(matrix[i][j]);
			k = i;
		}
		i++;
	}
	printf("%d\n", k);
	return (k);
}

double				**m_inverse(double **matrix)
{
	double			**inv;
	double			pivot;
	int				r;
	int				j;
	int				k;

	inv = m_unity();
	j = 0;
	r = 0;
	while (j <= 3)
	{
		pivot = m_pivot_seek(matrix, j, r);
		j++;
	}
	return (inv);
}

int					main()
{
	double			**matrix;
	double			**matrix_2;
	double			**matrix_3;
	double			**matrix_4;
	double			*line0;
	double			*line1;
	double			*line2;
	double			*line3;


	
	line0 = (double *)malloc(sizeof(double) * 4);
	line1 = (double *)malloc(sizeof(double) * 4);
	line2 = (double *)malloc(sizeof(double) * 4);
	line3 = (double *)malloc(sizeof(double) * 4);

	line0[0] = 1;
	line0[1] = 2;
	line0[2] = 3;
	line0[3] = 4;
	line1[0] = 4;
	line1[1] = 3;
	line1[2] = 2;
	line1[3] = 1;
	line2[0] = 3;
	line2[1] = 4;
	line2[2] = 1;
	line2[3] = 2;
	line3[0] = 2;
	line3[1] = 1;
	line3[2] = 4;
	line3[3] = 3;
	matrix = m_fill(line0, line1, line2, line3, matrix);
	m_print(matrix);
	printf("\n");


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
	matrix = m_scalaire(matrix, 2);
	m_print(matrix);
	return (0);
}