#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>

using namespace std;

int liczba, guess;
int counting=0;


int main()
{
    srand(time(NULL)); //start-randomizeing ( pobierz czas od 1970 do teraz )
    liczba = (rand()%100)+1;
    // ( przekazanie wartoœci do rand i wyci¹gniêcie reszty z dzielenia przez 100 [0..99 dodanie 1 -> 1>>100] )
    //chc¹c utworzyæ liczbê z sakresu 57..75 -> liczba=(rand()%25) + 51
    // pierwsza liczba jest zalezna od sekund, jest cykliczna, warto przetworzyæ funkcjê, aby zakryæ tê losowoœæ
    //liczba = (rand()%100)+1;
    //cout << liczba << endl;
    cout << "Hello, wylosowalem liczbe, zgadnij jakaz to (1 - 100):";

    while(guess!=liczba){
        cin >> guess;
        counting++;
        cout << "To byla Twoja " << counting << " proba.";

        if(guess<liczba){
            cout << endl << "Za mala, sprobuj ponownie: ";
        }else if(guess>liczba){
            cout << endl << "Za duza, sprobuj ponownie: ";
        }else{
            cout << endl << "Trwa weryfikacja" << endl;
            for(int i=0; i<30; i++){
                Sleep(100);
                cout << ".";
            }
            cout << endl;
        }
    }

    cout << endl << "Gratulacje!!! Udalo Ci sie za: " << counting << " razem." << endl;

    getchar(); getchar();

    return 0;
}
