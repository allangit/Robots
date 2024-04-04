

#include <iostream>
#include <stdlib.h>
#include <filesystem>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include "metodos.h"
using namespace std;


int main() {
	
	//comandos_bash();
	//Add();
	//eliminar_posiciones_especificas();
	//contenedor_cola();
	//contenedor_lista();
	vector<int>letras(10);
	for (int i = 0; i < letras.size(); i++) {

		letras[i] = 'A' + (rand() % 26);
	}


	/*llamar la funcion mostrar*/
	mostrar(letras.begin(), letras.end());
	lectura();
	cout << "\n\n";
	valores_set();





	return 0;
}