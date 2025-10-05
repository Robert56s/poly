/*Programme qui donne la hauteur finale atteinte par une balle en fonction de sa hauteur initiale, du nombre
de rebond et du coefficient de rebond
\file exo3.cpp
\authors Fournier et Nelea
\date 27 septembre 2025
\créé le 25 septembre 2025*/

#include <iostream>
#include <cmath>
using namespace std;

double validerEntree(double valeur, double min, double max) {
	bool erreur = false;

	do {
		cin >> valeur;

		if (cin.fail()) {
			erreur = true;
			cin.clear();
			cin.ignore(80, '\n');
			cout << "La valeur doit etre un chiffre" << endl;
		}
		else if (valeur < min || valeur > max) {
			erreur = true;
			cin.clear();
			cin.ignore(80, '\n');
			cout << "La valeur ne respecte pas l'intervalle" << endl;
		}
		else {
			erreur = false;
		}
	} while (erreur);

	return valeur;
}

int main() {
	
	cout << "Entrez la hauteur : " << endl;
	double hauteur = 0.0;
	hauteur = validerEntree(hauteur, 0, INFINITY);

	cout << "Entrez le nombre de rebonds : " << endl;
	int rebond = 0;
	rebond = validerEntree(rebond, 0, INFINITY);

	cout << "Entrez le coefficient de rebond : " << endl;
	double coefficient = 0.0;
	coefficient = validerEntree(coefficient, 0, 1);

	//cout << "la hauteur est " << hauteur << ", " << "le nombre de rebond est " << rebond << " et le coefficient est " << coefficient << endl;

	//calcul
	int i = 0;
	const double g = 9.81;
	const double c = coefficient;
	double hi = hauteur;
	double vi = 0.0;
	vi = sqrt(2 * g * hi);
	double vf = 0.0;
	double hf = 0.0;
	
	while (i < rebond) {
		vf = c * vi;
		hf = (pow(vf, 2)) / (2 * g);
		hi = hf;
		vi = vf;
		i++;
	}

	cout << "La hauteur finale est : " << hi << endl;
}