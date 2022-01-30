#include <iostream>

using namespace std;

long long int digitos(long long int n) {
	int cont = 0;
	while (n > 0) {
		cont++;
		n /= 10;
	}
	return cont;
}

bool recursion(long long int n) {
	int NumD = digitos(n);
	if (n % NumD == 0) {
		if (NumD > 1)
			return true && recursion(n / 10);
		else
			return true;
	}
	else
		return false;
}

int main() {
	long long int num;
	bool b;
	while (cin >> num) {
		b = recursion(num);
		if (b)cout << "POLIDIVISIBLE" << endl;
		else cout << "NO POLIDIVISIBLE" << endl;
	}
	return 0;
}