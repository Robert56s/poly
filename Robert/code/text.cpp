#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double epsilon = 0.0;
	cout << "Entrez epsilon : ";
    cin >> epsilon;
    
    double aproxPi = 0.0;
    
    bool state = true;
    
    for (int i = 1; i < 10; i++) {
    	int upper = 0;
        int lower = 0;
    	for (int j = 1; j <= i; i++) {
        	upper *= j;
            lower *= (2*j + 1);
        }
        cout << (upper/(double)lower) << endl;
    }
    
  	return 0;
}