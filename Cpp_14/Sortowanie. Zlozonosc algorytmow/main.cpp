#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

int ile;
clock_t start, stop;
double czas;

void sortowanie_babelkowe(int *tab, int n){
    for(int i=1; i<n; i++){
        for(int j=n-1; j>=1; j--){
            if(tab[j]<tab[j-1]){ // zmiana znaku < na > powoduje sortowanie malej�ce
                int bufor; bufor = tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=bufor;
            }
        }
    }
}

void sortowanie_quicksort(int *tablica, int lewy, int prawy) {
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do{
        while (tablica[i]<v) i++; // aby zmienic ascending na descending < / >
        while (tablica[j]>v) j--; // aby zmienic ascending na descending < / >
        if (i<=j){
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++; j--;
            }
        } while (i<=j);
    if (j>lewy) sortowanie_quicksort(tablica,lewy, j);
    if (i<prawy) sortowanie_quicksort(tablica, i, prawy);
    }

void sortowanie_insertion(int *tablica, int qty){
    int i,j;
    for (i=1; i<qty; i++){
        int tymczasowa = tablica[i]; // przechowanie elementu tablicy z zmiennej pomocniczej
        for (j=i-1; j>=0; j--){
            if (tymczasowa < tablica[j]) // zamiana miejsc (ascending / descending)
            tablica[j+1] = tablica[j];
            else
            break;
        }
        tablica[j+1] = tymczasowa;
    }
}

int main()
{
    cout << "Podaj ile liczb mamy sortowac: "; cin >> ile;

    //dynamiczna alokacja tablicy
    int *tablica, *tablica_copy, *tablica_copyx;
    tablica = new int [ile];
    tablica_copy = new int [ile];
    tablica_copyx = new int [ile];

    //unicjowanie generatora
    srand(time(NULL));


    for(int i=0; i<ile; i++){
        tablica[i] = rand()%100000+1;
    }

    for(int i=0; i<ile; i++){
        tablica_copy[i]=tablica[i];
        tablica_copyx[i]=tablica[i];
    }
/*
    cout << "Przed sortowaniem: ";
    for(int i=0; i<ile; i++){
        cout << tablica[i] << " ";
    } cout << endl;
*/ //testowanie czy istnieje tablica


    start = clock();

    cout << endl << "Sortuje teraz babelkowo, prosze czekac..." << endl;

    sortowanie_babelkowe(tablica,ile);

    stop = clock();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;

    cout << endl << "Czas sortowania babelkowego: " << czas << "s" << endl << endl;


    start = clock();

    cout << endl << "Sortuje teraz algorytmem rekurencyjnym quick sort, prosze czekac (ale krocej)..." << endl;

    sortowanie_quicksort(tablica_copy,0,ile-1);

    stop = clock();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;

    cout << endl << "Czas sortowania quicksort: " << czas << "s" << endl << endl;


    start = clock();

    cout << endl << "Sortuje teraz algorytmem insertion, prosze czekac (ale krocej)..." << endl;

    sortowanie_insertion(tablica_copyx, ile);

    stop = clock();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;

    cout << endl << "Czas sortowania insertion: " << czas << "s" << endl << endl;

/*
    cout << "Po sortowaniu: ";
    for(int i=0; i<ile; i++){
        cout << tablica_copyx[i] << " ";
    } cout << endl;
    // testowanie czy sortuje
*/

    delete [] tablica;
    delete [] tablica_copy;
    delete [] tablica_copyx;


    return 0;
}
