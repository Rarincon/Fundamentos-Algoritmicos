#include <iostream>
using namespace std;

/*
//Ejercicio 1
bool resolver(int N) {
	bool ok=true;
	int d = 10;
	int u, p;
	while (N > 10 && ok) {
		u = N % d;
		N /= 10;
		p = N % (d);
		if (u == p)
			ok = false;	
	}

	return ok;
}

int main(){
	int num;
	cin >> num;
	while (num >= 0) {
		if (resolver(num))
			cout << "Entretenido" << endl;
		else
			cout << "No entretenido" << endl;
		cin >> num;
	}

	return 0;
}
*/

//Ejercicio 3

void btd(int n, int d, int k, int K, int numero, int suma, int& cont) {
	d = d * 10;
	for (int i = 0; i < 10; i++) {
		if (numero != i && (suma + i) <= k) {
			suma += i;
			d = d + i;
			if (K == n - 1)
				cont++;
			else
				btd(n, d, k, K + 1, i, suma, cont);
			suma -= i;
			d = d - i;
		}
	}
}

void bt(int n, int d, int k) {
	int suma = d;
	int cont = 0;
	if (n == 1)cont = 1;
	else
		btd(n, d, k, 1 ,d, suma,cont);
	cout << cont << endl;
}

void resolver(int n) {
	int d, k,suma;
	suma = 0;
	cin >> d >> k;
	bt(n, d, k);
}

int main() {
	int n;
	cin >> n;
	while (n >=0) {
		resolver(n);
		cin >> n;
	}

	return 0;
}