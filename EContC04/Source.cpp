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
#include <cmath>

using namespace std;

//Implementa aqui tu funcion recursiva
bool divide_venceras(const vector <int>& v, int ini, int fin, int& max, int& min)
{
	if (ini == fin) { //v.size()==1
		min = v[ini];
		max = v[ini];
		return true;
	}
	/*else if (ini == fin - 1) {
		if (v[ini] <= v[fin]) {
			min = v[ini];
			max = v[fin];
			return true;
		}
		else {
			min = v[fin];
			max = v[ini];
			return false;
		}
	}*/
	else {
		int mitad = (ini + fin) / 2;
		int max1, min1, max2, min2;
		bool b1, b2, b;
		b1 = divide_venceras(v, ini, mitad, max1, min1);
		b2 = divide_venceras(v, mitad + 1, fin, max2, min2);
		b = b1 && b2;
		if (max1 > max2 && !b) return false;
		else max = max2;
		if (min1 <= min2 && b) min = min1;
		else return false;
		return b;
	}
}


//Analisis del coste: escribe la recurrencia e indica a que orden de complejidad pertenece la solucion de la misma

//El orden de complejidad es de n siendo n = fin - ini + 1
//Con una ecuacion de recurrencia de la forma:
//		 T(n) = {c0 			para n = 1, 2
//				{2*T(n/2) + c1  para n > 2
//Utilizando la formula de los costes con a = 2, b = 2 y k = 0 (a > b^k)
//nos sale que el coste del algoritmo es de O(n^log_2(2)) = O(n^1) = O(n);


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta

bool resuelveCaso() {
	int num;
	std::cin >> num;
	if (num == 0) return false;
	std::vector<int> v;
	while (num != 0) {
		v.push_back(num);
		std::cin >> num;
	}

	bool ok;
	int max, min;
	//INVOCA AQUI A TU FUNCION RECURSIVA
	ok = divide_venceras(v, 0, v.size() - 1, max, min);

	if (ok) std::cout << "SI" << '\n';
	else std::cout << "NO\n";
	return true;

}

int main() {
	/*
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/

	while (resuelveCaso());

	/*
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif*/
	return 0;
}