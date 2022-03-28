#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

using namespace std;

namespace A {
    struct data {
        int dzien;
        int miesiac;
        int rok;
    };
}


struct komputer {
    string nazwa;
    string producent;
    string model;
    int kategoria;
    int liczba;
    double cena;
    A::data dostawa;
    string uwagi;
};

string fKategoria (const vector <komputer> &kopia, const int i);

string fZamienSpacje (string s);

string fZamienPodloge (string s);

int fKategoriaR (string s);

void fWyswietl (const vector <komputer> &kopia, const int temp = -1);

void fWpisz (vector <komputer> &kopia, const int w, const int lp);

void fDomyslne (vector <komputer> &kopia);

void fDodaj (vector <komputer> &kopia);

void fUsun (vector <komputer> &kopia);

void fZmienDane (vector <komputer> &kopia);

void fZmienDate (vector <komputer> &kopia, unsigned lp = -1);

void fWyszukaj (vector <komputer> &kopia);

void fZapisz (vector <komputer> &kopia);

void fWczytaj(vector <komputer> &kopia);

#endif // HEADER_H_INCLUDED
