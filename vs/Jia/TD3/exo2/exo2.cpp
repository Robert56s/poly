/*Programme qui retourne le nombre de mois nécessaire pour payer une dette ainsi que les intérêts payés en fonction
de la somme d'argent empruntée, le montant remboursé chaque mois et le taux d'intérêt annuel
\file exo2.cpp
\authors Fournier et Nelea
\date 27 septembre 2025
\créé le 25 septembre 2025*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double validerEntree(double valeur, double min, double max) {
	bool erreur = false;

	do {
		cin >> valeur;

		if (cin.fail()) {
			erreur = true;
			cin.clear();
			cin.ignore(80, '\n');
			cout << "la valeur doit etre un chiffre" << endl;
		}
		else if (valeur < min || valeur > max) {
			erreur = true;
			cin.clear();
			cin.ignore(80, '\n');
			cout << "la valeur ne respecte pas l'intervalle" << endl;
		}
		else {
			erreur = false;
		}
	} while (erreur);

	return valeur;
}


int main() {

	cout << "Entrez la somme d'argent pretee : " << endl;
	double somme = 0.0;
	somme = validerEntree(somme, 0, INFINITY);

	cout << "Entrez le montant rembourse chaque mois : " << endl;
	double montant = 0.0;
	montant = validerEntree(montant, 0, INFINITY);

	cout << "Entrez le taux d'interet annuel : " << endl;
	double tauxAnnuel = 0.0;
	tauxAnnuel = validerEntree(tauxAnnuel, 0, 100);

	double tauxMensuel = tauxAnnuel / (100 * 12);

	//Traiter le cas limite -> si le paiement est plus petit que la dette, on ne remboursera jamais
	double interetPremierMois = 0.0;
	interetPremierMois = somme * tauxMensuel;
	if (montant <= interetPremierMois) {
		cout << "Paiement trop faible, la dette ne sera jamais remboursee." << endl;
		return 0;
	}

	//Calcul
	int i = 0;
	double interet = 0.0;
	double interetPaye = 0.0;

	while (somme > 0.0) {
		interet = tauxMensuel * somme;
		somme = somme * (1 + tauxMensuel) - montant;
		interetPaye += interet;
		i++;
	}

	int mois = i;

	cout << "Le nombre de mois pour rembourser la dette est : " << mois << endl;
	cout << "Les interets payes sont : " << fixed << setprecision(2) << interetPaye << "$" << endl;
};