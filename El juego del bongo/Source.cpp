#include <iostream>
#include <vector>
using namespace std;

bool resuelve(const vector<int>& a, int ini, int fin, const int& v, int& n) {
	if (ini == fin) {
		if ((ini +v)== a.at(ini)) {
			n = a.at(ini);
			return true;
		}
		else return false;
	}
	else {
		int m = (ini + fin) / 2;
		if ((m +v) > a.at(m))return resuelve(a, m + 1, fin, v, n);
		else return resuelve(a, ini, m, v, n);
	}
}

void resuelveCaso() {
	int N,b, v,n;
	vector<int> a;
	cin >> N>>v;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a.push_back(b);
	}
	bool ok= resuelve(a,0,N-1,v,n);
	if (ok)cout << n << endl;
	else cout << "NO" << endl;
}

int main() {
	/*// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */
	int casos, i = 0;
	cin >> casos;
	while (i < casos){
		resuelveCaso();
		i++;
	}

	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	return 0;
}