#include <iostream>
using namespace std;

const int MAX = 100;

void problema2(const int& N, const int& M, int tiendas[MAX][MAX], int tiend[MAX], int &mejor, int suma, int k, int est[MAX]) {
	int efic;
	for (int i = 0; i < N; i++) {
		suma += tiendas[i][k];
		tiend[i]++;
		efic = suma + est[k];
		if (tiend[i]<=3 && efic<mejor) {
			if (k == M - 1) {
				if (suma < mejor)mejor = suma;
			}
			else problema2(N, M, tiendas, tiend, mejor, suma, k + 1, est);
		}
		suma -= tiendas[i][k];
		tiend[i]--;
	}
}

void estimacion(const int a[MAX][MAX], const int& N, const int& M, int est[MAX]) {
	int mejor[MAX];
	for (int i = 0; i < M; i++) {
		mejor[i] = a[0][i];
		for (int j = 1; j < N; j++)
			if (mejor[i] > a[j][i])mejor[i] = a[j][i];
	}
	est[M - 1] = 0;
	for (int i = M - 2; i >= 0; i--) {
		est[i] = est[i + 1] + mejor[i + 1];
	}
}

int peor(const int& N, const int& M, int tiendas[MAX][MAX]) {
	int p, peor = 0;
	for (int i = 0; i < M; i++) {
		p = tiendas[0][i];
		for (int j = 1; j < N; j++)
			if (p < tiendas[j][i])p = tiendas[j][i];
		peor += p;
	}
	return peor;
}

int problema(const int& N, const int& M, int tiendas[MAX][MAX]) {
	int tiend[MAX];
	int est[MAX];
	for (int i = 0; i < N; i++)tiend[i] = 0;
	int mejor = peor(N, M, tiendas);
	estimacion(tiendas, N, M, est);
	problema2(N, M, tiendas, tiend, mejor, 0, 0, est);
	return mejor;
}

bool resuelve() {
	int N, M;
	int tiendas[MAX][MAX];
	cin >> N>>M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> tiendas[i][j];
	cout << problema(N,M, tiendas) << endl;
	return true;
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