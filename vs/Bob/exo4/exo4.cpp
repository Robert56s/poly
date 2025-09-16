// Robert Nelea 2449901
// Jia Fournier

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    ifstream infile("ventes.txt");
    ofstream outfile("facture.txt");

    string client;
    getline(infile, client);
    outfile << client << endl;
    string produit;
    int quantite;
    double prix, sousTotal = 0.0;

    for (int i = 0; i < 3; i++) {
        infile >> produit >> quantite >> prix;
        sousTotal += quantite * prix;
    }

    double taxes = sousTotal * 0.15;
    double total = sousTotal + taxes;

    outfile << left << setw(12) << "SOUS-TOTAL"
        << right << setw(10) << fixed << setprecision(2) << sousTotal << " $" << endl;
    outfile << left << setw(12) << "TAXES"
        << right << setw(10) << fixed << setprecision(2) << taxes << " $" << endl;
    outfile << left << setw(12) << "TOTAL"
        << right << setw(10) << fixed << setprecision(2) << total << " $" << endl;

    infile.close();
    outfile.close();

    return 0;
}
