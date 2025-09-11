#include <iostream>
using namespace std;

int main()
{
	double x1, y1, x2, y2;

	cout << "Ce code va vous dire si deux vecteur 2d sont orthogonaux ou pas" <<endl;
	cout << "La composante x du premier vecteur : ";
	cin >> x1;
	cout << "La composante y du premier vecteur : ";
	cin >> y1;
	cout << "La composante x du deuxieme vecteur : ";
	cin >> x2;
	cout << "La composante y du deuxieme vecteur : ";
	cin >> y2;

	if (x1 * x2 + y1 * y2 == 0)
	{
		cout << "Les vecteurs sont orthogonaux." << endl;
	}
	else
	{
		cout << "Les vecteurs ne sont pas orthogonaux" << endl;
	}

	return 0;
}