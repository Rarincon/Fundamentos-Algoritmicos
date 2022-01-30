#include <iostream>

using namespace std;

int recursion(int num) {
	if (num == 0)return 0;
	if (num == 1)return 4;
	else
		 return num*4+4*recursion(num / 2);
}

int main() {
	int num;
	
	while (cin >> num) {
		num = recursion(num);
		cout << num << endl;
	}

	return 0;
}