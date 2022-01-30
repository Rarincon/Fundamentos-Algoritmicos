#include <iostream>
#include <stack>
using namespace std;

void resuelve(int n) {
	int i=0,j=0,a=1,r;
	if (n == 0) {
		i = 9, j = 9;
	}
	while (n > 0) {
		i *= 10;
		r = 9 - (n % 10);
		i += r;
		j += (r * a);
		a*=10;
		n /= 10;
	}
	cout << j << " " << i << endl;
}

int main() {
	int casos, n,i=0;
	cin >> casos;
	while (i<casos) {
		cin >> n;
		resuelve(n);
		i++;
	}
	return 0;
}