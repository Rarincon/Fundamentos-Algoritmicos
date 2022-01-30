#include <iostream>
#include <vector>
using namespace std;

/*
//Ejercicio 3

//n carreteras
//m maquinas
const int Max = 50;
const int MAX = 100;

void vad(int m, int aM[Max], int n, int aN[Max],const int c[MAX][MAX], int k, bool marcaM[Max], bool marcaN[Max], int sol, int& solMejor, int est[Max], int &estimaMejor) {
	int solM;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!marcaM[i] && !marcaN[j] && (aM[i] <= aN[j])) {
				marcaM[i] = true;
				marcaN[j] = true;
				sol += c[i][j];
				solM = sol + est[k];
				if (solM > estimaMejor) {
					if (k == m - 1) {
						estimaMejor = sol;
						if (sol > solMejor)solMejor = sol;
					}
					else
						vad(m, aM, n, aN, c, k + 1, marcaM, marcaN, sol, solMejor, est, estimaMejor);
				}
				marcaM[i] = false;
				marcaN[j] = false;
				sol -= c[i][j];
			}
		}
	}
}

void estima(int est[Max], const int c[MAX][MAX], int m, int n) {
	int mejor[Max];
	for (int i = 0; i < m; i++) {
		mejor[i] = c[i][0];
		for (int j = 1; j < n; j++)
			if (mejor[i] < c[i][j])
				mejor[i] = c[i][j];
	}
	est[m - 1] = 0;
	for (int i = m - 2; i >= 0; i--)
		est[i] = mejor[i + 1] + est[i + 1];

}

int va(int m, int aM[Max], int n, int aN[Max], const int c[MAX][MAX]) {
	int sol, solMejor, estimaMejor;
	estimaMejor = -1;
	int est[Max];
	estima(est, c, m, n);
	bool marcaM[Max];
	bool marcaN[Max];
	for (int i = 0; i < m; i++)
		marcaM[i] = false;
	for (int i = 0; i < n; i++)
		marcaN[i] = false;
	sol = 0;
	solMejor = 0;
	
	vad(m, aM, n, aN, c, 0, marcaM, marcaN, sol, solMejor,est, estimaMejor);
	return solMejor;
}

void resulveCaso() {
	int n,m,aM[Max],aN[Max], c[MAX][MAX], sol;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> aM[i];
	for (int i = 0; i < n; i++)
		cin >> aN[i];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> c[i][j];
	sol = va(m, aM, n, aN, c);
	cout << sol << endl;
}

int main() {
	int casos, i;
	i = 0;
	cin >> casos;
	while (i < casos) {
		resulveCaso();
		i++;
	}
	return 0;
}*/

/*

//Ejercicio 2

int recursion( const vector <int>& v, int K, int ini, int fin) {
	int num, resta1,resta2, mitad;
	mitad = (ini + fin) / 2;
	
	if (ini+1 == fin) {
		resta1 = abs(v[mitad] - K);
		resta2 = abs(v[mitad+1] - K);
		if (resta1 < resta2)
			num = v[mitad ];
		else if (resta1 == resta2)
			num = v[mitad];
		else num = v[mitad+1];
	}
	else {
		if(K <= v[mitad])
			num= recursion(v, K, ini, mitad);
		else
			num = recursion(v, K,mitad,fin);
	}
	return num;
}

void resulveCaso() {
	int numero,num, N,sol;
	cin >> numero>>N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	sol = recursion(v,numero,0,N-1);
	cout << sol << endl;
}

int main() {
	int casos, i;
	i = 0;
	cin >> casos;
	while (i < casos) {
		resulveCaso();
		i++;
	}
	return 0;
}*/

/*
//Ejercicio 1
const int MAX = 1000;

int funcion(int v[MAX], int N) {
	int cont,i,aux;
	i = 0;
	cont = 0;
	aux = 1;
	if (N > 0) {
		cont = aux;
		while (i < N-1) {
			if (v[i] >= v[i+1]) {
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

void resulveCaso() {
	int num, v[MAX], pista;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> v[i];
	pista = funcion(v, num);
	cout << pista << endl;
}

int main() {
	int casos,i;
	i = 0;
	cin >> casos;
	while (i < casos) {
		resulveCaso();
		i++;
	}
	return 0;
}*/

//////////////////////////////////////////////
//Enero 2017
//Ejercicio 1, escalones
 
#define MAX 1000

bool funcion(const int v[], int N) {
	bool ok=true;
	int cont, aux, i;
	i = 0;
	aux = 0;
	cont = 1;
	while (i < N-1 && ok) {
		if (v[i] == v[i + 1])
			cont++;
		else {
			if (cont < aux)
				ok = false;
			else {
				aux = cont;
				cont = 1;
			}
		}
		i++;
	}
	if (cont < aux)
		ok = false;
	return ok;
}

void resulveCaso() {
	int N, v[MAX];
	cin >> N;
	while (N > 0) {
		for (int i = 0; i < N; i++)
			cin >> v[i];
		if (funcion(v, N))cout << "SI" << endl;
		else cout << "NO" << endl;
		cin >> N;
	}
}

int main() {
	resulveCaso();
	return 0;
}