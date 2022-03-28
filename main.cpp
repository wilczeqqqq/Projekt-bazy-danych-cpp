#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "header.h"

using namespace std;

/* Wykona³: Filip Dowhan 259683
   Data: 25.01.2021 r. */

int main() {

    /* Deklaracja zmiennych */

    int wybor;
    char warunek = 'N';
    vector <komputer> czesci(0);

    /* Wpisanie 10 przykladowych rekordow */

    for (;;) {
        char temp;
        cout << "Zaladowac domyslna baze danych? (T/N): ";
        cin >> temp;

        if (temp == 't' || temp == 'T' ) {fDomyslne(czesci); break;}
        else if (temp == 'n' || temp == 'N') break;
        else cout << "\nWpisano zly znak. Sprobuj jeszcze raz\n";
    }

    system ("cls");

    /* Cialo programu */

    while (warunek == 'N' || warunek == 'n') {
        cout << "======================================\n"
             << "PC PARTS DATABASE build 21012021-final\n"
             << "======================================\n"
             << endl;

        cout << "Wybierz opcje:\n\n"
             << "1. Wyswietl zawartosc bazy\n"
             << "2. Dodaj produkt\n"
             << "3. Usun produkt\n"
             << "4. Zmien dane produktu\n"
             << "5. Dodaj/zmien date dostawy\n"
             << "6. Wyszukaj produkt\n"
             << "7. Zapisz baze na dysku\n"
             << "8. Wczytaj baze z dysku\n"
             << "\n9. Zakoncz program\n>";
        cin >> wybor;

        if (wybor > 9 || wybor < 1) cout << "ERROR!";
        else {
            if (wybor == 1) {system ("cls"); fWyswietl (czesci);}
            else if (wybor == 2) {system ("cls"); fDodaj (czesci);}
            else if (wybor == 3) {system ("cls"); fUsun (czesci);}
            else if (wybor == 4) {system ("cls"); fZmienDane (czesci);}
            else if (wybor == 5) {system ("cls"); fZmienDate (czesci);}
            else if (wybor == 6) {system ("cls"); fWyszukaj (czesci);}
            else if (wybor == 7) {system ("cls"); fZapisz (czesci);}
            else if (wybor == 8) {system ("cls"); fWczytaj (czesci);}
            else if (wybor == 9) {
                 for (;;) {
                 cout << "\nCzy na pewno chcesz zakonczyc? (T/N): ";
                 cin >> warunek;

                 if (warunek == 'T' || warunek == 't') return 0;
                 else if (warunek == 'N' || warunek == 'n') {system("cls"); break;}
                 else cout << "Wpisano zly znak. Sprobuj jeszcze raz";
                 }
            }
        }
    }
}
