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
#include <math.h>

using namespace std;


//Define aquí la función recursiva
bool recursion(const vector<int>& v, int K, int ini, int fin) {
	if (ini == fin)return true;
	else {
		int m = (ini + fin) / 2;
		return  (abs(v[ini] - v[fin])>= K) && recursion(v, K, ini, m) && recursion(v, K, m + 1, fin);

	}
}

//Analisis y justificacion del coste
//T(n) { T(0)= constante c0
//		 T(num)= constante c1 *x+ 2T(num/(2^x)
// En nuestro algoritmo c1 = 9, y x= una variable que va aumentando con cada llamada, similar al del campesino egipcio

//El coste del algoritmo es de log(num) es de O(log n) donde n= num


// Al parecer es lineal, pues al final mirar todos los numeros del vector, esta es la solucion correcta

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int num; 
	std::cin >> num;
	if (!std::cin)return false;
	int K;
	std::cin >> K;
	std::vector<int> v(num);
	for (int& n : v) cin >> n;
	
	bool b;

	//LLAMA/INICIA aqui a tu funcion recursiva
	b = recursion(v,K,0,num-1);
	
	if (b) std::cout << "SI\n";
	else std::cout << "NO\n";
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
	#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	while (resuelveCaso());

	// restablecimiento de cin

#ifndef DOMJUDGE
	std::cin.rdbuf(cin.rdbuf);
	//system("PAUSE");
#endif 

	return 0;
}