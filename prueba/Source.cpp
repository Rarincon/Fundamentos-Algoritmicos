#include <iostream>
using namespace std;

int main() {
	int v[7] = { 4,10,6,2,11,4,-4 };

	int p, q,r, aux;
	p = 0;
	q = 2;
	r = v[p] - v[p + 1];
	if (r < 0) p = p + 1;
	while (q < 7) {
		aux = v[p] - v[q];
		if (aux > r)r = aux;
		if (v[p] < v[q])p = q;
		q++;
	}
	cout << r << endl;
	return 0;
}

//El coste del algoritmo es lineal en el bucle while, ya que la cota es N-q, siendo N el tamaño del array

//I= 0<=p<q<N : v[p]>v[q]