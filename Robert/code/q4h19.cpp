#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Vente {
    int date; // Format: YYYYMMDD
    char categorie;
    double montant;
};

// struct VenteTotalParCategorie {
//     char categorie;
//     double montantTotal;
// };

const int N_MAX_VENTES = 3;
const int N_CATEGORIES = 2;


int main() {

    ifstream ventesTxt("ventes.txt");

    Vente tableau[N_MAX_VENTES];

    for (int i = 0; i < N_MAX_VENTES; i++) {
        ventesTxt >> tableau[i].date;
        ventesTxt >> tableau[i].categorie;
        ventesTxt >> tableau[i].montant;
    }

    // for (int j = 0; j < N_MAX_VENTES; j++) {
    //     cout << tableau[j].date << '\t';
    //     cout << tableau[j].categorie << '\t';
    //     cout << tableau[j].montant << '\t';
    //     cout << endl;
    // }

    int dateDebut = 0;
    int dateFin = 0;

    cout << "Entrer la date de debut et de fin : ";
    cin >> dateDebut >> dateFin;

    for
}