#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << "Entrer epsilon: ";
	double epsilon;
    cin >> epsilon;  
	double terme, numerateur = 1.0, denominateur = 1.0;
	int k = 0;
	double somme = 0.0;
	do {
		terme = numerateur / denominateur;
		somme += terme;
		k++;
		numerateur *= k;
		denominateur *= 2*k + 1;
	} while (terme >= epsilon);
	cout << "pi/2 ~= " << somme << endl;
    
  	return 0;
}