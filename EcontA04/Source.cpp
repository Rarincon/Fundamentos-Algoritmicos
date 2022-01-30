#include <iostream> 
#include <vector>
using namespace std;

//No lo saco

int problema(const vector<int>& a, int ini, int fin) {
	if (ini == fin)return a.at(ini);
	else {
		int m = (ini + fin) / 2;
		int valor = (a.at(m) - a.at(ini));
		if (valor % 2 != 0) {
			if (a.at(m) % 2 == 0)return a.at(ini);
			else return a.at(m);
		}
		else {
			valor /= 2;
			if (valor == m)return  problema(a, m + 1, fin);
			else return problema(a, ini, m);
		}
	}
}

bool resuelve() {
	int N, b;
	vector<int> a;
	cin >> N;
	if (!cin)return false;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a.push_back(b);
	}
	cout << problema(a, 0, N - 1) << endl;

	return true;
}

int main() {
	while (resuelve());
	return 0;
}