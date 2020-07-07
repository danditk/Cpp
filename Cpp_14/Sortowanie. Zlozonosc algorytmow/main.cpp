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
            if(tab[j]<tab[j-1]){
                int bufor; bufor = tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=bufor;
            }
        }
    }
}

int main()
{
    cout << "Podaj ile liczb mamy sortowac: "; cin >> ile;

    //dynamiczna alokacja tablicy
    int *tablica;
    tablica = new int [ile];

    //unicjowanie generatora
    srand(time(NULL));


    for(int i=0; i<ile; i++){
        tablica[i] = rand()%100000+1;
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



    delete [] tablica;

    cout << endl << "Czas sortowania babelkowego: " << czas << "s" << endl;

    return 0;
}
