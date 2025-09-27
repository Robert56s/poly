/**
 * Programme qui calcule une approximation du logarithme naturel
 * à l'aide d'une série, et compare le résultat avec la fonction log().
 * \file   exo3.cpp
 * \author Jia Fournier 2278978 et Robert Nelea 2449901
 * \date   18 septembre 2025
 */

#include <iostream>
#include <cmath>
using namespace std;

double exposantPerso(double x, int n) {
    double resultat = 1.0;
    for (int i = 0; i < n; i++) {
        resultat *= x;
    }
    return resultat;
}

double absolutPerso(double x) {
    if (x >= 0.0) {
        return x;
    } else {
        return x * -1.0;
    }
}

double logPerso(double x, double precision) {
    double resultat = 0.0;
    int i = 1;

    int iterationLimite = 1000000;
    while (i < iterationLimite) {
		double xMoins1 = x - 1.0;
        double terme = exposantPerso(xMoins1, i) / i;
        // (-1)^(i+1) : si i est impair -> +1, si pair -> -1
        resultat += ((i % 2) * 2 - 1) * terme;

        if (absolutPerso(terme) < precision) {
            return resultat;
        }
        i++;
    }
}

int main() {
    cout << boolalpha;

    double x1 = 1.24;
    double p1 = 1e-5;
    double x2 = 1.35;
    double p2 = 1e-5;
    double x3 = 1.9;
    double p3 = 1e-5;

    cout << (abs(log(x1) - logPerso(x1, p1)) < p1) << endl;
    cout << (abs(log(x2) - logPerso(x2, p2)) < p2) << endl;
    cout << (abs(log(x3) - logPerso(x3, p3)) < p3) << endl;

    return 0;
}
