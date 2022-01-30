#include <iostream>
#include <vector>
using namespace std;

const int MAX =20;

bool divide(const int a[MAX][MAX], const int& k, int ini, int fin, int &suma) {
	if (ini == fin) {
		suma = a[k][ini];
		return true;
	}
	else {
		int m = (ini + fin) / 2;
		int sum1, sum2;
		bool ok1, ok2;
		ok1 = divide(a, k, ini, m, sum1);
		ok2 = divide(a, k, m + 1, fin, sum2);
		if (ok1 && ok2) {
			suma = sum1 + sum2;
			if (sum1 < sum2)return true;
			else return false;
		}
		else {
			suma = sum1 + sum2;
			return false;
		}
	}
}

bool resuelveCaso() {	
	int fil,col,b,suma,k=0;
	bool ok = true;
	int a[MAX][MAX];
	cin >> fil;
	if (!cin)
		return false;
	cin >> col;
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			cin >> b;
			a[i][j] = b;
		}
	}
	while (k < fil && ok) {
		ok = divide(a, k, 0, col - 1, suma);
		k++;
	}
	if (ok)cout << "SI" << endl;
	else cout << "NO" << endl;
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