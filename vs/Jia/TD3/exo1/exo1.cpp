/*Programme qui lit un nombre premier et qui détermine si le nombre est premier. S'il ne l'est pas, le plus petit entier diviseur est donné
\file exo1.cpp
\authors Fournier et Nelea
\date 27 septembre 2025
\créé le 25 septembre 2025*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout << "Entrer un nombre entier : ";
	int entier = 0;
	cin >> entier;

	bool estDiviseur = false;

	//Gérer les exceptions
	if (entier == 1 || entier == 0) {
		cout << "Le nombre n'est pas premier" << endl;
		return 0; //Arrêter le programme ici
	}

	for (int i = 2; i <= sqrt(entier); i++) {
		if (entier % i == 0) {
			estDiviseur = true;
			break;
		}
	}

	if (estDiviseur == true) {
		cout << "Le nombre n'est pas premier" << endl;
	}
	else {
		cout << "Le nombre est premier" << endl;
	}

};
