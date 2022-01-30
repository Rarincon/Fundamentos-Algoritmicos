// Grupo: A 
// Nombre del alumno Raúl Rincon de Andrés
// Usuario del Juez: A23

#include <iostream>
#include <vector>
using namespace std;

bool problema3(const vector<int>& array, const int& N, int p ){
	int min;
	if (p + 1 >= array.size())return true;
	else {
		min = array[p + 1];
		for (int i = p + 2;i<array.size();i++){
			if (array[i] < min)min = array[i];
		}
		for (int i = 0; i <= p; i++) {
			if (array[i] >= min)return false;
		}
	}
	return true;
}

void resuelveCaso() {
	int N,n,p;
	cin >>N>> p;
	vector<int> a;
	for (int i = 0; i < N; i++) {
		cin >> n;
		a.push_back(n);
	}
	if (problema3(a, N, p))cout << "SI" << endl;
	else cout << "NO" << endl;
}


int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif*/

	int n;
	cin >> n;
	while (n > 0) {
		resuelveCaso();
		n--;
	}

	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	return 0;
}