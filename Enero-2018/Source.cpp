#include <iostream>
#include <vector>
using namespace std;

int solucion1(const vector<int>& a, const int& N) {
	if (N == 0)return 0;
	int i=0,aux=1, cont = 1;
	while (i < N - 1) {
		if (a.at(i) >= a.at(i + 1)) {
			aux++;
			if (cont < aux)cont = aux;
		}
		else aux = 1;
		i++;
	}
	return cont;
}

int solucion2(const vector<int>& a,const int & ini, const int& fin, const int& n) {
	if (ini == fin - 1) {
		if(abs((a.at(ini)-n))<= abs((a.at(fin) - n)))return a.at(ini);
		else return a.at(fin);
	}
	else{
		int m = (ini + fin) / 2;
		if (n <= a.at(m))return solucion2(a,ini,m,n);
		else return solucion2(a,m,fin,n);
	}
}

int main() {
	int casos,n,N,b, i=0;
	vector<int> a;
	cin >> casos;
	while (i < casos) {
		cin >>n>> N;
		for(int j=0;j<N;j++){
			cin >> b;
			a.push_back(b);
		}
		cout << solucion2(a,0, N-1, n) << endl;
		a.clear();
		i++;
	}
	return 0;
}