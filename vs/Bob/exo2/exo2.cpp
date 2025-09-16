// Robert Nelea 2449901
// Jia Fournier

#include <iostream>
using namespace std;


int main() {
	int prix;
	int montant;
	cout << "Entrer prix : ";
	cin >> prix;
	cout << "Entrer montant : "; 
	cin >> montant;

	int monnaie = montant - prix;
	int montantSuffisant = montant >= prix;

	int billet100 = monnaie / 100;
	monnaie %= 100;

	int billet20 = monnaie / 20;
	monnaie %= 20;

	int billet10 = monnaie / 10;
	monnaie %= 10;

	int billet5 = monnaie / 5;
	monnaie %= 5;

	int piece1 = monnaie;

	cout << "Montant OK : " << boolalpha << (montantSuffisant) << endl
		<< "Monnaie rendue : " << endl
		<< " - Billet(s) 100$..." << billet100 << endl
		<< " - Billet(s) 20$...." << billet20 << endl
		<< " - Billet(s) 10$...." << billet10 << endl
		<< " - Billet(s) 5$....." << billet5 << endl
		<< " - Piece(s) 1$......" << piece1 << endl;

}

