#include <iostream>
using namespace std;

int resuelve(int n) {
	int r,s=0;
	while (n > 0) {
		s *= 10;
		r = n % 10;
		s += r;
		n /= 10;
	}
	return s;
}

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		cout << resuelve(n) << endl;
		cin >> n;
	}
	return 0;
}