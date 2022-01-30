#include <iostream>
#include <vector>
using namespace std;


//ESta mal, falta hacer bn los calculos de ASCII

char resuelve(const vector<char>& a, int ini, int fin, char aux) {
	if (ini == fin) {
		if(ini== a.size())
			return a.at(ini-1)+1;
		else return a.at(ini) -1;
	}
	else {
		int m = (fin + ini) / 2;
		char M = aux + m;
		if (M >= a.at(m))return resuelve(a, m+1, fin, M);
		else return resuelve(a, ini, m, aux);
	}

}

int main() {
	int N, casos, i = 0;
	char b, c,aux;
	vector<char> a;
	cin >> casos;
	while (i < casos) {
		cin >> b >> c;
		aux = b;
		N = c - b + 1;
		for (int j = 1; j < N; j++) {
			cin >> b;
			a.push_back(b);
		}
		c = resuelve(a, 0, N - 1,aux);
		cout << c << endl;
		a.clear();
		i++;
	}
	return 0;
}