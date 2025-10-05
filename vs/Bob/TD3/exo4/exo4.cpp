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

    int iterations;
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
