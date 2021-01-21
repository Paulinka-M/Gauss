#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

	int i,j;
	int w;//wiersze
	int k;//kolumny
	double suma= 0;
	if(mat->r != mat->c)
		return 2;
	w= mat -> r;
	k= mat -> c;

	for(i= 0;i<k;i++)
	{
		if( mat->data[i][i]==0)
			return 1;
	}
	
	for(i= w-1; w>=0; w--)
	{
		for(j= i+1; j<k; j++)
			suma += mat->data[i][j] * x->data[j][0];
		x -> data[i][0] = (b -> data[i][0] - suma) / mat -> data[i][i];
	}
	return 0;
}
