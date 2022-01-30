#include <iostream>
#include <vector>
using namespace std;

typedef int tAltura[1000];


int main(){
	vector<int> a;
	int cont,b,x,max;
	cin >> cont;
	while (cont > 0){
		x = 0;
		for(int i=0;i<cont;i++){
			cin >> b;
			a.push_back(b);
		}
		if (!a.empty()) {
			x++;
			max = a.back();
			for (int i = cont - 2; i >= 0; i--) {
				if (a.at(i) > max) {
					x++;
					max = a.at(i);
				}
			}
		}
		cout << x << endl;
		a.clear();
		cin >> cont;
	}

	return 0;
}