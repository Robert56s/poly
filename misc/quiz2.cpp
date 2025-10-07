#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int suite[100];

    cout << "Combien de valeurs : ";
    int nombre = 0;
    cin >> nombre;
    
    int nombreIntDivisiblePar3 = 0;

    cout << "Entrez les valeurs : ";
    for (int i = 0; i < nombre; i++) {
        cin >> suite[i];
        if (suite[i] % 3 == 0) {
            nombreIntDivisiblePar3++;
        }
    }

    cout << fixed << nombreIntDivisiblePar3 << " entiers sont divisibles par 3." << endl;

    return 0;
}