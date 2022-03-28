#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "header.h"

using namespace std;

/* Funkcje pomocnicze */
string fKategoria (const vector <komputer> &kopia, const int i) { //DONE
    if (kopia[i].kategoria == 1) return "Procesor";
    else if (kopia[i].kategoria == 2) return "Karta graficzna";
    else if (kopia[i].kategoria == 3) return "Peryferia";
    else if (kopia[i].kategoria == 4) return "Zasilacz";
    else if (kopia[i].kategoria == 5) return "Plyta glowna";
    else if (kopia[i].kategoria == 6) return "Pamiec RAM";
    else if (kopia[i].kategoria == 7) return "Dysk NVMe";
    else if (kopia[i].kategoria == 8) return "Dysk SSD";
    else return "Dysk HDD";
}

string fZamienSpacje (string s) {
    for (unsigned i=0; i<s.size(); i++) {
        if (s[i] == ' ') s[i] = '_';
    }
    return s;
}

string fZamienPodloge (string s) {
    for (unsigned i=0; i<s.size(); i++) {
        if (s[i] == '_') s[i] = ' ';
    }
    return s;
}

int fKategoriaR (string s) {
    if (s == "Procesor") return 1;
    else if (s == "Karta_graficzna") return 2;
    else if (s == "Peryferia") return 3;
    else if (s == "Zasilacz") return 4;
    else if (s == "Plyta_glowna") return 5;
    else if (s == "Pamiec_RAM") return 6;
    else if (s == "Dysk_NVMe") return 7;
    else if (s == "Dysk_SSD") return 8;
    else return 9;
}

void fWyswietl (const vector <komputer> &kopia, const int temp) { //DONE
    cout << "Lp." << "  |  " << "Nazwa" << "  |  " << "Producent" << "  |  " << "Model" << "  |  " << "Kategoria"
         << "  |  " << "Liczba sztuk" << "  |  " << "Cena j." << "  |  " << "Data dostawy" << "  |  " << "Uwagi" << "  |  " << "\n\n";
    for (unsigned i=0; i<kopia.size(); i++) {
        cout << i+1 << ".  |  " << kopia[i].nazwa << "  |  " << kopia[i].producent << "  |  " << kopia[i].model << "  |  "
             << fKategoria(kopia, i) << "  |  " << kopia[i].liczba << "  |  " << kopia[i].cena << "  |  "
             << kopia[i].dostawa.dzien << "\\" << kopia[i].dostawa.miesiac << "\\" << kopia[i].dostawa.rok << "  |  "
             << kopia[i].uwagi << "  |  " << endl;
    }
    if (temp == -1) {
        cout << endl;
        system("pause");
        system("cls");
    }

}

void fWpisz (vector <komputer> &kopia, const int w, const int lp) { //DONE
    if (w == 1) {
        for (;;) {
            cout << "\nWpisz nazwe/serie:\n";
            getline(cin, kopia[lp-1].nazwa);
            transform((kopia[lp-1].nazwa).begin(), (kopia[lp-1].nazwa).end(), (kopia[lp-1].nazwa).begin(), ::toupper);
            if ((kopia[lp-1].nazwa).size() < 257) break;
            else cout << "Wpisano za dluga nazwe/serie. Dozwolone maksymalnie 254 znaki.\n";
        }
    }
    else if (w == 2) {
        for(;;) {
            cout << "\nWpisz producenta:\n";
            getline(cin, kopia[lp-1].producent);
            transform((kopia[lp-1].producent).begin(), (kopia[lp-1].producent).end(), (kopia[lp-1].producent).begin(), ::toupper);
            if ((kopia[lp-1].producent).size() < 257) break;
            else cout << "Wpisano za dluga nazwe producenta. Dozwolone maksymalnie 254 znaki.\n";
        }
    }
    else if (w == 3) {
        for(;;) {
            cout << "\nWpisz model:\n";
            getline(cin, kopia[lp-1].model);
            transform((kopia[lp-1].model).begin(), (kopia[lp-1].model).end(), (kopia[lp-1].model).begin(), ::toupper);
            if ((kopia[lp-1].model).size() < 51) break;
            else cout << "Wpisano za dluga nazwe modelu. Dozwolone maksymalnie 50 znakow.\n";
        }
    }
    else if (w == 8) {
        for(;;) {
            cout << "\nWpisz uwagi (\"nd\" gdy nie dotyczy):\n";
            getline(cin, kopia[lp-1].uwagi);
            if ((kopia[lp-1].model).size() < 1001) break;
            else cout << "Wpisano za dlugi teskt uwag. Dozwolone maksymalnie 1000 znakow.\n";
        }
    }

    else if (w == 4) {
        cout << "\nWpisz cyfre predefiniowanej kategorii:\n\n"
             << "1. Procesor\n"
             << "2. Karta graficzna\n"
             << "3. Peryferia\n"
             << "4. Zasilacz\n"
             << "5. Plyta glowna\n"
             << "6. Pamiec RAM\n"
             << "7. Dysk NVMe\n"
             << "8. Dysk SSD\n"
             << "9. Dysk HDD\n>";
        for (;;) {
            cin >> kopia[lp-1].kategoria;
            cin.get();
            if (kopia[lp-1].kategoria > 0 && kopia[lp-1].kategoria < 10) break;
            else cout << "Wpisano nieprawidlowa wartosc. Sprobuj ponownie.\n>";
        }
    }
    else if (w == 5) {cout << "\nWpisz liczbe sztuk:\n"; cin >> kopia[lp-1].liczba; cin.get();}

    else if (w == 6) {cout << "\nWpisz cene:\n"; cin >> kopia[lp-1].cena; cin.get();}
}

void fDomyslne (vector <komputer> &kopia) { //DONE
    kopia.resize (10);

    kopia[0] = {"AMD", "POWERCOLOR", "RX 5700XT 8GB RED DEVIL", 2, 25, 2499.99, {26,01,2021}, "nd"};
    kopia[1] = {"AMD", "AMD", "RYZEN 5 3600", 1, 69, 999.99, {26,01,2021}, "nd"};
    kopia[2] = {"INTEL", "INTEL", "I9-9990K", 1, 25, 1849.99, {26,01,2021}, "nd"};
    kopia[3] = {"AMD", "GIGABYTE", "RX 580 8GB GAMING", 2, 25, 1099.99, {26,01,2021}, "nd"};
    kopia[4] = {"SPC GEAR", "SILENTIUMPC", "GK540", 3, 25, 239.99, {26,01,2021}, "nd"};
    kopia[5] = {"BLOODY", "A4TECH", "V7", 3, 25, 69.99, {26,01,2021}, "nd"};
    kopia[6] = {"SPC", "SILENTIUMPC", "FM2 750W", 4, 25, 429.99, {26,01,2021}, "nd"};
    kopia[7] = {"MPG", "MSI", "X570 GAMING PLUS", 5, 25, 849.99, {26,01,2021}, "nd"};
    kopia[8] = {"VIPER", "PATRIOT", "STEEL 3200MHZ 8GB", 6, 25, 179.99, {26,01,2021}, "nd"};
    kopia[9] = {"XPG", "ADATA", "SX8200 512GB", 7, 25, 309.99, {26,01,2021}, "nd"};
}

/* Funkcje glowne */
void fDodaj (vector <komputer> &kopia) { //DONE
    int temp, l = 0;
    cout << "Ile rekordow chcesz dodac?\n>";
    cin >> temp;
    cin.get();
    kopia.resize (kopia.size()+temp);
    system("cls");
    for (unsigned i=kopia.size()-temp; i<kopia.size(); i++) {
        l++;
        cout << "Dodajesz rekord " << l << "/" << temp << endl;
        for (int w=1; w<7; w++) {
            fWpisz(kopia, w, i+1);
        }
        fZmienDate (kopia, i+1);
        fWpisz (kopia, 8, i+1);
        system("cls");
    }
    system("cls");
    cout << "Operacja zakonczona sukcesem.\n\n";
}

void fUsun (vector <komputer> &kopia) { //DONE
    unsigned lp;
    if (kopia.size() == 0) {
        system("cls");
        cout << "Baza jest pusta. Brak elementow do usuniecia.\n\n";
    }
    else {
        fWyswietl(kopia, 0);
        for (;;) {
            cout << "\nWpisz liczbe porzadkowa produktu, ktory chcesz usunac (0, jesli chcesz anulowac): ";
            cin >> lp;
            if (lp < kopia.size()+1 && lp > 0) {
                    kopia.erase(kopia.begin()+lp-1);
                    break;
            }
            else if (lp == 0) break;
            else cout << "Wpisana wartosc nie istnieje. Sprobuj ponownie.\n";
        }
        system("cls");
        cout << "Operacja zakonczona sukcesem.\n\n";
    }
}

void fZmienDane (vector <komputer> &kopia) { //DONE
    unsigned lp, wybor;
    if (kopia.size() == 0) {
        system("cls");
        cout << "Baza jest pusta. Brak elementow do zmiany.\n\n";
    }
    else {
    fWyswietl(kopia, 0);
    for (;;) {
        cout << "\nWpisz liczbe porzadkowa produktu, w ktorym chcesz dodac/zmienic dane: ";
        cin >> lp;
        if (lp < kopia.size()+1 && lp > 0) {
            cout << "\n1. Nazwa/seria\n"
                 << "2. Producent\n"
                 << "3. Model\n"
                 << "4. Kategoria\n"
                 << "5. Liczba sztuk w magazynie\n"
                 << "6. Cena jednostokowa\n"
                 << "7. Data dostawy\n"
                 << "8. Uwagi\n\n"
                 << "9. Anuluj\n>";
            for (;;) {
            cin >> wybor;
            cin.get();
            if (wybor > 0 && wybor < 9 && wybor != 7) {
                fWpisz(kopia, wybor, lp);
                break;
            }
            else if (wybor == 7) {fZmienDate (kopia, lp); break;}
            else if (wybor == 9) break;
            else cout << "Wpisano nieprawidlowa wartosc. Sprobuj ponownie.\n>";
            }
            system ("cls");
            cout << "Operacja zakonczona sukcesem.\n\n";
            break;
        }
        else cout << "Wpisana wartosc nie istnieje. Sprobuj ponownie.\n";
   }}
}

void fZmienDate (vector <komputer> &kopia, unsigned lp) { //DONE
    if (kopia.size() == 0) {
        system("cls");
        cout << "Baza jest pusta. Brak elementow do zmiany.\n\n";
    }
    else {
    if (lp == -1) {
        fWyswietl(kopia, 0);
        for (;;) {
            cout << "\nWpisz liczbe porzadkowa produktu, w ktorym chcesz dodac/zmienic date dostawy: ";
            cin >> lp;

            if (lp < kopia.size()+1 && lp > 0) {
                cout << "\nAktualna data dostawy: " << kopia[lp-1].dostawa.dzien << "\\" << kopia[lp-1].dostawa.miesiac << "\\" << kopia[lp-1].dostawa.rok << endl;
                for (;;) {
                    cout << "\nWpisz nowy dzien dostawy [dd] (0 gdy chcesz usunac/pominac):\n";
                    cin >> kopia[lp-1].dostawa.dzien;
                    if (kopia[lp-1].dostawa.dzien > -1 && kopia[lp-1].dostawa.dzien < 32) break;
                    else cout << "Wpisano niemozliwy wariant. Sprobuj ponownie.\n";
                }
                if (kopia[lp-1].dostawa.dzien != 0) {
                    for (;;) {
                        cout << "\nWpisz nowy miesiac dostawy [mm]:\n";
                        cin >> kopia[lp-1].dostawa.miesiac;
                        if (kopia[lp-1].dostawa.miesiac > 0 && kopia[lp-1].dostawa.miesiac < 13) break;
                        else cout << "Wpisano niemozliwy wariant. Sprobuj ponownie.\n";
                    }
                    for (;;) {
                        cout << "\nWpisz nowy rok dostawy [rrrr]:\n";
                        cin >> kopia[lp-1].dostawa.rok;
                        if (kopia[lp-1].dostawa.rok > 2020 && kopia[lp-1].dostawa.rok < 9999) break;
                       else cout << "Wpisano niemozliwy wariant. Sprobuj ponownie.\n";
                    }
                }
                else {kopia[lp-1].dostawa.miesiac = 0; kopia[lp-1].dostawa.rok = 0;}
                system ("cls");
                cout << "Operacja zakonczona sukcesem.\n\n";
                break;
            }
            else cout << "Wpisana wartosc nie istnieje. Sprobuj ponownie.\n";
        }
    }
    else {
        for (;;) {
            cout << "\nAktualna data dostawy: " << kopia[lp-1].dostawa.dzien << "\\" << kopia[lp-1].dostawa.miesiac << "\\" << kopia[lp-1].dostawa.rok << endl;
            for (;;) {
                cout << "\nWpisz nowy dzien dostawy [dd] (0 gdy chcesz usunac/pominac):\n";
                cin >> kopia[lp-1].dostawa.dzien;
                cin.get();
                if (kopia[lp-1].dostawa.dzien > -1 && kopia[lp-1].dostawa.dzien < 32) break;
                else cout << "Wpisano niemozliwy wariant. Sprobuj ponownie.\n";
            }
            if (kopia[lp-1].dostawa.dzien != 0) {
                for (;;) {
                    cout << "\nWpisz nowy miesiac dostawy [mm]:\n";
                    cin >> kopia[lp-1].dostawa.miesiac;
                    if (kopia[lp-1].dostawa.miesiac > 0 && kopia[lp-1].dostawa.miesiac < 13) break;
                    else cout << "Wpisano niemozliwy wariant. Sprobuj ponownie.\n";
                }
                for (;;) {
                    cout << "\nWpisz nowy rok dostawy [rrrr]:\n";
                    cin >> kopia[lp-1].dostawa.rok;
                    cin.get();
                    if (kopia[lp-1].dostawa.rok > 2020 && kopia[lp-1].dostawa.rok < 9999) break;
                    else cout << "Wpisano niemozliwy wariant. Sprobuj ponownie.\n";
                }
            }
            else {kopia[lp-1].dostawa.miesiac = 0; kopia[lp-1].dostawa.rok = 0;}
            break;
       }
   }}
}

void fWyszukaj (vector <komputer> &kopia) { //DONE
    int wybor;
    string fraza;
    cout << "Po czym chcesz filtrowac/wyszukac?\n"
         << "1. Nazwa\n"
         << "2. Producent\n"
         << "3. Model\n>";
    for (;;) {
        cin >> wybor;
        cin.get();
        if (wybor < 4 && wybor > 0) {
            if (wybor == 1) {
                cout << "\nWpisz szukana fraze: \n";
                getline(cin, fraza);
                transform(fraza.begin(), fraza.end(), fraza.begin(), ::toupper);
                system("cls");
                cout << "Lp." << "  |  " << "Nazwa" << "  |  " << "Producent" << "  |  " << "Model" << "  |  " << "Kategoria"
                << "  |  " << "Liczba sztuk" << "  |  " << "Cena j." << "  |  " << "Data dostawy" << "  |  " << "Uwagi" << "  |  " << "\n\n";
                for (unsigned i=0; i<kopia.size(); i++) {
                    if ((kopia[i].nazwa).find(fraza) != string::npos) {
                        cout << i+1 << ".  |  " << kopia[i].nazwa << "  |  " << kopia[i].producent << "  |  " << kopia[i].model << "  |  "
                             << fKategoria(kopia, i) << "  |  " << kopia[i].liczba << "  |  " << kopia[i].cena << "  |  "
                             << kopia[i].dostawa.dzien << "\\" << kopia[i].dostawa.miesiac << "\\" << kopia[i].dostawa.rok << "  |  "
                             << kopia[i].uwagi << "  |  " << endl;
                    }
                }
            }
            else if (wybor == 2) {
                cout << "\nWpisz szukana fraze: \n";
                getline(cin, fraza);
                transform(fraza.begin(), fraza.end(), fraza.begin(), ::toupper);
                system("cls");
                cout << "Lp." << "  |  " << "Nazwa" << "  |  " << "Producent" << "  |  " << "Model" << "  |  " << "Kategoria"
                << "  |  " << "Liczba sztuk" << "  |  " << "Cena j." << "  |  " << "Data dostawy" << "  |  " << "Uwagi" << "  |  " << "\n\n";
                for (unsigned i=0; i<kopia.size(); i++) {
                    if ((kopia[i].producent).find(fraza) != string::npos) {
                        cout << i+1 << ".  |  " << kopia[i].nazwa << "  |  " << kopia[i].producent << "  |  " << kopia[i].model << "  |  "
                             << fKategoria(kopia, i) << "  |  " << kopia[i].liczba << "  |  " << kopia[i].cena << "  |  "
                             << kopia[i].dostawa.dzien << "\\" << kopia[i].dostawa.miesiac << "\\" << kopia[i].dostawa.rok << "  |  "
                             << kopia[i].uwagi << "  |  " << endl;
                    }
                }
            }
            else {
                cout << "\nWpisz szukana fraze: \n";
                getline(cin, fraza);
                transform(fraza.begin(), fraza.end(), fraza.begin(), ::toupper);
                system("cls");
                cout << "Lp." << "  |  " << "Nazwa" << "  |  " << "Producent" << "  |  " << "Model" << "  |  " << "Kategoria"
                << "  |  " << "Liczba sztuk" << "  |  " << "Cena j." << "  |  " << "Data dostawy" << "  |  " << "Uwagi" << "  |  " << "\n\n";
                for (unsigned i=0; i<kopia.size(); i++) {
                    if ((kopia[i].model).find(fraza) != string::npos) {
                        cout << i+1 << ".  |  " << kopia[i].nazwa << "  |  " << kopia[i].producent << "  |  " << kopia[i].model << "  |  "
                             << fKategoria(kopia, i) << "  |  " << kopia[i].liczba << "  |  " << kopia[i].cena << "  |  "
                             << kopia[i].dostawa.dzien << "\\" << kopia[i].dostawa.miesiac << "\\" << kopia[i].dostawa.rok << "  |  "
                             << kopia[i].uwagi << "  |  " << endl;
                    }
                }
            }
            cout << endl;
            system("pause");
            system("cls");
            break;
            }
        else cout << "Wpisano nieprawidlowa wartosc. Sprobuj ponownie.\n>";
        }
}

void fZapisz (vector <komputer> &kopia) { //DONE
    char wybor;
    ofstream plik ("baza.txt");
    for (unsigned i=0; i<kopia.size(); i++) {
        plik << fZamienSpacje(kopia[i].nazwa) << " " << fZamienSpacje(kopia[i].producent) << " " << fZamienSpacje(kopia[i].model) << " "
             << fZamienSpacje(fKategoria(kopia, i)) << " " << kopia[i].liczba << " " << kopia[i].cena << " "
             << kopia[i].dostawa.dzien << " " << kopia[i].dostawa.miesiac << " " << kopia[i].dostawa.rok << " "
             << fZamienSpacje(kopia[i].uwagi) << " " << "\n";
    }
    plik.close();
    system("cls");
    cout << "Operacja zakonczona sukcesem.\n\n";
    for (;;) {
        cout << "Chcesz otworzyc utworzony plik? (T/N): ";
        cin >> wybor;
        if (wybor == 'T' || wybor == 't') {system("baza.txt"); system("cls"); break;}
        else if (wybor == 'N' || wybor == 'n') {system("cls"); break;}
        else cout << "Wpisano zly znak. Sprobuj jeszcze raz";
    }
}

void fWczytaj (vector <komputer> &kopia) { //DONE
	int wybor;
	cout << "Chcesz nadpisac baze czy dodac rekordy do juz istniejacej?\n";
	for(;;) {
        cout << "1. Nadpisac\n"
             << "2. Dodac\n>";
        cin >> wybor;
        if (wybor == 1) {kopia.clear(); break;}
        else if (wybor == 2) break;
        else cout << "\nWpisano nieprawidlowa wartosc. Sprobuj ponownie.\n";
	}


	ifstream plik("baza.txt");
	if(plik.is_open()) {
        vector <string> s(0);
        string temp;
        while (!plik.eof()) {
            getline(plik, temp);
            s.push_back (temp);
        }
        kopia.resize(kopia.size()+s.size()-1);

        stringstream ss;
        vector <string> kategoria(s.size()-1);
        for (unsigned i=0; i<s.size()-1; i++) {
            ss << s[i];
            ss >> kopia[kopia.size()-s.size()+1+i].nazwa >> kopia[kopia.size()-s.size()+1+i].producent >> kopia[kopia.size()-s.size()+1+i].model
               >> kategoria[i] >> kopia[kopia.size()-s.size()+1+i].liczba >>  kopia[kopia.size()-s.size()+1+i].cena
               >> kopia[kopia.size()-s.size()+1+i].dostawa.dzien >> kopia[kopia.size()-s.size()+1+i].dostawa.miesiac >> kopia[kopia.size()-s.size()+1+i].dostawa.rok
               >> kopia[kopia.size()-s.size()+1+i].uwagi;

            kopia[kopia.size()-s.size()+1+i].kategoria = fKategoriaR(kategoria[i]);
            kopia[kopia.size()-s.size()+1+i].nazwa = fZamienPodloge(kopia[kopia.size()-s.size()+1+i].nazwa);
            kopia[kopia.size()-s.size()+1+i].producent = fZamienPodloge(kopia[kopia.size()-s.size()+1+i].producent);
            kopia[kopia.size()-s.size()+1+i].model = fZamienPodloge(kopia[kopia.size()-s.size()+1+i].model);
        }
        system("cls");
        cout << "Operacja zakonczona sukcesem.\n\n";
    }
	else {
		system("cls");
		cout<<"Plik nie istnieje.\n\n";
	}
}
