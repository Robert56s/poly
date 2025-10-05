/*Programme qui approxime la valeur de pi par la méthode de Monte-Carlo
   en générant des points aléatoires dans un carré de côté 2 et en testant
   s’ils appartiennent à un cercle de rayon 1
\file exo4.cpp
\authors Fournier et Nelea
\date 27 septembre 2025
\créé le 25 septembre 2025*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath> 

using namespace std;

static double randomMinusOneToOne() {
    return -1.0 + 2.0 * (rand() / (double)RAND_MAX);
}

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));

    int iterations = 0;
    cout << "Entrez le nombre d'iterations : ";
    cin >> iterations;

    int pointsInCircle = 0;

    for (int i = 0; i < iterations; i++) {
        double x = randomMinusOneToOne();
        double y = randomMinusOneToOne();

        if (x * x + y * y <= 1.0) {
            pointsInCircle++;
        }
    }

    double approxPi = 4.0 * pointsInCircle / iterations;

    const double truePi = 3.141593;

    double relativeError = fabs(approxPi - truePi) / truePi;

    cout << fixed << setprecision(6);
    cout << "Valeur approchee de pi : " << approxPi << endl;
    cout << "Ecart relatif : " << relativeError << endl;

    return 0;
}
