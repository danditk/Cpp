#include <iostream>

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

float srednia_zmienne(float &a,float &b,float &c){
   return (a+b+c)/3;
}

int main()
{
    float tablica[3];

    tablica[0]=1.5;
    tablica[1]=2.3;
    tablica[2]=.75;

    float a,b,c; // test dla zmiennych zamiast tablicy

    a=1.5;
    b=2.3;
    c=.75;

    cout << "Srednia wynosi: " << srednia(tablica,3) << endl;

    cout << tablica[0]<<endl; //pokazanie ze do funkcji wysylane sa kopie srednich, a nie tylko ich referencje
    cout << tablica[1]<<endl;
    cout << tablica[2]<<endl;


    cout << "Srednia zmiennych wynosi: " << srednia_zmienne(a,b,c) << endl;

    return 0;
}
