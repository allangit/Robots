#ifndef __FUNCIONES__
#define __FUNCIONES__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


int criterioInt1(int a, int b) {


	return a - b;
}

int criterioInt2(int a, int b) {


	return b - a;
}

int criterioString1(string a , string b) {


	return a < b ? -1 : a >b ? 1 : 0;

}


int criterioString2(string a, string b) {

	int var;


	if (a.size() == b.size()) {

		var=a < b ? -1 : a >b ? 1 : 0;

	}
	else {

		var= a.size()-b.size();
	}

	return var;

}

template <typename T> void ordenamiento(T a[], int len) {


	bool bandera = false;
	T aux;

	while (!bandera) {

		bandera = true;

		for (int i = 0; i < len - 1; i++) {

			if (a[i] > a[i + 1]) {/*si entra al if es porque hay un intercambio y array esta desordenado*/

				aux = a[i];
				a[i] = a[i + 1];
				a[i + 1] = aux;
				bandera = false;
			}
		}

	}
	return;
}

template <typename T> void ordenamiento2(T a[], int len, int (*criterio)(T,T)) {


	bool bandera = false;
	T aux;

	while (!bandera) {

		bandera = true;

		for (int i = 0; i < len - 1; i++) {

			if (criterio(a[i],a[i+1]) >0) {/*si entra al if es porque hay un intercambio y array esta desordenado*/

				aux = a[i];
				a[i] = a[i + 1];
				a[i + 1] = aux;
				bandera = false;
			}
		}

	}
	return;
}

template <typename T> int searh(T a[], int len, T buscado) {

	int i = 0;

	while (i < len&& a[i] != buscado) {

		i++;
	}


	return i < len ? i : -1;

}



#endif // __FUNCIONES
