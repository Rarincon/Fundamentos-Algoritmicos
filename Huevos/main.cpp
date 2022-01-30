#include <iostream>
using namespace std;

int main()
{
	int h;
	int c;
	do {
		cin >> h >> c;
	} while (h < 0 || c < 0);
	int min=0;
	while (h > 0 && c > 0)
	{
		if (h == 0)
			min = 0;
		else if (h <= c)
			min = 10;
		else {
			int n = h / c;
			if(h%c!=0)
				n++;
			min = 10 * n;
		}
		cout << min<< endl;
		do {
			cin >> h >> c;
		} while (h < 0 || c < 0);
	}
	return 0;
}