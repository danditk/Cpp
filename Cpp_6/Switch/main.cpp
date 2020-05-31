#include <iostream>

using namespace std;

int dzialanie=1;
float liczba1, liczba2, wynik;

int main()
{
    cout << "Wprowadz liczbe 1: "; cin >> liczba1;
    cout << "Wprowadz liczbe 2: "; cin >> liczba2;

    while(dzialanie != 0){

        cout << endl << "1. Dodawanie";
        cout << endl << "2. Odejmowanie";
        cout << endl << "3. Mnozenie";
        cout << endl << "4. Dzielenie";
        cout << endl << "0. Wyjscie";
        cout << endl << "wybierz dzialanie: "; cin >> dzialanie;

        switch(dzialanie){
        case 1:
            wynik = liczba1 + liczba2;
            cout << endl << "Wynik dodawania to: " << wynik;
            break;
        case 2:
            wynik = liczba1 - liczba2;
            cout << endl << "Wynik odejmowania to: " << wynik;
            break;
        case 3:
            wynik = liczba1 * liczba2;
            cout << endl << "Wynik mnozenia to: " << wynik;
            break;
        case 4:
            wynik = liczba1 / liczba2;
            cout << endl << "Wynik dzielenia to: " << wynik;
            break;
        default:
            break;
        }

    }


    return 0;


}
