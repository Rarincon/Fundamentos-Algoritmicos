#include <iostream>
using namespace std;



bool recursion(int pi, int di, int pd, int dd, int& paux) {
	bool izq = true;
	if (pi == 0) {
		int piI, diI, pdI, ddI;
		cin >> piI >> diI >> pdI >> ddI;
		izq = recursion(piI, diI, pdI, ddI, pi);
	}

	bool dcha = true;
	if (pd == 0) {
		int piD, diD, pdD, ddD;
		cin >> piD >> diD >> pdD >> ddD;
		dcha = recursion(piD, diD, pdD, ddD, pd);
	}

	paux = pi + pd;
	return izq && dcha && pi * di == pd * dd;
}

int main() {
	int pi, di, pd, dd, paux;
	bool b;
	cin >> pi >> di >> pd >> dd;
	while (cin >> pi >> di >> pd >> dd && !(pi == 0 && di == 0 && pd == 0 && dd == 0)) {
		b = recursion(pi, di, pd, dd, paux);
		if (b)cout << "SI" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

//while (cin >> pi >> di >> pd >> dd && !(pi == 0 && di == 0 && pd == 0 && dd == 0))
//cout << (isBalanced(pi, di, pd, dd, paux) ? "SI" : "NO") << endl;

///////////////////////////////////////////////////////

/*
bool recursion(int& pi, int di, int& pd, int dd) {
	int piA, diA, pdA, ddA;
	int b;
	if (pi != 0) {
		if (pd != 0) {
			b = pi * di == pd * dd;
		}
		else {
			cin >> piA >> diA >> pdA >> ddA;
			pd = piA + pdA;
			b= recursion(piA, diA, pdA, ddA) && pi * di == pd * dd;
		}
	}
	else {
		cin >> piA >> diA >> pdA >> ddA;
		b = recursion(piA, diA, pdA, ddA);
		pi = piA + pdA;
		if (pd != 0) 
			b = pi * di == pd * dd && b;
		else {
			cin >> piA >> diA >> pdA >> ddA;
			b = recursion(piA, diA, pdA, ddA) && b;
			pd = piA + pdA;
			b = pi * di == pd * dd && b;
		}
	}
	return b;
}

int main() {
	int pi, di, pd, dd;
	bool b;
	cin >> pi >> di >> pd >> dd;
	while ((pi, di, pd, dd) != 0) {
		b = recursion(pi, di, pd, dd);
		if (b)cout << "SI" << endl;
		else cout << "NO" << endl;
		cin >> pi >> di >> pd >> dd;
	}

	return 0;
}
*/

////////////////////////////////////////////////////////////////////


/*
bool recursion(int & pi, int di, int & pd, int dd) {
	int piA, diA, pdA, ddA;
	int b;
	if (pi != 0) {
		if (pd != 0) {
			b= pi * di == pd * dd;
		}
		else {
			cin >> piA >> diA >> pdA >> ddA;
			if (recursion(piA, diA, pdA, ddA)) {
				pd = piA + pdA;
				b = pi * di == pd * dd;
			}
			else
				b= false;
		}
	}
	else {
		cin >> piA >> diA >> pdA >> ddA;
		if (recursion(piA, diA, pdA, ddA)) {
			pi = piA + pdA;
			if (pd != 0) {
				b = pi * di == pd * dd;
			}
			else {
				cin >> piA >> diA >> pdA >> ddA;
				if (recursion(piA, diA, pdA, ddA)) {
					pd = piA + pdA;
					b = pi * di == pd * dd;
				}
				else
					b = false;
			}
		}
		else
			b = false;
	}
	return b;
}

int main() {
	int pi, di, pd, dd;
	bool b;
	cin >> pi>> di>> pd>> dd;
	while ((pi, di, pd, dd) != 0) {
		b = recursion(pi,di,pd,dd);
		if (b)cout << "SI" << endl;
		else cout << "NO" << endl;
		cin >> pi >> di >> pd >> dd;
	}

	return 0;
}
*/