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
float avg, avg_abs, low, high, near;
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
    avg_abs = absolutna(avg);
    //cout << "Srednia abs: " << avg_abs << endl;

    for(int i=0; i<ile; i++){
            //cout << liczby[i] << endl;
        if(liczby[i]<avg){
            mniejsze[i]=liczby[i];
            //cout << "mniejsze od sredniej: " << mniejsze[i] << endl;
        }else if(liczby[i]>avg){
            wieksze[i]=liczby[i];
            //cout << "wieksze od sredniej: " << wieksze[i] << endl;
        }else if (liczby[i]==avg){
            near=liczby[i];
            //cout << "takie samo: " << near << endl;
        }
    }

    //cout << endl << endl;

    if(near){
        cout << "Srednia to: " << avg << endl;
        cout << "Najblizsza srednia wartosc to: " << near;
        getchar(); getchar();
        return 0;
    }


    //cout << "Srednia: " << avg << endl;

    roznica_0 = avg_abs - liczby[0];
    roznica_0 = absolutna(roznica_0);

    for(int i=0; i<ile; i++){
        roznica = avg_abs - liczby[i];
        roznica = absolutna(roznica);
        if(roznica < roznica_0){
            near = liczby[i];
            roznica_0 = roznica;
        }
    }

/*

    roznica_0 = avg_abs - mniejsze[0];
    roznica_0 = absolutna(roznica_0);

    //wyszukiwanie najblizszej sredniej liczby dolnej

    for(int i=1; i<ile; i++){
        roznica = avg_abs - mniejsze[i];
        roznica = absolutna(roznica);
        if(roznica < roznica_0){
            low = mniejsze[i];
            roznica_0 = roznica;
        }

        //cout << "low: " << low << endl;
    }


    roznica_0 = avg_abs - wieksze[0];
    roznica_0 = absolutna(roznica_0);

    //wyszukiwanie najblizszej sredniej liczby gornej

    for(int i=1; i<ile; i++){
        roznica = avg_abs - wieksze[i];
        roznica = absolutna(roznica);
        if(roznica < roznica_0){
            high = wieksze[i];
            roznica_0 = roznica;
        }

        //cout << "high: " << high << endl;
    }


    roznica_0 = high - avg_abs;
    roznica_0 = absolutna(roznica_0);

    roznica = low - avg_abs;
    roznica = absolutna(roznica);
    if(roznica<roznica_0) near = low;
    else near = high;
*/

    cout << "Srednia to: " << avg << endl;
    cout << "Liczba najblizej sredniaj to: " << near << endl;
    cout << "Liczby z gory i z dolu najblzej sredniej: " << high << " i " << low << endl;

    return 0;
}
