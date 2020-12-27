#include <iostream> 

using namespace std;

/*
Source: https://github.com/FITCommunity/Programiranje-1/blob/master/POSTAVKE.md
Napišite program u kojem ćete kreirati tri cjelobrojna niza i to – prvi niz od 3 elementa, drugi niz od 4 elementa i treći niz od 7 elemenata. Uz pomoć funkcije:

void unos (int [], int); omogućite unos elemenata u prvi i drugi niz;
void inicijalizacija (int [], int[], int []); omogućite inicijalizaciju elemenata trećeg niza tako što ćete kopirati sve elemente prvog i drugog niza u treći;
int sumiraj (int [], int); koja će omogućiti sumiranje svih elementa niza; korisnik bira niz čije elemente treba sumirati;
*/

void unos(int[], int);
void inicijalizacija(int[], int[], int[]);
int sumiraj(int[], int);

const int LENGTH_OF_FIRST_ARRAY = 3;
const int LENGTH_OF_SECOND_ARRAY = 4;
const int LENGTH_OF_THIRD_ARRAY = 7;

int main()
{
	int arr1[LENGTH_OF_FIRST_ARRAY] = {};
	int arr2[LENGTH_OF_SECOND_ARRAY] = {};
	int arr3[LENGTH_OF_THIRD_ARRAY] = {};

	unos(arr1, LENGTH_OF_FIRST_ARRAY);
	unos(arr2, LENGTH_OF_SECOND_ARRAY);
	inicijalizacija(arr1, arr2, arr3);
	cout << "Suma elemenata u prvom nizu iznosi " << sumiraj(arr1, LENGTH_OF_FIRST_ARRAY) << "\n";
	cout << "Suma elemenata u drugom nizu iznosi " << sumiraj(arr2, LENGTH_OF_SECOND_ARRAY) << "\n";
	cout << "Suma elemenata u trecem nizu iznosi " << sumiraj(arr3, LENGTH_OF_THIRD_ARRAY) << "\n";
}

void unos(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		cout << "Unesite vrijednost za index " << i << ": ";
		cin >> arr[i];
	}
}

void inicijalizacija(int source1[], int source2[], int destination[]) {
	for (int i = 0; i < LENGTH_OF_THIRD_ARRAY; i++) {
		if (i >= LENGTH_OF_FIRST_ARRAY) {
			destination[i] = source2[i % 4];
		} else {
			destination[i] = source1[i];
		}
	}
}

int sumiraj(int arr[], int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}
	return sum;
}
