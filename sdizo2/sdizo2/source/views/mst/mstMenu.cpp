#include "stdafx.h"
#include "mstMenu.h"

using namespace std;

void mstMenu::print()
{
	int i = 1;
	cout << i++ << ": Wczytaj graf z pliku" << endl;
	cout << i++ << ": Algorytm Kruskala macierzowo i listowo z wy�wietleniem wynik�w" << endl;
	cout << i++ << ": Algorytm Prima macierzowo i listowo z wy�wieleniem wynik�w" << endl;
	cout << i++ << ": Wygeneruj graf" << endl;
	cout << i++ << ": Wyswietl aktualny graf" << endl;
	cout << "0. Wyjd�" << endl;
}
