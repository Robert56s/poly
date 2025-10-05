/*Programme qui calcule la hauteur d'une balle après un certain nombre de rebonds
   en tenant compte d'un coefficient de rebond
\file exo3.cpp
\authors Fournier et Nelea
\date 27 septembre 2025
\créé le 25 septembre 2025*/

#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

template <typename Type>
Type readValueInRange(const string question, double min, double max) {
    Type value{};
    bool isValid = false;
    string input = "";

    while (!isValid) {
        cout << question;
        getline(cin, input); 

        stringstream ss(input);
        ss >> value;

        if (ss.fail() || !ss.eof()) {
            cout << "La valeur est du mauvais type, reesaye." << endl;
            continue;
        }

        double valAsDouble = static_cast<double>(value);

        if (valAsDouble < min || valAsDouble > max) {
            cout << "La valeur doit etre dans l'intervalle de " << min
                << " a " << max << ", reesaye." << endl;
            continue;
        }

        isValid = true;
    }

    return value;
}


int main() {
	double height = readValueInRange<double>("Entrez la hauteur initial de la balle (en m): ", 0.0, INFINITY);
	double numberOfBounce = readValueInRange<int>("Entrez le nombre de rebonds au bout duquel vous souhaitez connaitre la hauteur de la balle : ", 0, numeric_limits<int>::max());
	double coefficient = readValueInRange<double>("Entrez le coefficient de rebond (entre 0 et 1): ", 0.0, 1.0);

	const double G = 9.81;
	double currentHeight = height;
	double currentVelocity = 0.0;

	int realNumberOfBounce = 0;

	while (realNumberOfBounce < numberOfBounce) {
		currentVelocity = sqrt(2 * G * currentHeight);
		currentVelocity *= coefficient;

		double newHeight = (currentVelocity * currentVelocity) / (2 * G);
		if (newHeight <= 0) break;

		currentHeight = newHeight;
		realNumberOfBounce++;
	}

	cout << fixed << setprecision(2);
	cout << "La hauteur de la balle apres " << realNumberOfBounce << " rebond est " << currentHeight << "m.";

	return 0;
}