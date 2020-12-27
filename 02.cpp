#include <iostream> 

using namespace std;

/*
Source: https://github.com/FITCommunity/Programiranje-1/blob/master/POSTAVKE.md
Napišite program u kojem ćete deklarirati matricu 5x4. Redak u matrici je učenik, a kolona predmet. Uz pomoć funkcije:

void unos (int [] [4]); omogućite unos samo prolaznih ocjena (2-5) za sve učenike;
float prosjek(int []); izračunati prosječnu ocjenu učenika; za kojeg od učenika će se računati prosjek bira korisnik;
int prebroji (int [][4], int); prebrojati koliko učenika ima ocjenu 4 i više na predmetu po izboru korisnika.
*/

void unos(int[][4]);
float prosjek(int[]);
int prebroji(int[][4], int);

const int NUM_OF_STUDENTS = 5;
const int NUM_OF_CLASSES = 4;

int main()
{
	int data[5][4] = {};
	unos(data);
	int studentIndex;
	cout << "Unesi index ucenika od koga zelis znati prosjek: ";
	cin >> studentIndex;
	cout << "Prosjek ocjena za ucenika sa indexom " << studentIndex << " je: " << prosjek(data[studentIndex]) << "\n";
	int classIndex;
	cout << "Unesi index predmeta za koji zelis znati broj ucenika sa ocjenom 4 ili vecom: ";
	cin >> classIndex;
	cout << "Za predmet sa indexom " << classIndex << " ukupno ima " << prebroji(data, classIndex) << " ucenika sa ocjenom 4 ili vecom.";
}

void unos(int data[][NUM_OF_CLASSES]) {
	for (int i = 0; i < NUM_OF_STUDENTS; i++) {
		for (int j = 0; j < NUM_OF_CLASSES; j++) {
			cout << "Unesite prolaznu ocjenu za ucenika sa indexom " << i << " za predmet sa indeksom " << j << ": ";
			int grade;
			cin >> grade;
			if (grade < 2) {
				cout << "Ocjena nije prolazna!" << "\n";
				j--;
				continue;
			}
			data[i][j] = grade;
		}
	}
}

float prosjek(int data[]) {
	double sumOfGrades = 0.0;
	for (int i = 0; i < NUM_OF_CLASSES; i++) {
		sumOfGrades += data[i];
	}
	return sumOfGrades / NUM_OF_CLASSES;
}

int prebroji(int data[][4], int classIndex) {
	int count = 0;
	for (int i = 0; i < NUM_OF_STUDENTS; i++) {
		if (data[i][classIndex] >= 4) {
			count++;
		}
	}
	return count;
}

