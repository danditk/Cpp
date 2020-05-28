#include <iostream>
#include <windows.h>

using namespace std;

string imie;
int ile;

int main()
{

    cout << "Jak    Tobie   na      imie:"; cin >> imie;
    do{
        cout << endl << "Ile razy wypisac Twoje imie:"; cin >> ile;
        if(ile <0){
            cout << endl << "To musi byæ liczba dodatnia!";
            Sleep(100);
        } else if(ile == 0){
            cout << endl << "Ok, dzieki za info";
            Sleep(100);
        }
    }while (ile<0);
    for (int i = 1; i<= ile; i++){
        cout << endl << i << ". " << imie;
    }
    return 0;
}
