#include <iostream>
#include <string>

using namespace std;

void dodajOsobe(string* tabI, string* tabN, int* tabIdx, bool* tabO, int* n, int max) {
    if (*n < max) {
        cout << "Imie: "; cin >> tabI[*n];
        cout << "Nazwisko: "; cin >> tabN[*n];
        cout << "Indeks: "; cin >> tabIdx[*n];
        tabO[*n] = false;
        (*n)++; 
    }
    else {
        cout << "Brak miejsca!" << endl;
    }
}

void ustawObecnosc(string* tabN, bool* tabO, int n) {
    string szukane;
    cout << "Podaj nazwisko (KLUCZ): "; cin >> szukane;
    for (int i = 0; i < n; i++) {
        if (tabN[i] == szukane) {
            int status;
            cout << "Obecny? (1-tak, 0-nie): "; cin >> status;
            tabO[i] = (status == 1);
            return;
        }
    }
    cout << "Nie znaleziono!" << endl;
}

void usunOsobe(string* tabI, string* tabN, int* tabIdx, bool* tabO, int* n) {
    string szukane;
    cout << "Nazwisko do usuniecia: "; cin >> szukane;
    for (int i = 0; i < *n; i++) {
        if (tabN[i] == szukane) {
            
            for (int j = i; j < (*n) - 1; j++) {
                tabI[j] = tabI[j + 1];
                tabN[j] = tabN[j + 1];
                tabIdx[j] = tabIdx[j + 1];
                tabO[j] = tabO[j + 1];
            }
            (*n)--; 
            cout << "Usunieto." << endl;
            return;
        }
    }
}

void drukujListe(string* tabI, string* tabN, int* tabIdx, bool* tabO, int n) {
    if (n == 0) cout << "Lista jest pusta!" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << tabI[i] << " " << tabN[i]
            << " [" << tabIdx[i] << "] - " << (tabO[i] ? "Obecny" : "---") << endl;
    }
}
void edytujOsobe(string* tabI, string* tabN, int* tabIdx, int n) {
    string klucz;
    cout << "Podaj nazwisko osoby do edycji: ";
    cin >> klucz;

    for (int i = 0; i < n; i++) {
        if (tabN[i] == klucz) {
            cout << "Edytujesz dane studenta: " << tabN[i] << endl;
            cout << "Nowe imie: ";
            cin >> tabI[i];
            cout << "Nowe nazwisko: ";
            cin >> tabN[i];
            cout << "Nowy nr indeksu: ";
            cin >> tabIdx[i];

            cout << "Dane zostaly pomyslnie zaktualizowane." << endl;
            return;
        }
    }
    cout << "Blad: Nie znaleziono osoby o takim nazwisku." << endl;
}

int main() {
    const int MAX = 10;
    string tImie[MAX];
    string tNazwisko[MAX];
    int tIndeks[MAX];
    bool tObecnosc[MAX];
    int n = 0;
    int wybor;

    do {
        cout << "\n1.Dodaj osobe 2. Sprawdz obecnosc 3.Lista osob 4.Usuwanie osob 5. edycja osoby 6.Wyjscie: ";
        cin >> wybor;
        switch (wybor) {
        case 1:
            dodajOsobe(tImie, tNazwisko, tIndeks, tObecnosc, &n, MAX);
            break;
        case 2:
            ustawObecnosc(tNazwisko, tObecnosc, n);
            break;
        case 3:
            drukujListe(tImie, tNazwisko, tIndeks, tObecnosc, n);
            break;
        case 4:
            usunOsobe(tImie, tNazwisko, tIndeks, tObecnosc, &n);
            break;
        case 5:
            edytujOsobe(tImie, tNazwisko, tIndeks, n);
            break;
        case 6:
            cout << "Zamykam program";
            break;
        default:
            cout << "Niemozliwy wybor";
        }

    } while (wybor != 6);

    return 0;
}