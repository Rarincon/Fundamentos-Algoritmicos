#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;

void problema2(const int& M, const int& C, int niev[MAX][MAX], const vector<int> & m, const vector<int> & c , int & nieve, bool car[MAX], int suma, int k) {
	for (int i = 0; i < C;i++) {
		if (!car[i] && m.at(k) <= c.at(i)) {
			suma += niev[k][i];
			car[i] = true;
			if (k == M - 1) {
				if (suma > nieve)nieve = suma;
			}
			else problema2(M, C, niev, m, c, nieve, car, suma, k+1);
			suma -= niev[k][i];
			car[i] = false;
		}
	}
}

int problema(const int& M, const int& C,  int niev[MAX][MAX], const vector<int> & m, const vector<int> & c) {
	int nieve = 0;
	bool car[MAX];
	for (int i = 0; i < C; i++) car[i] = false;
	problema2(M, C, niev, m , c, nieve, car, 0, 0);
	return nieve;
}

void resuelve() {
	int M, C,b;
	cin >> M >> C;
	vector<int>m;
	vector <int>c;
	int niev[MAX][MAX];
	for (int i = 0; i < M; i++) {
		cin >> b;
		m.push_back(b);
	}
	for (int i = 0; i < C; i++) {
		cin >> b;
		c.push_back(b);
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < C; j++) {
			cin >> b;
			niev[i][j]=b;
		}
	}
	cout << problema(M, C, niev, m, c)<<endl;
}

int main() {
	int casos, i = 0;
	cin >> casos;
	while (i < casos) {
		resuelve();
		i++;
	}
	return 0;
}