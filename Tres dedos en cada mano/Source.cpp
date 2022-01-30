#include <iostream>
using namespace std;

int recursion(int n) {
	if (n < 6)return n;
	else
		return (n % 6)+ recursion(n / 6)*10;
}

int main() {
	int cant,num, base;
	cin >> cant;
	while (cant > 0) {
		cin >> num;
		base = recursion(num);
		cout << base << endl;
		cant--;
	}
	return 0;
}