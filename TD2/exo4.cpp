/**
 * Programme qui lit un fichier de ventes et qui écrit dans un autre fichier
 * le sous-total, les taxes et le montant total de la vente.
 * \file   exo4.cpp
 * \author Jia Fournier 2278978 et Robert Nelea 2449901
 * \date   19 septembre 2025
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


int main() {
	string texte = "";

	ifstream lireVentes("ventes.txt");

	ofstream ecrireFacture("facture.txt");

	string nom = "";
	getline(lireVentes, nom);
	ecrireFacture << nom << endl;

	string article = "";
	int quantite = 0;
	double prixUnitaire = 0.0;

	double prixTotal = 0.0;
	double prixArticle = 0.0;
	
	for (int i = 0; i < 3; i++) {
		//lire les variables qu'on vient de creer dans cet ordre
		lireVentes >> article >> quantite >> prixUnitaire;

		if (lireVentes.eof()) break;

		prixArticle = quantite * prixUnitaire;
		prixTotal += prixArticle;
	}

	const double TAUX_TAXE = 0.15;
	double taxe = TAUX_TAXE * prixTotal;
	double prixTaxe = prixTotal + taxe;

	ecrireFacture << left << setw(12) << "SOUS-TOTAL" << right << setw(10) << fixed << setprecision(2) << prixTotal << " $" << endl;
	ecrireFacture << left << setw(12) << "TAXES" << right << setw(10) << fixed << setprecision(2) << taxe << " $" << endl;
	ecrireFacture << left << setw(12) << "TOTAL" << right << setw(10) << fixed << setprecision(2) << prixTaxe << " $" << endl;

	//Fermer les fichiers
	lireVentes.close();
	ecrireFacture.close();

	return 0;
};