#include <iostream>
#include <string> 
using namespace std;

int sumDigits(int K, int numdigits) {
	int sum = 0;
	int i = 0;
	while (i < numdigits) {
		sum += K % 10;
		K /= 10;
		i++;
	}
	return sum;
}

int contDigits(int k) {
	int cont = 0;
	while (k > 0) {
		cont++;
		k /= 10;
	}
	return cont;
}

bool recursion2(int K, int suma, int digits) {
	if (digits == 1)return true;
	if (suma % digits == 0) {
		int last = K % 10;
		suma -= last;
		return recursion2(K / 10, suma, digits - 1);
	}
	else return false;
}


bool recursion(int K) {
	bool ok;
	int digits = contDigits(K);
	int sumdigits = sumDigits(K, digits);
	if (digits == 1)ok = true;
	else {
		ok = recursion2(K, sumdigits,digits);
	}
	return ok;
}


/*
bool recursion(int K) {
	bool ok;
	int digits = contDigits(K);
	int sumdigits = sumDigits(K, digits);
	if (digits == 1)ok = true;
	else {
		if (sumdigits % digits == 0)
			ok = recursion(K / 10);
		else
			ok = false;
	}
	return ok;
}*/

// Tamaño de los datos de entrada n=numero de digitos del numero
// T(n){c1 si n=1
//	   {c2 + T(n-1) si n>1
// Coste de la funcion de O(n), lineal

int main() {

	int num;
	cin >> num;
	while (num > 0) {
		if (recursion(num))
			cout << "Si" << endl;
		else cout << "No" << endl;
		cin >> num;
	}
	return 0;
}