#include <iostream>
#include <cmath>
#include <limits>
#include <string>

using namespace std;

static double readValueInRange(string question, double min, double max) {

	double value = 0.0;
	bool isValid = false;

	while (!isValid) {
		cout << question;
		cin >> value;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "La valeur doit etre reel, reesaye." << endl;
			continue;
		}
		else if (value < min || value > max) {
			cout << "La valeur doit etre dans l'intervale de " << min << " a " << max << ", reesaye." << endl;
			continue;
		}
		
		isValid = true;
	}

	return value;
}


int main() {


	double amount = readValueInRange("Entrez la somme d'argent : ", 0.0, INFINITY);

	double monthlyPayment = readValueInRange("Entrez le montant rembourser chaque mois : ", 0.0, INFINITY);

	double rate = readValueInRange("Entrez le taux d'interet annuel (en %) : ", 0.0, 100.0);

	double monthlyRate = (rate / 100.0) / 12.0;
	double remaining = amount;
	double totalInterest = 0.0;
	int monthsToRepay = 0;

	if (monthlyPayment <= remaining * monthlyRate) {
		cout << "Erreur : le remboursement mensuel est trop faible pour couvrir les intérêts." << endl;
		return 1;
	}

	// Simulation mois par mois
	while (remaining > 0) {
		double interest = remaining * monthlyRate;
		totalInterest += interest;
		remaining += interest;

		if (monthlyPayment > remaining) {
			// Dernier paiement, on ne rembourse que ce qui reste
			monthlyPayment = remaining;
		}
		//cout << remaining << " " << interest << endl;

		remaining -= monthlyPayment;
		monthsToRepay++;
	}

	cout << "Le nombre de mois necessaire pour rembourser la dette est : " << monthsToRepay << endl;
	cout << "La somme des interets percus par le preteur est : " << totalInterest << " $" << endl;

	return 0;
}