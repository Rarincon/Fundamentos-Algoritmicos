#include <iostream>
#include <vector>
using namespace std;

int resuelve(const vector<int>&a, int ini, int fin) {
	int M = (ini + fin) / 2;
	if (ini+1==fin)
		return a.at(ini);
	else {
		if (a.at(M) < a.at(fin)) return resuelve(a, M, fin);
		else return resuelve(a, ini,M);
	}
}

int resuelve2(const vector<int>& a, int N){
	if (a.at(0) > a.at(N - 1))return a.at(N - 1);
	else return resuelve(a, 0, N - 1);
}

/*
int main() {
	int N, b;
	vector<int> a;
	cin >> N;
	if (!cin)return 0;
	while(true){
		for (int i = 0; i < N; i++) {
			cin >> b;
			a.push_back(b);
		}
		cout << resuelve2(a,N) << endl;
		a.clear();
		cin >> N;
		if (!cin)return 0;
	}
	return 0;
}
*/

bool resuelveCaso() {
	int N, b;
	vector<int> a;
	cin >> N;
	if (!std::cin)
		return false;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a.push_back(b);
	}
	cout << resuelve2(a, N) << endl;
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