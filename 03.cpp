#include <iostream> 

using namespace std;

/*
Source: https://github.com/FITCommunity/Programiranje-1/blob/master/POSTAVKE.md
Napišite program u kojem ćete omogućiti unos prirodnog broja. Provjerite je li broj trivijalan (prost) uz pomoć funkcije: bool trivijalan (int);.
U slučaju da broj nije trivijalan (prost) odredite i ispište sve njegove djelitelje uz pomoć funkcije: void djelitelji(int);
*/

bool trivijalan(int);
void djelitelji(int);

int main()
{
	int n;
	cout << "Unesite broj: ";
	cin >> n;

	if (!trivijalan(n)) {
		djelitelji(n);
	}
}

bool trivijalan(int n) {
	int limit = n / 2; // divide and floor if odd

	for (int i = 2; i <= limit; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void djelitelji(int n) {
	int limit = n / 2; // divide and floor if odd

	// print all not including 1 and itself
	for (int i = 2; i <= limit; i++) {
		if (n % i == 0) {
			cout << "Broj " << n << " je djeljiv sa " << i << "\n";
		}
	}
}
