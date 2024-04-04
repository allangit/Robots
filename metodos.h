#pragma once


#ifndef __metodos__
#define __metodos__

#include <iostream>
#include <stdlib.h>
#include <filesystem>
#include <stdio.h>
#include <vector>
#include <deque>
#include <list>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <set>
//namespace fs = std::filesystem;
using namespace std;

template <class T> bool esPositivo(T valor) {

	return (valor >= 0);

}

void comandos_bash() {

	system("start comandos.bat");

}

void Add() {

	vector<int> numeros;

	/*agregando datos al vector*/
	for (int i = 0; i < 30; i++) {

		numeros.push_back(i);
	}
	/*imprimiendo los datos del vector*/
	for (int i = 0; i < numeros.size(); i++) {

		cout << numeros[i] << "|";
	}

	/*eliminar datos de un vector*/
	cout << "\n\n";
	numeros.pop_back();

	/*imprimiendo los datos del nuevo vector*/
	for (int i = 0; i < numeros.size(); i++) {

		cout << numeros[i] << "|";
	}

}

void eliminar_posiciones_especificas() {

	vector<int> numerosx;

	/*agregando datos al vector*/
	for (int i = 0; i < 7; i++) {

		numerosx.push_back(i);
	}
	/*imprimiendo los datos del vector*/
	for (int i = 0; i < numerosx.size(); i++) {

		cout << numerosx[i] << "|";
	}

	/*eliminar datos de posiciones especificas de array*/

	cout << "\n";
	numerosx.erase(numerosx.begin() + 1, numerosx.begin() + 5);
	for (int i = 0; i < numerosx.size(); i++) {

		cout << numerosx[i] << "|";
	}
	cout << "\n";
	/**/
}

void contenedor_cola() {

	deque<char> letra;

	letra.push_back('A');
	letra.push_back('B');
	letra.push_back('C');
	letra.push_back('D');
	letra.push_back('E');
	letra.push_back('F');

	/*mostrando los elementos de array*/
	for (int i = 0; i < letra.size(); i++) {

		cout << letra[i] << "|";
	}

	letra.pop_front();
	letra.pop_back();
	letra.pop_back();
	cout << "\n";
	for (int i = 0; i < letra.size(); i++) {

		cout << letra[i] << "|";
	}
}

void contenedor_lista() {

	list<int> data;
	list<int> dato;

	for (int i = 0; i < 40; i++) {

		data.push_back(i);
	}

	/*mostrar los datos del vector*/

	list<int>::iterator i;
	i = data.begin();

	while (i != data.end()) {

		cout << *i <<"|";
		i++;

	}

	cout << endl;

	/*datos totalmente desordenados*/
	dato.push_front(2);
	dato.push_front(-22);
	dato.push_front(-6);
	dato.push_front(3);
	dato.push_front(9);
	dato.push_front(-200);
	dato.push_front(10);
	dato.push_front(5);

	/*ordenamiento de los elementos*/
	cout << "\n\n\n";
	dato.sort();

	list<int>::iterator j;
	j = dato.begin();

	while (j != dato.end()) {

		cout << *j << "|";
		j++;

	}
}

/*Random access iterator*/

template <class Iter> void mostrar(Iter inicio, Iter final) {

	while (inicio != final) {

		cout << *inicio << "|";
		inicio++;
	}

	cout << "\n\n";
}

void lectura() {

	vector<float>numeros;
	ifstream archivo("datos2.txt", ios::in);

	/*copiar los datos del archivo txt al vector numeros*/

	copy(istream_iterator<float>(archivo), istream_iterator<float>(), back_inserter(numeros));
	cout << "Maximo:::" << *max_element(numeros.begin(), numeros.end());
	cout << endl;
	cout << "Minimo::" << *min_element(numeros.begin(), numeros.end());
	cout << "\n";
	cout << "Promedio::" << accumulate(numeros.begin(), numeros.end(), 0.0)/numeros.size();
	cout << "\n";
	cout << "Cantidad de numeros +" << count_if(numeros.begin(), numeros.end(),esPositivo<float>);


}

void valores_set() {

	set<int> valor;
	multiset<int> A;

	valor.insert(4);
	valor.insert(4);
	valor.insert(3);
	valor.insert(-8);
	valor.insert(-10);
	valor.insert(11);

	copy(valor.begin(), valor.end(), ostream_iterator<int>(cout, "<->"));

	/*buscar Elementos dentro del set*/

	set<int>::iterator i;
	i = valor.find(10);

	if (i != valor.end()) {

		cout << "\nEl elemento buscando a sido encontrado" << *i << endl;
	}
	else {

		cout << "\nEl elemento buscando no ha sido encontrado"<< endl;

	}

	cout << "\n\ndefiniendo el multiset los valores\n";

	A.insert(4);
	A.insert(4);
	A.insert(4);
	A.insert(4);
	A.insert(4);
	A.insert(4);
	A.insert(3);
	A.insert(-8);
	A.insert(-10);
	A.insert(11);

	copy(A.begin(), A.end(), ostream_iterator<int>(cout, "|"));

	/*Buscar el multiset*/

	multiset<int>::iterator j;
	j = A.find(4);
	copy(A.begin(), A.end(), ostream_iterator<int>(cout, "|"));

	if (j != A.end()) {

		cout << "\nEl elemento buscando a sido encontrado" << *j << endl;
	}
	else {

		cout << "\nEl elemento buscando no ha sido encontrado" << endl;

	}

}

#endif // !__metodos__
