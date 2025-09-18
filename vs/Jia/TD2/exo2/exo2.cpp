#include <iostream>
using namespace std;

int main() {
	cout << "Entrer le prix a payer : ";
	int prix = 0;
	cin >> prix;

	cout << "Entrer le montant donne pour payer : ";
	int montant = 0;
	cin >> montant;

	bool montantPasSuffisant = montant < prix;

	cout << "Montant OK : " << boolalpha << (!montantPasSuffisant) << endl;

	if (montantPasSuffisant) {
		cout << "Montant pas suffisant";
		return 0;
	}

	int monnaie = montant - prix; //donne le montant d'argent à redonner

	cout << "Monnaie rendue : " << endl;
	cout << " - Billet(s) 100$..." << (monnaie / 100) << endl;
	cout << " - Billet(s) 20$...." << ((monnaie % 100) / 20) << endl;
	cout << " - Billet(s) 10$...." << ((monnaie % 20) / 10) << endl;
	cout << " - Billet(s) 5$....." << ((monnaie % 10) / 5) << endl;
	cout << " - Piece(s) 1$......" << ((monnaie % 5) / 1) << endl;

};