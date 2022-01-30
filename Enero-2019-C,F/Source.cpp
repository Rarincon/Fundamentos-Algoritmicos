#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;

int problema1(const vector<int>& a, const int& N) {
	if (N <= 0)
		return 0;
	int i = 0, mejor = 1, cont = 1;
	while (i <= N - 2) {
		if ((a.at(i) + 1) == a.at(i + 1) || (a.at(i) - 1) == a.at(i + 1)) {
			cont++;
			if (cont > mejor)mejor = cont;
		}
		else
			cont = 1;
		i++;
	}
	return mejor;
}

void resuelve() {
	int N, b;
	vector<int> a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a.push_back(b);
	}
	cout << problema1(a, N) << endl;
}

/*int problema2(const vector<int>& a, int ini, int fin) {
	if (ini == fin) {
		if (a.at(ini) == 1)return ini + 1;
		else return ini;
	}
	else {
		int m = (ini + fin) / 2;
		if (a.at(m) == 1)return problema2(a, m + 1, fin);
		else return problema2(a, ini, m);
	}
}

void resuelve() {
	int N,b;
	vector<int> a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a.push_back(b);
	}
	if (N > 0) {
		int sol = problema2(a, 0, N - 1);
		cout << N - sol << endl;
	}
	else cout << 0 << endl;
}*/

/*
bool toca(const int& i, const int& k,const int vet[MAX][MAX], const int sol[MAX]) {
	if (k > 0) {
		if (vet[i][sol[k - 1]] == 1)return true;
		else return false;
	}
	else return true;
}

void prob3(const int& N, const int don[MAX][MAX], const int vet[MAX][MAX], int& benef, bool& acuerdo, bool toc[MAX], int suma, int k, int sol[MAX]) {
	for (int i = 0; i < N; i++) {
		if (toca(i, k, vet,sol) && !toc[i]) {
			toc[i] = true;
			sol[k] = i;
			suma += don[i][k];
			if (k == N - 1) {
				if (suma > benef)benef = suma;
				acuerdo = true;
			}
			else prob3(N, don, vet, benef, acuerdo, toc, suma, k + 1, sol);
			toc[i] = false;
			suma -= don[i][k];
		}
	}
}

void problema3(const int& N, int don[MAX][MAX], int vet[MAX][MAX]) {
	int benef;
	bool acuerdo=false;
	bool toc[MAX];
	int sol[MAX];
	for (int i = 0; i < N; i++)toc[i] = false;
	prob3(N, don, vet, benef, acuerdo, toc, 0, 0,sol);
	if (!acuerdo)cout << "NEGOCIA CON LOS ARTISTAS" << endl;
	else cout << benef<<endl;
	
}

void resuelve() {
	int N;
	cin >> N;
	int don[MAX][MAX];
	int vet[MAX][MAX];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> don[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> vet[i][j];
	}
	problema3(N, don, vet);
}*/

int main() {
	int casos,i=0;
	cin >> casos;
	while (i < casos) {
		resuelve();
		i++;
	}
}