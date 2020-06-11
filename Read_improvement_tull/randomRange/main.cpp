#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Funkcje
int random_range(int beg, int fin);// deklaracja uzycia funkcji randomowych liczb
int thatManyDigits(int qty);

// Zmienne
string userChoice;

int numberQty, numberShow;

int main()
{
    while(userChoice != "end"){

        cout << "Ilo cyfrowa liczbe wylosowac? :  " << endl;
        getline(cin, userChoice);
        numberQty = atoi(userChoice.c_str());

        numberShow = thatManyDigits(numberQty);

        cout << numberShow << endl;

    }

    return 0;
}

int random_range(int beg=1, int fin=10){

    int qty = fin-(beg+1); // ustalanie dlugosci ciagu zakresu liczbowego
    srand(time(NULL)); // zatrzymanie odliczania sekund zegara od 1070 roku
    int rands = rand()%qty+beg; // ustalenie przesunietego o jeden domyslnego zakresu liczb

    return (rands);
}


int thatManyDigits(int qty=1){
    // qty - okresla ilo cyfrowa liczba ma zostac wylosowana
    int x = pow(10,(qty-1));
    int y = pow(10,qty)-1;
    return random_range(x,y);
}
