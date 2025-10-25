#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

static const unsigned nMaxAppels = 200, nMaxContacts = 50, nMaxNumeros = 3;

struct Appel {
    string numero;
    int heure, minute;
    bool estSortant;
};

struct Contacts {
    int nNumero;
    string numero[nMaxNumeros];
    string nomComplet;
};

static int lireAppeles(string cacs1) {
    return 3;
}

int main() {
    Appel appels[3];

    unsigned nAppels = lireAppeles("appeles.txt, appels");

    ifstream contactsTxt("ventes.txt");

    Contacts contacts[nMaxContacts] = {};

    int nEntre = 0;
    while (!ws(contactsTxt).eof()) {

        contactsTxt >> contacts[nEntre].nNumero;

        for (int i = 0; i < contacts[nEntre].nNumero; i++) {
            contactsTxt >> contacts[nEntre].numero[i];
        }

        getline(contactsTxt, contacts[nEntre].nomComplet);
        contactsTxt.ignore(1);

        nEntre++;
    }

    string nomRechercher = "";
    Contacts contactRechercher;
    cout << "Entrez le nom comnplet du contact : ";
    cin >> nomRechercher;

    for (int i = 0; i < nEntre; i++ ) {
        if (contacts[i].nomComplet == nomRechercher) {
            contactRechercher = contacts[i];
        }
    }

    
}