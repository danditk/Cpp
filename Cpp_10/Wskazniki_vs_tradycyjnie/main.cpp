#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int ile; // alokowac pamieci na tablice
clock_t start, stop;
double czas;

int main()
{
    cout << "Ile liczb w tablicy: ";
    cin >> ile;

    int *tablica; // nazwa wskaznika
    tablica = new int [ile]; // nowy obszar w pamieci

    start = clock();
    for(int i=0; i<ile; i++){
        tablica[i]=i;
        tablica[i]+=50;
    }

    stop = clock();
    czas = (double)(stop - start)/CLOCKS_PER_SEC;
    cout << "Czas zapisu (bez wskazniaka): " << czas << endl;

    delete [] tablica; // na koniec usun tablice [] o nazwie tablica, konieczne czyszczenie pamieci

    int *wskaznik = tablica;
    tablica = new int [ile];

    start = clock();

    for(int i=0; i<ile; i++){
        *wskaznik = i;
        *wskaznik+=50;
        wskaznik++;
    }

    stop = clock();
    czas = (double)(stop - start)/CLOCKS_PER_SEC;
    cout << "Czas zapisu (ze wskaznikiem): " << czas << endl;

    delete [] tablica; // na koniec usun tablice [] o nazwie tablica, konieczne czyszczenie pamieci

    return 0;
}
