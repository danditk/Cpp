#include <iostream>

using namespace std;

int ile; // alokowac pamieci na tablice

int main()
{
    cout << "Ile liczb w tablicy: ";
    cin >> ile;

    int *tablica; // nazwa wskaznika
    tablica = new int [ile]; // nowy obszar w pamieci

    for(int i=0; i<ile; i++){
        cout << "Numer wskaznika: " << *tablica << endl; // zmienna przedstawia numer wskaznika
        cout << "16'tkowa Przekonwertowana na int: " << (int)tablica << endl; //numer zmiennej przekonwertowany na liczbe
        cout << "16'tkowa: " << tablica << endl; //numer zmiennej alokowanej jako liczba 16 tkowa
        tablica++; // zwiêkszanie numetu zmiennej w tablicy do momentu osiagniecia porzadanej przez uzytkownika rezerwacji w pamieci
    }

    delete [] tablica; // na koniec usun tablice [] o nazwie tablica, konieczne czyszczenie pamieci

    return 0;
}
