#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <conio.h>

using namespace std;

ifstream fman("Mancare.txt");
ifstream fbau("Bauturi.txt");

int man_nmax = 0;
int bau_nmax = 0;

float nota_plata = 0;

struct mancare {
	float pret;
	char nume[25];
	char categorie[50];
}man[50];

struct bauturi {
	float pret;
	char nume[25];
	char categorie[50];
}bau[50];

void citire_mancare() {
	while (fman >> man[man_nmax].nume >> man[man_nmax].pret >> man[man_nmax].categorie) {
		man_nmax++;
	}
}

void citire_bauturi() {
	while (fbau >> bau[bau_nmax].nume >> bau[bau_nmax].pret >> bau[bau_nmax].categorie) {
		bau_nmax++;
	}
}

void prima_pagina() {
	cout << "MENIU" << endl << endl;
	cout << "MANCARE : 1" << endl;
	cout << "BAUTURI : 2" << endl;
	cout << "Nota = " << nota_plata << " " << "RON" << endl << endl;
}

void MANCARE() {
	for (int i = 0; i < man_nmax; i++) {
		cout << i + 1 << '.' << "  " << man[i].nume << "  " << man[i].pret << endl;
	}
}

void BAUTURI() {
	for (int i = 0; i < bau_nmax; i++) {
		cout << i + 1 << '.' << "  " << bau[i].nume << "  " << bau[i].pret << endl;
	}
}

int main() {
	bool ok = true;
	citire_mancare();
	citire_bauturi();

	prima_pagina();

	while (ok == true) {
		char input = _getch();

		switch (input) {

		case('1'): {
			MANCARE();
			cout << endl;
			char input = _getch();
			switch (input)
			{
			case('1'):
				nota_plata += man[0].pret;
				break;
			case('2'):
				nota_plata += man[1].pret;
				break;
			case('3'):
				nota_plata += man[2].pret;
				break;
			case('4'):
				nota_plata += man[3].pret;
				break;
			case('5'):
				nota_plata += man[4].pret;
				break;
			}
			cout << "Apasa 'l' pentru a plati sau 'f' pentru a te inoarce la meniul principal" << "   " << endl << endl;
			char def = _getch();
			if (def == 'l') {
				cout << "Nota de plata este " << nota_plata << " RON" << endl << endl;
				ok = false;
			}
			else if (def == 'f')
				prima_pagina();
			break;
		}
		case('2'): {
			BAUTURI();
			cout << endl;
			char input = _getch();
			switch (input)
			{
			case('1'):
				nota_plata += bau[0].pret;
				break;
			case('2'):
				nota_plata += bau[1].pret;
				break;
			case('3'):
				nota_plata += bau[2].pret;
				break;
			case('4'):
				nota_plata += bau[3].pret;
				break;
			case('5'):
				nota_plata += bau[4].pret;
				break;
			}
			cout << "Apasa 'l' pentru a plati sau 'f' pentru a te inoarce la meniul principal" << "   " << endl << endl;
			char def = _getch();
			if (def == 'l') {
				cout << "Nota de plata este " << nota_plata << " RON" << endl << endl;
				ok = false;
			}
			else if (def == 'f')
				prima_pagina();
			break;
		}
		}
	}
}