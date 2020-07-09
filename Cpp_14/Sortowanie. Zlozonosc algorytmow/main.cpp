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
            if(tab[j]<tab[j-1]){ // zmiana znaku < na > powoduje sortowanie malej¹ce
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
        while (tablica[i]<v) i++;
        while (tablica[j]>v) j--;
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

int main()
{
    cout << "Podaj ile liczb mamy sortowac: "; cin >> ile;

    //dynamiczna alokacja tablicy
    int *tablica, *tablica_copy;
    tablica = new int [ile];
    tablica_copy = new int [ile];

    //unicjowanie generatora
    srand(time(NULL));


    for(int i=0; i<ile; i++){
        tablica[i] = rand()%100000+1;
    }

    for(int i=0; i<ile; i++){
        tablica_copy[i]=tablica[i];
    }

    cout << "Przed sortowaniem: ";
    for(int i=0; i<ile; i++){
        cout << tablica[i] << " ";
    } cout << endl;

    start = clock();

    cout << "Sortuje teraz babelkowo, prosze czekac..." << endl;

    sortowanie_babelkowe(tablica,ile);

    stop = clock();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;


    cout << endl << "Czas sortowania babelkowego: " << czas << "s" << endl;

    start = clock();

    cout << "Sortuje teraz algorytmem rekurencyjnym quick sort, prosze czekac (ale krocej)..." << endl;

    sortowanie_quicksort(tablica_copy,0,ile-1);

    stop = clock();
    czas = (double)(stop-start)/CLOCKS_PER_SEC;

    cout << "Po sortowaniu: ";
    for(int i=0; i<ile; i++){
        cout << tablica[i] << " ";
    } cout << endl;



    delete [] tablica;
    delete [] tablica_copy;


    return 0;
}
