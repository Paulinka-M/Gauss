#include "mat_io.h"
#include "element_glowny.h"
#include "gauss.h"

#include <math.h>
#include <stdlib.h>
//wybor niezerowego elementu diagonalnego

int wybor(int k, Matrix *mat, Matrix *b)
{//w - wiersz, k- kolumna
	int max = fabs(mat->data[k][k]);
	int w = k;
	
	int i = k + 1, j = 0;
	double pom;
	for(i; i < mat -> r; i ++)  // petla szuka max
		for(j=i;j<mat->r;j++)
			if(max < fabs(mat->data[j][i]))
			{
				max = mat->data[j][i];
				w = j;//zmieniam nr wiersza ktory wybrany
			}
	//zamien wiersze zeby sprobowac usunac zero na diagonali
	if (max > fabs(mat->data[i][i])){
		for(i;i < mat->c; i++)
		{
			pom = mat->data[w][i];
			mat->data[w][i] = mat->data[k][i];
			mat->data[k][i] = pom;
		}
		pom = b->data[w][0];//zamiana w wektorze z wyrazami wolnymi
		b->data[w][0] = b->data[k][0];
		b->data[k][0] = pom;
	}
	if(mat->data[k][k] == 0 ) 
		return -1; //nie udalo sie pozbyc zera
	else 
		return 0;
}
