/*Ejercicios de Grafos*/
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {

    /*Declaro los vertices y aristas*/
	int n;	
	int m;
    int x, y; 

    /*Leo los vertices y aristas*/
	cin >> n >> m;

	// Declaro Matriz de Adyacencia

	vector< vector<int> > G(n);	

	// Leo el Grafo por la Consola
	for (int i = 0; i < m; ++i) {
		
		cin >> x >> y;	// Leo arista (x,y) 

		G[x].push_back(y);	
		G[y].push_back(x);	

	}

	// Imprimir el Grafo G(n) por la Consola
	for (int i = 0; i < n; i++) {

		cout << "Vertices adyacentes a " << i << ": ";

		for (int j = 0; j < G[i].size(); j++){

            cout << G[i][j] << ' ';

        } 
		cout << endl;
	}

    return 0;
}