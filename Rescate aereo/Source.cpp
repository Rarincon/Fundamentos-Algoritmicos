#include <iostream>
#include <vector>
using namespace std;

void resuelve(const vector<int>& a,const int & nav,const int & N, int& ini, int& fin) {
	int i = 0;
	ini = -1;
	fin = -1;
	while (a.at(i) < nav && i < N) {
		i++;
	}
	for (int j = i + 1; j < N; j++) {
		if (a.at(j) >= nav) {
			if ((fin - ini) < (j - i)) { ini = i; fin = j; }
		}
		else {
			i = j + 1;
			while(i < N && a.at(i) < nav) i++;
			j = i;
		}
	}
}

int main() {
	int casos,edif,b,ini,fin, nav,k=0;
	vector<int> a;
	cin >> casos;
	while (k < casos) {
		cin >> edif;
		cin >> nav;
		for (int i = 0; i < edif; i++) {
			cin >> b;
			a.push_back(b);
		}
		resuelve(a, nav,edif, ini, fin);
		cout << ini << " " << fin << endl;
		a.clear();
		k++;
	}
	return 0;
}