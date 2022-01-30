#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;

//Hasta los cojones de que no cuente bn lo que debe, no esta bn

int particion(int a[], int ini, int fin, int& p) {
	int i, j,aux,aux2,suma=0;
	j = fin;
	i = ini + 1;
	while (i <= j) {
		if (a[i] > a[ini] && a[j] < a[ini]) {
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			suma += (j - i + 1);
			j--;
			i++;
		}
		else {
			if (a[i] <= a[ini])i++;
			if (a[j] >= a[ini])j--;
		}
	}
	//for (int i = 0; i < 3; i++) cout << a[i] << " ";
	//cout << endl;
	p = j;
	aux = a[ini];
	aux2= a[p];
	a[ini] = a[p];
	a[p] = aux;
	if (a[ini] != a[p]) {
		if((ini+1)!=p)
			suma += p - ini + 1;
		else
			suma += p - ini;

	}
	//for (int i = 0; i < 3; i++) cout << a[i] << " ";
	//cout << endl;
	return suma;
}

int divide(int a[], int ini, int fin) {
	int p,suma=0;
	if (ini <= fin) {
		suma += particion(a, ini, fin, p);
		suma += divide(a, ini, p - 1);
		suma += divide(a, p + 1, fin);
	}
	return suma;
}

bool resuelveCaso() {
	int N, b;
	int a[MAX];
	cin >> N;
	if (!cin)
		return false;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a[i] = b;
	}
	cout << divide(a,0,N-1) << endl;
	//for (int i = 0; i < N; i++) cout << a[i] << " ";
	//cout << endl;
	return true;
}

int main() {
	/*// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */


	while (resuelveCaso())
		;

	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	return 0;
}