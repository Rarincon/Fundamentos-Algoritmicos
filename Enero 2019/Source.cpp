#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Ejercicio 3
#define MAX 10000
//Ya esta hecho EContaAC06

void resuelve() {
	int sol, N;
	sol = 0;
	int v[MAX];
	//vector<int>v;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> v[i];
	//dv(v, 0, N - 1, sol);
	cout << sol << endl;
}

int main() {
	int casos, i;
	i = 0;
	cin >> casos;
	while (i < casos) {
		resuelve();
		i++;
	}
	return 0;
}


/*
//Ejercicio 2
#define MAX 10000

void dv(const int v[], int ini, int fin,int &sol) {
	int mitad;
	if (fin == ini) {
		if (v[ini] == 0)sol += 1;
	}
	else if (v[fin] == 0) {
		mitad = (ini + fin) / 2;
		if (v[mitad] == 0) {
			sol += fin - mitad;
			dv(v, ini, mitad, sol);
		}
		else
			dv(v, mitad+1, fin, sol);
	}
}

void resuelve() {
	int sol, N;
	sol = 0;
	int v[MAX];
	//vector<int>v;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> v[i];
	dv(v, 0, N-1,sol);
	cout << sol << endl;
}

int main() {
	int casos, i;
	i = 0;
	cin >> casos;
	while (i < casos) {
		resuelve();
		i++;
	}
	return 0;
}*/

/*
//Ejercicio 1
//N>=0
//fun(v[N])devulve entero s
//s=(max p,q: 0<=p<q<=N : v[p]+1==v[q] || v[p]-1==v[q])

//T=N-i


#define MAX 10000
//const int MAX = 100;
 
int funcion(const int v[], int N) { //const vector<int>& v
	int cont, aux,i;
	aux = 1;
	i = 0;
	cont = 0;
	if (N > 0) {
		cont = aux;
		while (i < N - 1) {
			if ((v[i] + 1 == v[i + 1]) || (v[i] - 1 == v[i + 1])) {
				aux++;
				if (aux > cont)cont = aux;
			}
			else
				aux = 1;
			i++;
		}
	}
	return cont;
}

void resuelve() {
	int sol,N;
	int v[MAX];
	//vector<int>v;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sol = funcion(v, N);
	cout << sol << endl;
}

int main() {
	int casos,i;
	i = 0;
	cin >> casos;
	while (i < casos){
		resuelve();
		i++;
	}
	return 0;
}
*/