/*Programme qui affiche en premier les valeurs paires d'un tableau donné puis les valeurs impaires
\file exo5.cpp
\authors Fournier et Nelea
\date 27 septembre 2025
\créé le 25 septembre 2025*/

#include <iostream>
using namespace std;

int main() {
	const int tailleTableau = 10;
	int tableau1[tailleTableau] = {};
	int tableau2[tailleTableau] = {};
	int position = 0; //Position pour le deuxième tableau

	cout << "Entrez 10 nombres separes par un espace :" << endl;
	for (int i = 0; i < tailleTableau; i++) {
		cin >> tableau1[i];
	}

	//Nombres pairs
	for (int i = 0; i < tailleTableau; i++) {
		if (tableau1[i] % 2 == 0) {
			tableau2[position] = tableau1[i];
			position++;
		}
	}

	//Nombres impairs
	for (int i = 0; i < tailleTableau; i++) {
		if (tableau1[i] % 2 != 0) {
			tableau2[position] = tableau1[i];
			position++;
		}
	}

	//Affichage tableau
	cout << "Le tableau trie est : " << endl;
	for (int i = 0; i < tailleTableau; i++) {
		cout << tableau2[i] << " ";
	}
	cout << endl;
}