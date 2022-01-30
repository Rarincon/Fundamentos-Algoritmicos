#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

long long int divide_venceras(vector<long long int>& v, long long ini, long long fin) {
	long long int m, aux, i, j, k, tam, sol;
	vector <long long int> c;

	//Casos base
	if (ini == fin) {
		sol = 0;
	}
	else if ((fin - ini) == 1) {
		sol = 0;
		if (v[ini] > v[fin]) {
			sol++;
			aux = v[ini];
			v[ini] = v[fin];
			v[fin] = aux;
		}
	}

	//Caso Recursivo
	else {
		m = (ini + fin) / 2;
		tam = fin - ini + 1;
		c.resize(tam);
		i = 0;
		j = ini;
		k = m + 1;
		sol = divide_venceras(v, ini, m) + divide_venceras(v, m + 1, fin);

		while ((j <= m) && (k <= fin)) {
			if (v[j] <= v[k]) {
				c[i] = v[j];
				j++;
			}
			else {
				c[i] = v[k];
				sol += abs(ini + i - k);
				k++;
			}
			i++;
		}

		while (j <= m) {
			c[i] = v[j];
			j++;
			i++;
		}
		while (k <= fin) {
			c[i] = v[k];
			sol += abs(ini + i - k);
			k++;
			i++;
		}

		for (i = 0; i < tam; i++) {
			v[ini + i] = c[i];
		}
	}
	return sol;
}

//Analisis del coste
//Tamaño de datos: el numero de elementos que hay en el vector v, diremos que es n, siendo 0<=n<=100000
//T(n){ c0(constante acumulativa) si n= 1 ó n=2
//	  { c1(constante acumalativa)+ 2T(n/2) si n != 1 ó 2
// En el caso de que el tamaño del vector sea 0, osea n=0, no se accede al algoritmo de divide y venceras
//El coste del del caso recursivo es 2T(n/2), por tanto el coste del orden de O(N log(N)) osea nLogn

void resuelveCaso() {

	long long int num, aux;
	vector<long long int> v;

	//Lee los datos
	cin >> num;

	//Calcula el resultado
	if (num == 0) {
		cin.get();
		cout << "0\n";
	}
	else {
		for (long long int i = 0; i < num; ++i) {
			cin >> aux;
			v.push_back(aux);
		}
		aux = divide_venceras(v, 0, v.size() - 1);
		cout << aux << "\n";
	}

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
#endif

	return 0;
}