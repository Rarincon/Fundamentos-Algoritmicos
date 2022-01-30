#include <iostream>

using namespace std;

bool dalton() {
	int n, i;
	long long int dalton1, dalton2;
	bool asc, desc;
	asc = true;
	desc = true;
	cin >> n;
	if (n == 0)
		return false;
	else {
		cin >> dalton1;
		i = 1;
		while (i < n) {
			cin >> dalton2;
			asc = asc && (dalton2 > dalton1);
			desc = desc && (dalton2 < dalton1);
			i++;
			dalton1 = dalton2;
		}
		if (asc || desc)
			cout << "DALTON" << endl;
		else
			cout << "DESCONOCIDOS" << endl;

		return true;
	}
}

int main()
{
	while (dalton())
	{
	}
	return 0;
}


