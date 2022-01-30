
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <utility>
#include <cstdlib>

using namespace std;

int contarUnos(vector<vector<int>> v, int esqArribaX, int esqArribaY, int esqAbajoX, int esqAbajoY) {
	int cuentaUnos = 0;
	int tamano = (esqAbajoX - esqArribaX) + 1;
	for (int i = esqArribaY; i <= esqAbajoY; i++) {
		for (int j = esqArribaX; j <= esqAbajoX; j++) {
			if (v[i][j] == 1) cuentaUnos++;
		}
	}
	return cuentaUnos;
}

// Comentario general sobre la solucion explicando como se resuelve el problema

// Requisitos
// 1. El numero total de parcelas de labranza no puede ser inferior (<) a la cuarta parte del numero
//    total de parcelas - 1 ni superior (>) a las tres cuartas partes del numero total de parcelas.
// 2. La diferencia del numero de parcelas de labranza entre las cuatro cuadriculas dos a dos no
//    puede ser superior a 2.
// 3. A su vez cada una de las cuatro cuadriculas ha de ser equilibrada.

// Para resolver el problema (en caso de no ser una unica parcela -> caso base) primero compruebo si se cumple
// la primera condicion, en caso de cumplirse comienzo la division en cuadriculas, para podar he decidido encapsular
// cada llamada en un if. Por ultimo en caso de que todas las llamadas se hayan podido llevar a cabo compruebo el
// cumplimiento de la segunda condicion. El cumplimiento de la tercera condicion va implicito en el uso de los
// if (sol){} y la recursion en si.

bool recursion(vector<vector<int>> v, int esqArribaX, int esqArribaY, int esqAbajoX, int esqAbajoY, int& numUnos) {
	int tamano = (esqAbajoX - esqArribaX) + 1;
	if (tamano == 1) {
		if (v[esqArribaX][esqArribaY] == 1) numUnos = 1;
		else numUnos = 0;
		return true;
	}
	else {
		//numUnos = contarUnos(v, esqArribaX, esqArribaY, esqAbajoX, esqAbajoY);
		//if (numUnos < ((tamano * tamano) / 4) - 1 || numUnos > 3 * ((tamano * tamano) / 4)) return false;
		//else {
			bool sol;
			int num1, num2, num3, num4;
			sol = recursion(v, esqArribaX, esqArribaY, esqAbajoX - (tamano / 2), esqAbajoY - (tamano / 2), num1);
			if (sol) {
				sol = recursion(v, esqArribaX + (tamano / 2), esqArribaY, esqAbajoX, esqAbajoY - (tamano / 2), num2);
				if (sol) {
					sol = recursion(v, esqArribaX, esqArribaY + (tamano / 2), esqAbajoX - (tamano / 2), esqAbajoY, num3);
					if (sol) {
						sol = recursion(v, esqArribaX + (tamano / 2), esqArribaY + (tamano / 2), esqAbajoX, esqAbajoY, num4);
						if (sol && abs(num1 - num2) < 3 && abs(num1 - num3) < 3 && abs(num1 - num4) < 3 && abs(num2 - num3) < 3 && abs(num2 - num4) < 3 && abs(num3 - num4) < 3) {
							
							numUnos = num1 + num2 + num3 + num4;
							if (numUnos < ((tamano * tamano) / 4) - 1 || numUnos > 3 * ((tamano * tamano) / 4)) return false;
							
							return true;
						}
						else return false;
					}
					else return false;
				}
				else return false;
			}
			else return false;
		//}
	}
}

bool resolver(vector<vector<int>> v)
{
	int numUnos;
	//Resuelve el problema
	return recursion(v, 0, 0, v.size() - 1, v.size() - 1, numUnos);
}

//Analisis del coste:
//-------------------

// Tamano de los datos de entrada: n => (esqAbajoX - esqArribaX) + 1
// Ecuaciones de recurrencia: T(n) = { c0                  para n = 1;
//                                   { c1 + n^2 + 4 * T(n/2) para n > 1;

// Por tanto el coste es de O(n^2 * logn)

void resuelveCaso() {
	int dim = 0;
	std::cin >> dim;
	std::vector<vector<int>> v(dim, vector<int>(dim));
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			cin >> v[i][j];
	if (resolver(v))
		cout << "SI\n";
	else
		cout << "NO\n";
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
	return 0;
}