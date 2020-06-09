#include <iostream>
#include <stdlib.h>

using namespace std;

float srednia(float *tab, int ile){
    float suma=0;

    for(int i=0; i<ile; i++){
        suma+=*tab; // dodanie wartosci wszystkich el tablicy
        *tab=999; // test czy funkcja moze zmienic argumenty tablicy, czy pracuje tylko na ich referencjach
        tab++; // inkrementecja numeru wskaznika
    }

    return suma/ile;
}


int ile;

int main()
{
    float avg;
    cout << "Ile liczb w tablicy: ";
    cin >> ile;

    float *tablica; // nazwa wskaznika
    tablica = new float [ile]; // nowy obszar w pamieci

    for(int i=0; i<ile; i++){
        cin >> *tablica;
        avg = srednia(tablica,i+1);
        cout << "wskaznik wartosc: " << *tablica << endl;
        cout << "srednia wartosc: " << avg << endl;
        tablica++;
    }

    delete [] tablica;
    // na koniec usun tablice [] o nazwie tablica, konieczne czyszczenie pamieci



    return 0;
}
