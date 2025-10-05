/*Programme qui lit un nombre premier et qui détermine si le nombre est premier. S'il ne lest pas, le plus petit entier diviseur est donné
/file exo2.pp
/authors Fournier et Nelea
/date 27 septembre 2025
/créé le 25 septembre 2025*/

#include <iostream>
#include <cmath>
using namespace std;

double validationEntree(double valeur, double min, double max) {
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
	somme = validationEntree(somme, 0, INFINITY);
	cout << "la somme d'argent pretee est " << somme << endl;

	cout << "Entrez le montant rembourse chaque mois : " << endl;
	double montant = 0.0;
	montant = validationEntree(montant, 0, INFINITY);
	cout << "le montant rembourse chaque mois est " << montant << endl;

	cout << "Entrez le taux d'interet annuel : " << endl;
	double tauxAnnuel = 0.0;
	tauxAnnuel = validationEntree(tauxAnnuel, 0, 100);
	cout << "le taux interet annuel est " << tauxAnnuel << endl;

	double tauxMensuel = tauxAnnuel / (100 * 12);

	//traiter le cas limite -> si le paiement est plus petit que la dette, on ne remboursera jamais
	double interetPremierMois = 0.0;
	interetPremierMois = somme * tauxMensuel;
	if (montant <= interetPremierMois) {
		cout << "Paiement trop faible, la dette ne sera jamais remboursee." << endl;
		return 0;
	}

	//calcul
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

	cout << "nombre de mois est : " << mois << endl;
	cout << "interet est : " << interetPaye << endl;
};


/*/*Programme qui lit un nombre premier et qui détermine si le nombre est premier. S'il ne lest pas, le plus petit entier diviseur est donné
/file exo2.pp
/authors Fournier et Nelea
/date 27 septembre 2025
/créé le 25 septembre 2025*/

#include <iostream>
#include <cmath>
using namespace std;


double validationTaux(double tauxAnnuel) {
	bool erreur = false;

	do {
		cout << "Entrez le taux d'interet annuel : " << endl;
		cin >> tauxAnnuel;

		if (cin.fail()) {
			erreur = true;
			//cout << "erreur, cin inutilisable" << endl;
			cin.clear();
			cin.ignore(80, '\n');
			//cout << "cin reinitialise" << endl;
		}
		else if (tauxAnnuel < 0.0 || tauxAnnuel > 100.0) {
			erreur = true;
			//cout << "erreur pas dans l'intervalle, cin inutilisable" << endl;
			cin.clear(); //necessaire?
			cin.ignore(80, '\n');
			//cout << "cin reinitialise" << endl;
		}
		else {
			erreur = false;
			//cout << tauxAnnuel << " lu correctement" << endl;
		}
	} while (erreur);

	return tauxAnnuel;
};

double validationSomme(double somme) {
	bool erreur = false;

	do {
		cout << "Entrez la somme d'argent pretee" << endl;
		cin >> somme;

		if (cin.fail()) {
			erreur = true;
			//cout << "erreur, cin inutilisable" << endl;
			cin.clear();
			cin.ignore(80, '\n');
			//cout << "cin reinitialise" << endl;
		}
		else if (somme < 0.0) {
			erreur = true;
			//cout << "erreur, nombre negatif" << endl;
			cin.clear();
			cin.ignore(80, '\n');
			//cout << "cin reinitialise" << endl;
		}
		else {
			erreur = false;
			//cout << somme << " lu correctement" << endl;
		}
	} while (erreur);

	return somme;
}

double validationMontant(double montant) {
	bool erreur = false;

	do {
		cout << "Entrez le montant rembourse chaque mois" << endl;
		cin >> montant;

		if (cin.fail()) {
			erreur = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
		else if (montant < 0.0) {
			erreur = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
		else {
			erreur = false;
			//cout << montant << " lu correctement" << endl;
		}
	} while (erreur);

	return montant;
}

int main() {

	double somme = 0.0;
	somme = validationSomme(somme);
	cout << "la somme d'argent pretee est " << somme << endl;

	double montant = 0.0;
	montant = validationMontant(montant);
	cout << "le montant rembourse chaque mois est " << montant << endl;

	double tauxAnnuel = 0.0;
	tauxAnnuel = validationTaux(tauxAnnuel);
	cout << "le taux interet annuel est " << tauxAnnuel << endl;

	double tauxMensuel = tauxAnnuel / (100 * 12);

	//traiter le cas limite -> si le paiement est plus petit que la dette, on ne remboursera jamais
	double interetPremierMois = 0.0;
	interetPremierMois = somme * tauxMensuel;
	if (montant <= interetPremierMois) {
		cout << "Paiement trop faible, la dette ne sera jamais remboursee." << endl;
		return 0;
	}

	//calcul
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

	cout << "nombre de mois est : " << mois << endl;
	cout << "interet est : " << interetPaye << endl;
}; */