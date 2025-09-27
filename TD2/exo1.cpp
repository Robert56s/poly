/**
 * Programme qui vérifie si deux vecteurs sont orthogonaux.
 * \file   exo1.cpp
 * \author  Jia Fournier 2278978 et Robert Nelea 2449901
 * \date   18 septembre 2025
 */

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

	int produitScalaire = (x1 * x2) + (y1 * y2);
	
	if (produitScalaire == 0) {
		cout << "Les vecteurs sont orthogonaux" << endl;
		cout << produitScalaire;
	}
	else {
		cout << "Les vecteurs ne sont pas orthogonaux" << endl;
		cout << produitScalaire;
	}

	return 0;
};