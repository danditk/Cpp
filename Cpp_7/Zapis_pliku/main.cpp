#include <iostream>
#include <fstream>

using namespace std;

string imie, nazwisko;
int telefon;

int main()
{
    cout << "Witytowka" << endl;
    cout << "Podaj imie: "; cin >> imie;
    cout << "Podaj nazwisko: "; cin >> nazwisko;
    cout << "Podaj nr telefonu: "; cin >> telefon;

    fstream plik;
    // plik.open("wizytowka.txt", ios::out); imput output streem::output - do stworzenia nowego pliku i nadpisania zawarto�ci starego
    plik.open("wizytowka.txt", ios::out | ios::app); // ::append (za��cz) Kiedy chcemy dopisa� dane do pliku

    plik << imie << endl;
    plik << nazwisko << endl;
    plik << telefon << endl;

    plik.close();

    return 0;
}
