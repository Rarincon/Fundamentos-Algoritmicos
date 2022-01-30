#include <iostream>
#include <vector>
using namespace std;

bool divide(const vector<int> & a, const vector<int>& b, int ini, int fin, int &pos1, int &pos2 ) {
	if (ini == fin) {
		if (a.at(ini) == b.at(ini)) {
			pos1 = pos2=ini;
			return true;
		}
		else {
			if (ini == a.size() - 1) {
				pos1 = ini;
				pos2 = pos1 + 1;
			}
			else {
				pos1 = ini - 1;
				pos2 = ini;
			}
			return false;
		}
	}
	else {
		int m = (ini + fin) / 2;
		if (a.at(m) < b.at(m))return divide(a, b, m + 1, fin, pos1, pos2);
		else return divide(a, b, ini, m, pos1, pos2);
	}
}

bool resuelveCaso() {
	int N, c,pos1,pos2,i=0;
	vector<int> a, b;
	cin >> N;
	if (N == 0)return false;
	for (int i = 0; i < N; i++) {
		cin >> c;
		a.push_back(c);
	}
	for (int i = 0; i < N; i++) {
		cin >> c;
		b.push_back(c);
	}
	bool ok = divide(a, b, 0, N - 1, pos1, pos2);
	if (ok)cout << "SI " << pos1 << endl;
	else cout << "NO " << pos1 <<" "<< pos2 << endl;
	return true;
}

int main() {
	/*// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */
	
	while (resuelveCaso());

	/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	return 0;
}