#include <iostream>
#include <fstream>

using namespace std;

string imie, nazwisko;
int telefon;

int main()
{
    cout << "Witytowka" << endl;
    cout << "Podaj imie: " << endl; cin >> imie;
    cout << "Podaj nazwisko: " << endl; cin >> nazwisko;
    cout << "Podaj nr telefonu: " << endl; cin >> telefon;

    fstream plik;

    return 0;
}
