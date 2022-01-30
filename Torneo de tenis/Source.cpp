#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct sol{
	bool NP;
	int parts;
	int nivel;
};

sol problema2(const vector<string>& jug, const int& P, int ini, int fin) {
	sol Sol,sol1,sol2;
	if (ini == fin) {
		if (jug.at(ini) == "NP")Sol.NP = true;
		else Sol.NP = false;
		Sol.nivel = 0;
		Sol.parts = 0;
	}
	else {
		int m = (ini + fin) / 2;
		sol1 = problema2(jug, P, ini, m);
		sol2 = problema2(jug, P, m+1, fin);
		if (sol1.nivel + 1 <= P) {
			Sol.nivel = sol1.nivel + 1;
			Sol.parts = sol1.parts + sol2.parts;
			if (!sol1.NP && !sol2.NP) {
				Sol.parts++;
				Sol.NP = false;
			}
			else if ((!sol1.NP && sol2.NP) || (sol1.NP && !sol2.NP)) {
				Sol.NP = false;
			}
			else
				Sol.NP = true;

		}
		else {
			Sol.nivel = sol1.nivel + 1;
			Sol.NP = true;
			Sol.parts = sol1.parts+ sol2.parts;
		}
	}
	return Sol;
}

int problema(const int& N, const int& P, const vector<string>& jug) {
	sol Sol;

	Sol = problema2(jug, P, 0, N - 1);
	return Sol.parts;
}

bool resuelve() {
	int N, P;
	string b;
	cin >> N;
	if (!cin) return false;
	cin>> P;
	vector<string>jug;
	for (int i = 0; i < N; i++) {
		cin >> b;
		jug.push_back(b);
	}
	cout << problema(N,P,jug) << endl;
	return true;
}

int main() {

	while (resuelve());

	return 0;
}