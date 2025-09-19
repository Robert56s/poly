/*Programme qui lit un fichier de ventes faites et qui écrit dans un autre fichier le sous-total, les taxes et le montant total de la vente.
\file exo4.cpp
\author Fournier et Nelea
\date 19 septembre 2025
Créé le 11 septembre 2025*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


int main() {
	string texte;

	//Ouverture et déclaration du ficher è lire
	ifstream lireVentes("ventes.txt");

	//Ouverture du fichier à créer
	ofstream ecrireFacture("facture.txt");

	//Lire la première ligne qui est le nom
	string nom;
	getline(lireVentes, nom);
	ecrireFacture << nom << endl;

	//Créer les variables qui représente les informations contenues dans le fichier
	string article;
	int quantite = 0;
	double prix = 0;

	//autre variables
	double prixTotal= 0.0;
	double prixArticle = 0.0;
	
	for (int i = 0; i < 3; i++) {
		//lire les variables qu'on vient de créer dans cet ordre
		lireVentes >> article >> quantite >> prix;

		prixArticle = quantite * prix;
		prixTotal += prixArticle;

		if (lireVentes.eof()) break;

	}

	double taxe = 0.15 * prixTotal;
	double prixTaxe = prixTotal + taxe;

	ecrireFacture << left << setw(12) << "SOUS-TOTAL" << right << setw(10) << fixed << setprecision(2) << prixTotal << " $" << endl;
	ecrireFacture << left << setw(12) << "TAXES" << right << setw(10) << fixed << setprecision(2) << taxe << " $" << endl;
	ecrireFacture << left << setw(12) << "TOTAL" << right << setw(10) << fixed << setprecision(2) << prixTaxe << " $" << endl;

	//Fermer les fichiers
	lireVentes.close();
	ecrireFacture.close();

};