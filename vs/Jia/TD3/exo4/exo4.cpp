/*Programme qui permet de calculer une valeur approchée de pi avec la méthode de Monte-Carlo
\file exo4.cpp
\authors Fournier et Nelea
\date 27 septembre 2025
\créé le 25 septembre 2025*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

double genererNombre() {
	double nombre = 0.0;

	//on divise par RAND_MAX pour avoir un intervalle entre 1 et 0. On fait *2 pour avoir intervalle de [0,2]. On fait -1 pour décaler l'intervalle à [-1,1]
	nombre = (static_cast<double>(rand()) / RAND_MAX) * 2.0 - 1;
	
	return nombre;
}

int main() {
	srand(time(0));

	double x = 0.0;
	double y = 0.0;

	cout << "Entrez le nombre d'iteration souhaitees : " << endl;
	int iteration = 0;
	cin >> iteration;

	double nombreCercle = 0.0;

	for (int i = 0; i < iteration; i++) {
		x = genererNombre();
		y = genererNombre();

		if (pow(x, 2) + pow(y, 2) < 1) {
			nombreCercle += 1;
		}
	}

	double approximation = 0.0;
	approximation = (nombreCercle / iteration) * 4;

	const double pi = 3.141593;
	double ecartRelatif = 0.0;
	ecartRelatif = (abs(approximation - pi) / pi) * 100; 

	cout << "approximation est : " << fixed << setprecision(6) << approximation << endl;
	cout << "ecart relatif est : " << fixed << setprecision(6) << ecartRelatif << "%" << endl;

};

