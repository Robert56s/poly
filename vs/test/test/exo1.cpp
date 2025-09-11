#include <iostream>
using namespace std;

int main()
{
	int n = 10;
	int sum = 0;

	int i = 0;


	cout << "Enter a number: ";
	cin >> n;

	while (i<n) {
		sum = +i;
		i++;
	}
	cout << "Sum is: " << sum << endl;
}
