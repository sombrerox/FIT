#include <iostream> 

using namespace std;

/*
Source: https://github.com/FITCommunity/Programiranje-1/blob/master/POSTAVKE.md
Napišite program u kojem ćete :

omogućiti unos niza od 5 isključivo malih slova pomoću funkcije: void unos (char [], int);
definirati i upotrijebiti funkciju void promijeni(char [], int [], int); koja će unesene karaktere (slova) promijeniti u odgovarajuće cijele brojeve (prema ASCII kodnoj shemi) i smjestiti ih u zaseban niz.
definirati i upotrijebiti funkciju void binarni(int [], int); u kojoj će niz prethodno dobivenih cijelih brojeva pretvoriti u ekvivalentne binarne brojeve (binarne brojeve smjestiti u isti niz u kojem su bile ASCII vrijednosti).
Upotrijebite funkciju bin (funkciju ne treba prepisivati) čija je zadaća da pretvara jedan cijeli broj u binarni i izgleda ovako:
int bin(int broj)
{
    int binarni = 0, ostatak, brojac = 0;
    while(broj > 0)
    {
        ostatak = broj % 2;
        binarni = binarni + ostatak * pow(10.0, brojac);
        brojac++;
        broj /= 2;
    }
    return binarni;
}
*/

void unos(char[], int);
void promijeni(char[], int[], int);
void binarni(int[], int);
int bin(int);

const int ARRAY_SIZE = 5;

int main()
{
    char charArr[ARRAY_SIZE] = {};
    int intArr[ARRAY_SIZE] = {};

    unos(charArr, ARRAY_SIZE);
    promijeni(charArr, intArr, ARRAY_SIZE);
    binarni(intArr, ARRAY_SIZE);
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << intArr[i] << "\n";
    }
}

void unos(char arr[], int length) {
    int count = 0;

    while (count != 5) {
        cout << "Unesite malo slovo: ";
        char character;
        cin >> character;
        if (character < 97 || character > 122) {
            cout << "Niste unijeli malo slovo." << "\n";
            continue;
        }
        arr[count++] = character;
    }
}

void promijeni(char charArr[], int intArr[], int length) {
    for (int i = 0; i < length; i++) {
        intArr[i] = (int)charArr[i];
    }
}

void binarni(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = bin(arr[i]);
    }
}

int bin(int broj)
{
    int binarni = 0, ostatak, brojac = 0;
    while (broj > 0)
    {
        ostatak = broj % 2;
        binarni = binarni + ostatak * pow(10.0, brojac);
        brojac++;
        broj /= 2;
    }
    return binarni;
}
