#include <iostream>
#include <string>

using namespace std;

class Osoba {
private:
    string imie;
    string nazwisko;
    int indeks;

public:
    int setImie(string wartosc) {
        if (wartosc.length() < 3) { 
            return -1;
        }
        imie = wartosc;
        return 0;
    }

    void setNazwisko(string wartosc) {
        nazwisko = wartosc;
    }

    void setIndeks(int wartosc) {
        indeks = wartosc;
    }

    string getNazwisko() {
        return nazwisko;
    }

    void wyswietl() {
        cout << imie << " " << nazwisko << " (Nr indeksu: " << indeks << ")" << endl;
    }
};


void wczytajImie(Osoba& os) {
    string temp;
    do {
        cout << "Podaj imie (min. 3 znaki): ";
        cin >> temp;
        if (os.setImie(temp) == -1) {
            cout << "Blad: Imie za krotkie!" << endl;
        }
        else {
            break;
        }
    } while (true);
}

void dodajOsobe(Osoba* tab, int* n, int max) {
    if (*n < max) {
        string t_nazwisko;
        int t_indeks;

        wczytajImie(tab[*n]); 

        cout << "Nazwisko: ";
        cin >> t_nazwisko;
        tab[*n].setNazwisko(t_nazwisko);

        cout << "Indeks: ";
        cin >> t_indeks;
        tab[*n].setIndeks(t_indeks);

        (*n)++;
    }
    else {
        cout << "Brak miejsca!" << endl;
    }
}

void edytujOsobe(Osoba* tab, int n) {
    string klucz;
    cout << "Podaj nazwisko osoby do edycji: ";
    cin >> klucz;

    for (int i = 0; i < n; i++) {
        if (tab[i].getNazwisko() == klucz) {
            string t_nazwisko;
            int t_indeks;

            wczytajImie(tab[i]);

            cout << "Nowe nazwisko: ";
            cin >> t_nazwisko;
            tab[i].setNazwisko(t_nazwisko);

            cout << "Nowy nr indeksu: ";
            cin >> t_indeks;
            tab[i].setIndeks(t_indeks);

            cout << "Dane zostaly zaktualizowane." << endl;
            return;
        }
    }
    cout << "Blad: Nie znaleziono osoby." << endl;
}

void usunOsobe(Osoba* tab, int* n) {
    string klucz;
    cout << "Nazwisko do usuniecia: "; cin >> klucz;
    for (int i = 0; i < *n; i++) {
        if (tab[i].getNazwisko() == klucz) {
            for (int j = i; j < (*n) - 1; j++) {
                tab[j] = tab[j + 1];
            }
            (*n)--;
            cout << "Usunieto." << endl;
            return;
        }
    }
}

void drukujListe(Osoba* tab, int n) {
    if (n == 0) {
        cout << "Lista jest pusta!" << endl;
        return;
    }
    cout << "\nLista studentow: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". ";
        tab[i].wyswietl();
    }
}

int main() {
    const int MAX = 10;
    Osoba grupa[MAX];
    int n = 0;
    int wybor;

    do {
        cout << "\n1. Dodaj | 2. Edytuj | 3. Usun | 4. Lista | 5. Wyjscie\nWybor: ";
        if (!(cin >> wybor)) break;

        switch (wybor) {
        case 1: dodajOsobe(grupa, &n, MAX); break;
        case 2: edytujOsobe(grupa, n); break;
        case 3: usunOsobe(grupa, &n); break;
        case 4: drukujListe(grupa, n); break;
        case 5: cout << "Zamykam program..." << endl; break;
        default: cout << "Niepoprawny wybor!" << endl;
        }
    } while (wybor != 5);

    return 0;
}