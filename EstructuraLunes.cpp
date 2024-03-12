#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main(){

	int arr[] = { -5,5,0,75,65 };
	int len = 5;
	ordenamiento<int>(arr, len);

	for (int i = 0; i < len; i++) {

		cout << arr[i] << endl;
	}

	/*ordenamiento con strings*/

	string names[10] = { "uno","dos","tres","cuatro","cinco","seis","siete","ocho" };
	int len2 = 8;

	ordenamiento<string>(names, len2);

	for (int i = 0; i < len2; i++) {

		cout << names[i] << endl;
	}

	cout << "\n\nORDENAMIENTO USANDO ALGORITMO2\n";

	int arr3[] = { -5,5,0,75,65 };
	int len3 = 5;
	ordenamiento2<int>(arr3, len3, criterioInt1);

	for (int i = 0; i < len; i++) {

		cout << arr3[i] << endl;

	}

	cout << "\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";

	int arr4[] = { -5,5,0,75,65 };
	int len4 = 5;
	ordenamiento2<int>(arr4, len4, criterioInt2);

	for (int i = 0; i < len4; i++) {

		cout << arr4[i] << endl;
	}

	cout << "\n\nUSANDO LA FUNCION CRITERIOSTRING\n\n";

	string names2[10] = { "uno","dos","tres","cuatro","cinco","seis","siete","ocho" };
	int len6 = 8;

	ordenamiento2<string>(names2, len6, criterioString1);

	for (int i = 0; i < len2; i++) {

		cout << names2[i] << endl;
	}


	cout << "\n\nUSANDO LA FUNCION CRITERIOSTRING\n\n";

	string names3[10] = { "uno","dos","tres","cuatro","cinco","seis","siete","ocho" };
	int len7 = 8;

	ordenamiento2<string>(names3, len7, criterioString2);

	for (int i = 0; i < len7; i++) {

		cout << names3[i] << endl;
	}


	cout << "\n\nUSANDO LA FUNCION PARA BUSCAR UN ELEMENTO DENTRO DE UN ARRAY\n\n";

	string names8[10] = { "uno","dos","tres","cuatro","cinco","seis","siete","ocho" };
	int len8 = 8;

	cout<<searh<string>(names8, len8, "cinco");




	return 0;
   
}

