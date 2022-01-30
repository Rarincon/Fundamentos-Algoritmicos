#include <iostream>
#include <vector>
using namespace std;

int problema1(const int& N, const vector<int>& a) {
	//if (N <= 0)return 0;
	int cont = 1, mejor = 0, i=0;
	while (i <= N-2) {
		if (a.at(i) >= a.at(i + 1)) {
			cont++;
			if (mejor < cont)mejor = cont;
		}
		else cont = 1;
		i++;
	}
	if (mejor < cont && N>0)mejor = cont;
	return mejor;
}

int problema2(const vector<int>& a, const int & n, int ini, int fin) {
	if (ini+1 == fin) {
		if (abs(a.at(ini) - n) <= abs(a.at(fin) - n))return a.at(ini);
		else return a.at(fin);
	}
	else {
		int m = (ini + fin) / 2;
		if (a.at(m)>=n)return problema2(a, n, ini, m);
		else return problema2(a, n, m, fin);
	}
}

void resuelve() {
	int N,b,n;
	cin >> n>>N;
	vector<int>a;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a.push_back(b);
	}
	if (N > 1)
		cout << problema2(a, n, 0, N - 1) << endl;
	else cout << a.at(0)<<endl;
}

int main() {
	int casos, i = 0;
	cin >> casos;
	while (i < casos) {
		resuelve();
		i++;
	}
}