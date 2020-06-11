#include <iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

float srednia(float *tab, int ile){
    float suma=0;

    for(int i=0; i<ile; i++){
        suma+=*tab; // dodanie wartosci wszystkich el tablicy
        tab++; // inkrementecja numeru wskaznika
    }

    return suma/ile;
}

float absolutna(float x){
    if(x < 0) x*=-1;
    return x;
}


int ile=5;
float avg, avg_abs, near;
float liczby[10];

float roznica_0, roznica;

int main()
{
    cout << "Podaj 5 liczb po spacji:" << endl;
    for(int i=0; i<ile; i++){
        cin >> liczby[i];
    }

    avg = srednia(liczby,ile);
    avg_abs = absolutna(avg);
    //cout << "Srednia abs: " << avg_abs << endl;
    //cout << endl << endl;

    for(int i=0; i<5; i++){
        if (liczby[i]==avg){
        near=liczby[i];
        cout << "Srednia to: " << avg << endl;
        cout << "Najblizsza srednia wartosc to: " << near;
        getchar(); getchar();
        return 0;
    }

    }

    roznica_0 = absolutna((avg - liczby[0]));

    for(int i=0; i<ile; i++){
        roznica = absolutna((avg - liczby[i]));
        if(roznica < roznica_0){
            near = liczby[i];
            roznica_0 = roznica;
        }
        //cout << "roznica_0  " << roznica_0 << endl;
        //cout << "roznica    " << roznica << endl;
        //cout << "avg_abs    " << avg_abs << endl;
        //cout << "liczba     " << liczby[i] << endl;
        //cout << "near       " << near << endl;
    }

    cout << "Srednia to: " << avg << endl;
    cout << "Liczba najblizej sredniaj to: " << near << endl;

    return 0;
}
