#include <iostream>
#include <cstdlib>


using namespace std;

int ile; // alokowac pamieci na tablice

int *wskaznik, zmienna;
int zmiennaWskaznikowa;

int funkcja( int *wskaznikFunkcji ){
    *wskaznikFunkcji = 5;
    cout << "Wskaznik zmiennej w funkcji: " << wskaznikFunkcji << " Wartosc wskaznika w funkcji: " << *wskaznikFunkcji << endl;
}

int main(){
    /*
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
    */

    // Test przekazywania zmiennych funkcji
    zmienna = 1;
    cout << "Zamienna adres: " << &zmienna << " Wartosc: " << zmienna << endl;
    wskaznik = &zmienna;
    cout << "Wskaznik zmiennej: " << wskaznik << " Wartosc wskaznika: " << *wskaznik << endl;
    system("pause");

    cout << endl << endl;
    funkcja(wskaznik);
    cout << "Wskaznik zmiennej po wyslaniu go funkcji: " << wskaznik << " Wartosc wskaznika po wyslaniu go funkcji: " << *wskaznik << endl;
    system("pause");

    zmiennaWskaznikowa = 100;
    funkcja(&zmiennaWskaznikowa);
    cout<< "zmienna wskaznikowa: " << zmiennaWskaznikowa ;


    return 0;
}
