/*Programme qui détermine le nom le plus long d'un dictionnaire et qui affiche ce mot avec sa nature, son genre et
sa définition
\file exo6.cpp
\authors Fournier et Nelea
\date 27 septembre 2025
\créé le 25 septembre 2025*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Dictionnaire {
	string mot, natureGenre, definition;
};

int main() {
	//Ouverture et déclaration du ficher à lire
	ifstream fichier("dictionnaire.txt");

	const int nombreMot = 4;

	//Tableau pour stocker les mots
	Dictionnaire tableau[nombreMot];

	if (!fichier.fail()) {
		//i est le compteur pour le nombre de mots
		for (int i = 0; i < nombreMot; i++) {
			getline(fichier, tableau[i].mot, '\t');
			getline(fichier, tableau[i].natureGenre, '\t');
			getline(fichier, tableau[i].definition);
		}

		//Trouver mot le plus long et afficher
		int indiceLongMot = 0;
		for (int i = 1; i < nombreMot; i++) {
			if (tableau[i].mot.size() > tableau[indiceLongMot].mot.size()) {
				indiceLongMot = i;
			}
		}

		cout << tableau[indiceLongMot].mot << " " << "(" << tableau[indiceLongMot].natureGenre << ") : " << tableau[indiceLongMot].definition << endl;
		
	}

	else {
		cout << "Le est fichier introuvable" << endl;
	}

}