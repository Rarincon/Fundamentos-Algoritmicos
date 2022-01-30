#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;

/*
int problema1(const vector<int>& a, const int& N) {
	int i = 0, cont=0,dist=1, mejor=1;
	if (N == 0)return 0;
	if (N == 1)return 1;
	while (i <= N - 2) {
		if (a[i] >= a[i + 1]) {
			dist++;
			cont = 0;
		}
		else{
			cont++;
			if (cont < 2) 
				dist++;
			else {
				dist = 2;
			}
		}
		if (dist > mejor)mejor = dist;
		i++;
	}
	if (dist > mejor)mejor = dist;
	return mejor;
}

void resuelve() {
	int N,b;
	vector<int>a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> b;
		a.push_back(b);
	}
	cout << problema1(a, N) << endl;
}*/

/*
bool problema2(int a[MAX][MAX], int AX, int AY, int DX, int DY, int & valor) {
	int vIA, vDA, vID, vDD;
	bool ok;
	int tamano = (DX - AX) + 1;
	if (tamano == 1) {
		valor = a[AX][AY];
		return true;
	}
	else {
		ok = problema2(a, AX, AY, DX - (tamano / 2), DY - (tamano / 2), vIA);
		if (ok) {
			ok = problema2(a, AX , AY + (tamano / 2), DX - (tamano / 2), DY, vDA);
			if (ok) {
				ok = problema2(a, AX+ (tamano / 2), AY, DX, DY - (tamano / 2), vID);
				if (ok) {
					ok = problema2(a, AX+ (tamano / 2), AY+ (tamano / 2), DX, DY , vDD);
					if (ok) {
						if ((vIA * vDD) == (vDA * vID)) {
							valor = (vIA * vDD);
							return true;
						}
						else return false;
					}
					else return false;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
}

void resuelve() {
	int N;
	int a[MAX][MAX];
	cin >> N;
	vector<int, vector<int>> b(N, vector<int>(N)); //vector matricial con tamaño
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) 
			cin>>a[i][j];
	}
	int valor;
	if (problema2(a, 0, 0, N-1, N - 1,valor))cout << "SI " << valor << endl;
	else cout << "NO" << endl;
}*/

void resuelve() {

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