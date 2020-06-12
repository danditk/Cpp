#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Funkcje
int thatManyDigits(int qty);

// Zmienne
string userChoice;

int numberQty, numberShow;

int main()
{

    srand(time(NULL)); // zatrzymanie odliczania sekund zegara od 1070 roku

    while(userChoice != "end"){

        cout << "Ilo cyfrowa liczbe wylosowac? :  ";
        getline(cin, userChoice);
        numberQty = atoi(userChoice.c_str());

        numberShow = thatManyDigits(numberQty);

        cout << numberShow << endl;

    }

    return 0;
}


int thatManyDigits(int qty=1){

    // qty - okresla ilo cyfrowa liczba ma zostac wylosowana
    int x = pow(10,(qty));
    int y = pow(10,qty+1)-1;

    int maxi = (y-x)+1; // ustalanie dlugosci ciagu zakresu liczbowego
    int rands[3]; // ustalenie przesunietego o jeden domyslnego zakresu liczb
    //for(int i=0;i<10000;i++){
        rands[1] = rand(); // ustalenie przesunietego o jeden domyslnego zakresu liczb
        rands[2] = rand(); // ustalenie przesunietego o jeden domyslnego zakresu liczb
   // }

    rands[0]=(rands[1]*rands[2])%maxi+x;

    return rands[0];
}
