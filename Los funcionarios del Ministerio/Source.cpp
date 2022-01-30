#include <iostream>
using namespace std;

const int MAX = 100;

void divide2(const int a[MAX][MAX], const int& N, bool trab[MAX], int k, int sum, int& tiem, int est[MAX]) {
	int estimac;
	for (int i = 0; i < N; i++) {
		if (!trab[i]) {
			trab[i] = true;
			sum += a[k][i];
			estimac = sum + est[k];
			if (estimac < tiem) {
				if (k == (N - 1)) {
					if (sum < tiem)tiem = sum;
				}
				else
					divide2(a, N, trab, k + 1, sum, tiem, est);
			}
			trab[i] = false;
			sum -= a[k][i];
		}
	}
}

void estimacion(const int a[MAX][MAX], const int& N, int est[MAX]) {
	int mejor[MAX];
	for (int i = 0; i < N; i++) {
		mejor[i] = a[i][0];
		for (int j = 1; j < N; j++)
			if (mejor[i] > a[i][j])mejor[i] = a[i][j];
	}
	est[N - 1] = 0;
	for (int i = N - 2; i >= 0; i--) {
		est[i] = est[i + 1] + mejor[i + 1];
	}
}

int peor(const int a[MAX][MAX], const int& N) {
	int aux=0, peor = 0;
	for (int i = 0; i < N; i++) {
		aux = 0;
		for (int j = 0; j < N; j++)
			if (a[i][j] > aux) aux = a[i][j];
		peor += aux;
	}
	return peor;
}

int divide(const int a[MAX][MAX], const int& N) {
	bool trab[MAX];
	int est[MAX];
	for (int i = 0; i < N; i++)
		trab[i] = false;
	int tiem=peor(a,N);
	estimacion(a, N, est);
	divide2(a, N, trab, 0, 0, tiem, est);
	return tiem;
}

bool resuelveCaso() {
	int N;
	int a[MAX][MAX];
	cin >> N;
	if (N <= 0)return false;
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++) 
			cin >> a[i][j];
	cout << divide(a, N)<<endl;

	return true;
}

int main() {
	while (resuelveCaso());
}