#include <iostream>
using namespace std;

void sumdiv(const int& K, int D, int j, int& cont) {
	if (j > K)
		cont = 1;
	else {
		for (int i = 0; i < 10; i++) {
			D += i;
			if ((D % j == 0) && j < K) { sumdiv(K, D, j + 1, cont); }
			else if (D % j == 0 && j == K)
				cont++;
			D -= i;
		}
	}
}

//La poda es D y j, incidicando si D (numero introducido) mas otro numero es divisible por j(inicialmente a 2),
//de ser asi, si j(que es la cantidad de digitos del numoro) es igual a k, habra llegado al final del arbol, sino hara recursion.
//Una vez j==k(siendo la cantidad de digitos que tienen los numoros que queremos) solo habra que comprobar si los numeros son "sumadivisibles"
//El tamaño del problema, en la forma de arbol, esta dividido en k niveles, y cada nivel tiene 10 hijos

void sumdivisibles(int D) {
	int K;
	cin >> K;
	int cont = 0;
	sumdiv(K, D, 2, cont);
	cout << cont<<endl;
}


int main() {
	int D;
	cin >> D;
	while (D > 0) {
		sumdivisibles(D);
		cin >> D;
	}
	return 0;
}