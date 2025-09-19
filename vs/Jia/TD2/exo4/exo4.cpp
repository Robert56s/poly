/*Programme qui lit un fichier de ventes faites et qui �crit dans un autre fichier le sous-total, les taxes et le montant total de la vente.
\file exo4.cpp
\author Fournier et Nelea
\date 19 septembre 2025
Cr�� le 11 septembre 2025*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


int main() {
	string texte;

	//Ouverture et d�claration du ficher � lire
	ifstream lireVentes("ventes.txt");

	//Ouverture du fichier � cr�er
	ofstream ecrireFacture("facture.txt");

	//Lire la premi�re ligne qui est le nom
	string nom;
	getline(lireVentes, nom);
	ecrireFacture << nom << endl;

	//Cr�er les variables qui repr�sente les informations contenues dans le fichier
	string article;
	int quantite = 0;
	double prix = 0;

	//autre variables
	double prixTotal= 0.0;
	double prixArticle = 0.0;
	
	for (int i = 0; i < 3; i++) {
		//lire les variables qu'on vient de cr�er dans cet ordre
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