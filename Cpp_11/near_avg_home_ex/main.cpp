#include <iostream>
#include <stdlib.h>

using namespace std;

float srednia(float *tab, int ile){
    float suma=0;

    for(int i=0; i<ile; i++){
        suma+=*tab; // dodanie wartosci wszystkich el tablicy
        tab++; // inkrementecja numeru wskaznika
    }

    return suma/ile;
}


int ile=10;
float avg, low, high, near;
float liczby[10], wieksze[10], mniejsze[10];

float roznica_0, roznica;

int main()
{
    cout << "Podaj 5 liczb po spacji:" << endl;
    for(int i=0; i<ile; i++){
        cin >> liczby[i];
    }

    low = liczby[0];
    high = liczby[0];

    avg = srednia(liczby,ile);
    cout << avg << endl;

    for(int i=0; i<ile; i++){
            cout << liczby[i] << endl;
        if(liczby[i]<avg){
            mniejsze[i]=liczby[i];
            cout << "mniejsze od sredniej: " << mniejsze[i] << endl;
        }else if(liczby[i]>avg){
            wieksze[i]=liczby[i];
            cout << "wieksze od sredniej: " << wieksze[i] << endl;
        }else if (liczby[i]==avg){
            near=liczby[i];
            cout << "takie samo: " << near << endl;
        }
    }

    cout << endl << endl;
    cout << avg << endl;

    roznica_0 = avg - mniejsze[0];
    if (roznica_0 < 0) roznica_0*=-1; // abs(); - wartosc absolutna

    for(int i=1; i<ile; i++){
        roznica = avg - mniejsze[i];
        if(roznica < 0) roznica*=-1;
        if(roznica < roznica_0){
            low = mniejsze[i];
            roznica_0 = roznica;
        }

        cout << "low: " << low << endl;
    }


    roznica_0 = avg - wieksze[0];

    for(int i=1; i<ile; i++){
        roznica = avg - wieksze[i];
        if(roznica < 0) roznica*=-1;
        if(roznica < roznica_0){
            high = wieksze[i];
            roznica_0 = roznica;
        }

        cout << "high: " << high << endl;
    }



    return 0;
}
