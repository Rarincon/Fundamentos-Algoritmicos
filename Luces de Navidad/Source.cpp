#include <iostream> 
using namespace std;

const int MAX = 100;

struct bomb {
	int cant = 0;
	int pot;
};

bool notres(const int sol[MAX], const int& k) {
	if (k >= 2) {
		if (sol[k] == sol[k - 1] && sol[k - 1] == sol[k - 2])return false;
		else return true;
	}
	else return true;
}

bool cantidades(const int& cant, bomb Bomb[MAX], int k) {
	bool ok=true;
	int total = 0;
	for (int i = 0; i < cant && ok; i++) {
		total = k - Bomb[i].cant;
		if (total < Bomb[i].cant && (Bomb[i].cant-total)>1)ok = false;
	}
	return ok;
}

void problema2(const int& N, const int& cant, const int& lim, bomb Bomb[MAX], int poten, int& cont, int k, int sol[MAX]) {
	for (int i = 0; i < cant; i++) {
		poten += Bomb[i].pot;
		Bomb[i].cant++;
		sol[k] = i;
		if (notres(sol,k) && poten<=lim &&
			cantidades(cant,Bomb,k+1)) {
			if (k == N - 1) {
				cont++;
				//for (int i = 0; i <=k; i++)cout << sol[i] << " ";
				//cout << endl;
			}
			else problema2(N, cant, lim, Bomb, poten, cont, k + 1, sol);
		}
		poten -= Bomb[i].pot;
		Bomb[i].cant--;
	}
}

int problema(const int& N, const int& cant, const int& lim) {
	int b,poten=0,cont=0;
	bomb Bomb[MAX];
	int sol[MAX];
	for (int i = 0; i < cant; i++) {
		cin >> b;
		Bomb[i].pot = b;
	}
	problema2(N, cant, lim, Bomb, poten, cont, 0, sol);
	return cont;
}

bool resuelve() {
	int N, cant, lim;
	cin >> N;
	if (N == 0)return false;
	cin >> cant >> lim;
	cout<<problema(N, cant, lim)<<endl;
	return true;
}

int main(){
	while (resuelve());
}