#include <iostream> 

using namespace std;

/*
Source: https://github.com/FITCommunity/Programiranje-1/blob/master/POSTAVKE.md
Napišite program u kojem ćete deklarirati niz od 7 cijelih brojeva. Uz pomoć funkcije:

void unos (int [], int); omogućite unos elemenata u niz;
float prosjecna(int [], int); izračunati prosječnu vrijednost elemenata niza;
bool opadajuci (int [], int); provjeriti jesu li elementi niza poredani u opadajućem poretku (n1 > n2 > n3 > n4 > n5 > n6 > n7);
*/

void unos(int[], int);
float prosjecna(int[], int);
bool opadajuci(int[], int);

int main()
{
	int arr[7] = {};
	unos(arr, 7);
	cout << "Prosjecna vrijednost niza je: " << prosjecna(arr, 7) << "\n";
	cout << "Niz je opadajuci: " << opadajuci(arr, 7);
}

void unos(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		cout << "Unesite vrijednost za index " << boolalpha << i << ": ";
		cin >> arr[i];
	}
}

float prosjecna(int arr[], int length) {
	int sum = 0;

	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}

	return (float)sum / length;
}

bool opadajuci(int arr[], int length) {
	for (int i = 0; i < length - 1; i++) {
		if (arr[i] < arr[i + 1]) {
			return false;
		}
	}
	return true;
}
