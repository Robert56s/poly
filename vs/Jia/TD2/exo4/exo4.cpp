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

	ecrireFacture << "sous-total " << prixTotal << '$' << endl << "taxes " << taxe << '$' << endl << "total " << prixTaxe << '$' << endl;

	//Fermer les fichiers
	lireVentes.close();
	ecrireFacture.close();

};