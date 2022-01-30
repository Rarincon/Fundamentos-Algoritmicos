#include <iostream>
using namespace std;

const int MAX = 100;

int funcion(int cantNum,const int a[MAX],int N, int K) {
	int i, f, x, dist_aux;
	x = cantNum + 1;
	i = 0;
	f = K - 1;
	if (N >= K) {
		while (f < N) {
			dist_aux = a[f] - a[i] + 1;
			if (dist_aux < x)x = dist_aux;
			i++;
			f++;
		}
	}
	return x;
}

int funcion2(int cantNum, const int a[MAX], int N, int K) {
	int i, f, x, dist_aux,cont=1;
	x = cantNum + 1;
	i = 0;
	while (a[i] != 1 && i<N) {
		i++;
	}
	if (i == N)return x;
	if (K == 1)return 1;
	f = i + 1;
	while (f < N) {
		if (cont == K) {
			dist_aux = f - i+1;
			if (dist_aux < x)x = dist_aux;
			i++;
			f++;
			cont--;
		}
		else {
			if (a[f] == 1) {
				cont++;
				if (cont < K)f++;
			}
			else f++;
			if (a[i] != 1 && i < f)i++;
		}
	}
	return x;
}

int main() {
	int cantNum, x, aux, N, K, a[MAX];
	cin >> cantNum;
	while (cantNum >= 0) {
		N = 0;
		for (int i = 0; i < cantNum; i++) {
			cin >> aux;
			if (aux == 1) {
				a[N] = 1;
				
			}
			else {
				a[N] = 0;
			}
			N++;
		}
		cin >> K;
		x = funcion2(cantNum, a, N, K);
		cout << x << endl;
		cin >> cantNum;
	}
	return 0;
}

/*
int main() {
	int cantNum, x,aux,N,K,a[MAX];
	cin >> cantNum;
	while (cantNum >= 0) {
		N = 0;
		for (int i = 0; i < cantNum; i++) {
			cin >> aux;
			if (aux == 1) {
				a[N] = i;
				N++;
			}
		}
		cin >> K;
		x = funcion(cantNum,a,N,K);
		cout <<x << endl;
		cin >> cantNum;
	}
	return 0;
}*/

// {N>=0}
// fun(entero Cantidad_total, a[0...N-1] de enteros, entero K) devuelve x:entero
// x=( Min ini,fin: 0<=ini<fin<N : a[fin] - a[ini] + 1)

//I= 0<=i<f<=N & a[i]<a[f] & x=(Min i,f: ini<=i<f<=fin: a[f] - a[i] + 1)
//T= N-f-1
//O(N) recorre todo el array, para buscar la menor diferencia entre dos valores de dos posiciones