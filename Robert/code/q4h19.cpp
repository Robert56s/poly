#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Vente {
    int date; // Format: YYYYMMDD
    char categorie;
    double montant;
};

const int N_MAX_VENTES = 3;
const int N_CATEGORIES = 26;

int main() {

    ifstream ventesTxt("ventes.txt");

    Vente tableau[N_MAX_VENTES];

    for (int i = 0; i < N_MAX_VENTES; i++) {  // ou while (!ws(fichier).eof()) avec nVentes et nventes++
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

    double sommeMotant[N_CATEGORIES] = {};
    double venteMax = 0.0;
    int dateVenteMax = 0;

    for (int i = 0; i < N_MAX_VENTES; i++) {
        
        if (tableau[i].date < dateDebut || tableau[i].date > dateFin) 
        continue;
        
        if(tableau[i].montant > venteMax) {
            venteMax = tableau[i].montant;
            dateVenteMax = tableau[i].date;
        }

        sommeMotant[tableau[i].categorie - 65] += tableau[i].montant;
    }

    for (int i = 0; i < N_CATEGORIES; i++) {
        if (sommeMotant[i] == 0) 
            continue;
        cout << "Categorie " << char(65 + i) << " : " << sommeMotant[i] << endl;
    }

    cout << "Date de plus grosse vente: " << dateVenteMax;
}