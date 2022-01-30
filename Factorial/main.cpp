#include <iostream>
using namespace std;

int main()
{
	int cont;
	cin >> cont;
	int n;
	for (int i = 0; i < cont; i++) {
		cin >> n;
		if (n > 4)
			cout << 0 << endl;
		else if (n == 0)
			cout << 1 << endl;
		else if (n == 4)
			cout << 4 << endl;
		else if(n>0 &&n<=3) {
			int m=1;
			for (int j = 1; j < n+1; j++) 
				m = m * j;
			cout << m << endl;
		}
	}
	return 0;
}