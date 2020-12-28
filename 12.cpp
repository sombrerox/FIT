#include <iostream>

using namespace std;

/*
Source: https://github.com/FITCommunity/Programiranje-1/blob/master/POSTAVKE.md
Napišite program, poštujući sve faze procesa programiranja, u kojem ćete za uneseni prirodni broj n izračunati sumu:
S=3!-6!+9! -....+(-1)n+1(3n)!

Upotrijebite funkcije:

int faktorijel(int);
int suma(int);
*/

// I don't know what the fuck this example is, why do we even have 1 before (3n) in the series, it's not changing anything
// not sure if this is correct, we should have one or two examples with concrete values for n so we know exactly h
int faktorijel(int);
int suma(int);

int main()
{
	int n;
	cout << "Unesi n: ";
	cin >> n;

	cout << "Suma serije iznosi: " << suma(n);
}

int faktorijel(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return n * faktorijel(n - 1);
}

int suma(int n) {
	int sum = 0;
	int operation = 0; // 0 -> subtraction, 1 -> addition
	// do the summation for series...
	for (int i = 3; i < n; i += 3) {
		// originally used ternary, replaced it later on for clarity
		if (operation == 1) {
			sum += faktorijel(i);
			// alternate...
			operation = 0;
		}
		else {
			sum -= faktorijel(i);
			// alternate...
			operation = 1;
		}
	}
	// append final calculation of (-1)n + 1(3n)!
	operation ? sum += (-1) * n + 1 * faktorijel(3 * n) : sum -= (-1) * n + 1 * faktorijel(3 * n);
	return sum;
}
