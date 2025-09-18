#include <iostream>
using namespace std;

//COMMENT FAIRE UNE FONCTION?? METTRE DES DOUBLE ET DES INT ENSEMBLE? I'M CONFUSED

//Fonction exponentielle
double exponentielle(double x, double n) {
	double resultat = 0.0;
	n = 1;
	double i = 0.0;
	while (i < n) {
		resultat *= x;
		i++;
	}
	return resultat;
};

//Fonction valeur absolue
double valeur_absolue(double x) {
	if (x >= 0) {
		return x;
	}
	else {
		return x *= -1;
	}
};

//Fonction logarithmique
double logarithmique(double x, double precision) {
	int resultat = 0;
	bool boucle = true;
	int i = 1;

	while (boucle) {
		double n = exponentielle((x - 1), i);
		double resultat = resultat + (((i % 2) * 2 - 1) * n);

		if (valeur_absolue(n) < precision) {
			return resultat;
		}

		i++;

	}

};

int main() {
	cout << "Entrer x: ";
	double x;
	cin >> x;

	if (x < 0 || x > 2) {
		cout << "Entrer un nombre valide";
		return;
	}

	cout << "Entrer la precision";
	double precision;
	cin >> precision;

	double resultat = logarithmique(x, precision);
	cout << "le resultat est:" << endl;
	cout << resultat;
	return resultat;
};


//Comprend pas comment appeler 3 paires de valeurs différentes? On doit les entrer nous-mêmes? -> oui