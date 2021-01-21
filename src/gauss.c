#include "gauss.h"
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {

	int i, j, k; // iteratory 

	int m = sizeof ( mat->data ) / sizeof ( mat->data[0] );
	int n = sizeof ( mat->data ) / sizeof ( mat->data[0][0] );
	n /= m;	// m - liczba wierszy, n - liczba kolumn	

	for ( i = 0 ; i < m - 1  ; i++ ) {
		for ( k = i + 1 ; k < m; k++ ) {
			if ( fabs ( mat->data[i][i] ) < fabs( mat->data[k][i] ) ){
				// Porównujemy wartość bezwzględną elementu diagonalnego z wszystkimi poniżej.
				for ( j = 0; j < n + 1; j++ ) { // funkcja "swap"
					if ( j < n ){
						double pom; // zmienna pomocnicza
						pom = mat->data[i][j];
						mat->data[i][j] = mat->data[k][j];
						mat->data[k][j] = pom;
					}
					else
					{
						double pom = b->data[i][1];
						b->data[i][1] = b->data[k][1];
						b->data[k][1] = pom;	
					}
				}
			}
		}

		// Eliminacja
		for ( k = i + 1; k < m; k++ ) {
			if ( mat->data[i][i] == 0) return 1;
			double  p = mat->data[k][i]/ mat->data[i][i];
			for ( j = 0; j < n + 1; j++ ){
				if ( j < n ){
					mat->data[k][j] = mat->data[k][j] - p*mat->data[i][j];
				}
				else
				{
					b->data[k][1] = b->data[k][1] - p * b->data[i][1];
				}
			}
		}
	}
		
	return 0;
}

