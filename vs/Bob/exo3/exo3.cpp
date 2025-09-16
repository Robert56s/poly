// Robert Nelea 2449901
// Jia Fournier

#include <iostream>
#include <cmath>
using namespace std;

double exposantPerso(double x,int n) {
	double resultat = 1;
	for (int i = 0; i < n; i++) {
		resultat *= x;
	}
	return resultat;
}

double absolutPerso(double x) {
	if (x >= 0) {
		return x;
	}
	else {
		return (x * -1);
	}
}

double logPerso(double x, double precision) {
	double resultat = 0;

	int i = 1;
	while (true) {
		double n = exposantPerso(x - 1, i) / i;
		resultat += ((i % 2) * 2 - 1) * n;

		if (absolutPerso(n) < precision) {
			return resultat;
		}

		i++;
	}
}

int main() {

	cout << boolalpha;

	double x1 = 1.24, p1 = 1e-5;
	double x2 = 1.35, p2 = 1e-5;
	double x3 = 1.9, p3 = 1e-5;

	cout << (abs(log(x1) - logPerso(x1, p1)) < p1) << endl;
	cout << (abs(log(x2) - logPerso(x2, p2)) < p2) << endl;
	cout << (abs(log(x3) - logPerso(x3, p3)) < p3) << endl;
}