#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int ile; // alokowac pamieci na tablice
clock_t start, stop; // deklaracja zmiennych typu clock_t
double czas;

int main()
{
    cout << "Ile liczb w tablicy: ";
    cin >> ile;

    int *tablica; // nazwa wskaznika
    tablica = new int [ile]; // nowy obszar w pamieci

    //BEZ WSKAZNIKÓW

    start=clock(); // odczyt czasu z procesora
    for(int i=0; i<ile; i++){
        tablica[i]=i;
        tablica[i]+=50;
    }
    stop=clock(); // odczyt czasu z procesora
    czas=(double)(stop-start) / CLOCKS_PER_SEC; // zutowanie roznicy w czasie na zmienna double i zmiana jej dziel¹c ja przez stala (c_p_s)

    cout<<"Czas zapisu (bez wskaznika)"<<czas<<endl;

    delete [] tablica;
    // na koniec usun tablice [] o nazwie tablica, konieczne czyszczenie pamieci

    //DLA WSKAZNIKOW


    tablica = new int [ile]; // nowy obszar w pamieci
    int *wskaznik = tablica; // zrobienie do tablicy wskaznika - nazwa wskaznika

    start=clock(); // odczyt czasu z procesora
    for(int i=0; i<ile; i++){
        *wskaznik = i;
        *wskaznik+=50;
        wskaznik++;
    }
    stop=clock(); // odczyt czasu z procesora
    czas=(double)(stop-start) / CLOCKS_PER_SEC; // zutowanie roznicy w czasie na zmienna double i zmiana jej dziel¹c ja przez stala (c_p_s)

    cout<<"Czas zapisu (ze wskaznikiem)"<<czas<<endl;

    delete [] tablica;
    // na koniec usun tablice [] o nazwie tablica, konieczne czyszczenie pamieci


    return 0;
}
