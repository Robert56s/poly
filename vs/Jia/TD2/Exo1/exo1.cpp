/*Programme qui vérifie si les vecteurs sont orthogonaux ou non.
\file exo1.cpp
\author Fournier et Nelea
\date 18 septembre 2025
Créé le 11 septembre 2025*/

#include <iostream>
using namespace std;

int main() {
	cout << "Entrer la composante x du premier vecteur : ";
	double x1 = 0.0;
	cin >> x1;

	cout << "Entrer la composante y du premier vecteur : ";
	double y1 = 0.0;
	cin >> y1;

	cout << "Entrer la composante x du deuxieme vecteur : ";
	double x2 = 0.0;
	cin >> x2;

	cout << "Entrer la composante y du deuxieme vecteur : ";
	double y2 = 0.0;
	cin >> y2;

	int resultat = (x1 * x2) + (y1 * y2);
	
	if (resultat == 0) {
		cout << "Les vecteurs sont orthogonaux" << endl;
		cout << resultat;
	}
	else {
		cout << "Les vecteurs ne sont pas orthogonaux" << endl;
		cout << resultat;
	}

};