#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int liczba, guess;
int counting;
int poprawna=0;


int main()
{
    srand(time(NULL)); //start-randomizeing ( pobierz czas od 1970 do teraz )
    liczba = (rand()%100)+1;
    // ( przekazanie wartoœci do rand i wyci¹gniêcie reszty z dzielenia przez 100 [0..99 dodanie 1 -> 1>>100] )
    //chc¹c utworzyæ liczbê z sakresu 57..75 -> liczba=(rand()%25) + 51
    // pierwsza liczba jest zalezna od sekund, jest cykliczna, warto przetworzyæ funkcjê, aby zakryæ tê losowoœæ
    //liczba = (rand()%100)+1;
    cout << liczba << endl;
    cout << "Hello, wylosowalem liczbe, zgadnij jakaz to (1 - 100):";
    while(poprawna <= 1){
        cin >> guess;
        if(guess==liczba){
            poprawna=1;
        }
        /*if else(guess<liczba){
            cout << "Za mała, sprobuj ponownie.";
            poprawna = 0;
        } if else(guess>liczba){
            cout << "Za duza, sprobuj ponownie.";
            poprawna = 0;
        } else{
            cout << "error";
        }*/
        counting++;
    }

    cout << endl << "Gratulacje!!! Udalo Ci sie za: " << counting << "razem." << endl;

    return 0;
}
