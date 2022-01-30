
#include <iostream>
using namespace std;

void resuelveCaso() {
	int N,picos=0,valles=0,p,s,aux;
	cin >> N;
	if (N > 2) {
		cin >> p>>aux;
		int i = 0;
		while (i < N - 2){
			cin >> s;
			if (p > aux&& aux < s)valles++;
			if (p<aux && aux>s)picos++;
			p = aux;
			aux = s;
			i++;
		}
	}
	else {
		int i = 0;
		while (i < N) {
			cin >> p;
			i++;
		}
	}
	cout << picos << " " << valles << endl;
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