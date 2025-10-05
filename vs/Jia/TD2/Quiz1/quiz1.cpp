#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	cout << "Entrez la resistance R1 : " << endl;
	int R1 = 0;
	cin >> R1;

	cout << "Entrez la resistance R2 : " << endl;
	int R2 = 0;
	cin >> R2;

	double resistanceEquivalente = 0.0;
	resistanceEquivalente = (R1 * R2) / double((R1 + R2));

	//Ouverture du fichier à créer
	ofstream fichier("resistance.txt");

	//Écrire dans le fichier
	fichier << fixed << setprecision(2) << resistanceEquivalente << " " << "ohm" << endl;
	

	//Fermer le fichier
	fichier.close();


}