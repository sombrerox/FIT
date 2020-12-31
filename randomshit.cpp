#include <iostream>

using namespace std;

/*
Source: https://github.com/FITCommunity/Programiranje-1/blob/master/POSTAVKE.md
Napišite program u kojem ćete :

omogućiti unos niza od 6 realnih brojeva u intervalu od -7.0 do +7.0 pomoću funkcije: void unos (float [], int);
definirati i upotrijebiti funkciju int najvecineg(float [], int); koja će pronaći i vratiti poziciju najvećeg negativnog elementa u nizu; (Moguće je da u nizu uopće ne bude negativnih brojeva – ispisati odgovarajuću poruku.)
definirati i upotrijebiti funkciju float suman(float[], int); koja treba izračunati i vratiti sumu negativnih elemenata niza; (Moguće je da u nizu uopće ne bude negativnih brojeva.)
Ispis pozicije najvećeg negativnog elementa, sume negativnih elemenata kao i odgovarajućih poruka vršite u funkciji main.
*/

void unos(float[], int);
int najvecineg(float[], int);
float suman(float[], int);

const int ARR_LENGTH = 6;

int main(void)
{
	float arr[ARR_LENGTH] = {};
	unos(arr, ARR_LENGTH);

	cout << "Index najveceg negativnog broja u nizu je: " << najvecineg(arr, ARR_LENGTH) << "\n";
	cout << "Suma svih negativnih elemenata u nizu je: " << suman(arr, ARR_LENGTH);

}

void unos(float arr[], int length) {
	for (int i = 0; i < length; i++) {
		float n;
		cout << "Unesi broj u intervalu od -7.0 do +7.0: ";
		cin >> n;

		if (n < -7.0 || n > 7.0) {
			cout << "Uneseni broj nije validan, interval je od -7.0 do 7.0" << "\n";
			i--;
			continue;
		}

		arr[i] = n;
	}
}

int najvecineg(float arr[], int length) {
	int maxNegative = 0; // [-4,3,-2,1, -7,5]

	for (int i = 1; i < length; i++ ) {
		if (arr[i] < arr[maxNegative]) {
			maxNegative = i;
		}
	}
	if (!(arr[maxNegative] < 0)) { // maxNegative = 0 .... false
		cout << "Nema negativnih brojeva.";
		return 0;
	}
	return maxNegative;
}

float suman(float arr[], int length) {
	float sum = 0.0;
	for (int i = 0; i < length; i++) {
		if (arr[i] < 0) {
			sum += arr[i];
		}
	}
	return sum;
}
