#include <iostream>
#include <cmath>

using namespace std;

static bool isPrime(int number) {

	if (number <= 1) return false;

	int i = 2;
	while (i * i <= number) {
		if (number % i == 0) {
			return false;
		}
		i++;
	}
	return true;
}

static int getSmallestIntDivisor(int number) {
	int divisor = 2;
	if (number % divisor == 0) return divisor;
	
	divisor++;

	while (divisor <= sqrt(number)) {
		if (number % divisor == 0) {
			return divisor;
		}
		divisor += 2;
	}
	return number;
}

int main() {
	int number = 0;

	cout << "Entrer un nombre entier : ";
	cin >> number;

	if (isPrime(number)) {
		cout << "Ce nombre est premier.";
		return 0;
	}
	cout << "Ce nombre n'est pas premier car il est divisible par " << getSmallestIntDivisor(number) << ".";

	return 0;
}