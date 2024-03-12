

#ifndef __TAREA__
#define __TAREA__

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
	XXXXXXXXXXXXXXXXX
	x.......x..t....x
	xXXX...t....xxxxx
	xXXX...t....xxxxx
	xXXXXXXXXXXXXXXXX

*/


vector<pair<int, int>> direcciones = { {0,1},{0,-1},{-1,0},{1,0} };

bool limitado(vector<vector<char> >& T, int i, int j) { /*determinar si el agente o el robot esta dentro de los limites del map*/


	return i >= 0 and j >= 0 and i< int(T.size()) and j < int(T[0].size());

}


bool dfs(vector<vector<char> >& T, int i, int j) { /*recibe mapa*/

	/*CASO BASE*/

	if (T[i][j] == 't') {

		return true;
	}
	else if (T[i][j] == 'X') {

		return false;
	}

	// Moverme en el mapa

	for (auto& d : direcciones) {

		int adj_i = i + d.first;
		int adj_j = j + d.second;


		// (adj_i,adj_j) nueva posicion casilla
		if (limitado(T, adj_i, adj_j) and dfs(T, adj_i, adj_j))
			
			return true;

	}

	return false;	// No he sido capaz de llegar a ningún tesoro
}



void mapa() {

	int n, m; //vertices y aristas
	int r, c; //son x,y las coordenadas donde se encuentra el agente

	bool respuesta_algoritmo;
	vector<vector<char> > T(n, vector<char>(m)); /*Cree el mapa de caracteres*/

	/*inicializacion del mapa*/

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			cin >> T[i][j];
		}
	}

	cout << "Digite las coordenadas del agente::";
	cin >> r >> c;

	/*algoritmo dfs*/

	respuesta_algoritmo = dfs(x, y, z);

	if (respuesta_algoritmo) {


		cout << "Encontro un tesoro en el mapa";
	}
	else {

		cout << "No se encuentra el tesoro en el mapa";

	}

}


#endif // !__GRAFOS__
