#include <iostream> 

using namespace std;

/*
Source: https://github.com/FITCommunity/Programiranje-1/blob/master/POSTAVKE.md
Napišite program, poštujući sve faze procesa programiranja, koji će ispisati sve troznamenkaste brojeve koji
su jednaki sumi faktorijela svojih znamenki – ABC = A! + B! + C! Upotrijebite funkcije:

bool provjera(int);
int faktorijel(int);
*/

bool provjera(int);
int faktorijel(int);

const int MIN_THREE_DIGIT_NUMBER = 100;
const int MAX_THREE_DIGIT_NUMBER = 999;

// initialize for with zeroes by default, so we can check whether slot has been initialised or not
int factorials[10] = {0};

int main()
{
	for (int i = MIN_THREE_DIGIT_NUMBER; i <= MAX_THREE_DIGIT_NUMBER; i++) {
		if (provjera(i)) {
			// only 145??
			cout << i << "\n";
		}
	}
}

bool provjera(int n) {
	int sumOfDigitFactorials = 0;
	int originalValue = n;

	while (n > 0) {
		int digit = n % 10;
		n /= 10;
		sumOfDigitFactorials += faktorijel(digit);
	}
	return originalValue == sumOfDigitFactorials;
}

// basic, recursive, no validity checks
// uncomment to use it and comment the one below
//int faktorijel(int n) {
//	if (n == 1 || n == 0) {
//		return 1;
//	}
//	return n * faktorijel(n - 1);
//}

// "optimised" (only 10 possible digits [], no real improvements), iterative, no validity checks
// to optimize it further we could ignore all numbers which contain digit 7
// as 7! == 5040 which is well over highest three digit number (999)
int faktorijel(int n) {
	// handle n == zero
	if (n == 0) {
		return 1;
	}
	// if factorial has been already calculated, return the value
	if (factorials[n] != 0) {
		return factorials[n];
	}
	// otherwise proceed with calculation
	int factorial = 1;
	for (int i = 1; i <= n; i++) {
		factorial *= i;
	}
	// save/memoize for reuse
	factorials[n] = factorial;
	return factorial;
}
