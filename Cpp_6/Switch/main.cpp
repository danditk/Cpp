#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

using namespace std;

char dzialanie=1;
float liczba1, liczba2, wynik;

int main()
{
    cout << "Wprowadz liczbe 1: "; cin >> liczba1;
    cout << "Wprowadz liczbe 2: "; cin >> liczba2;

    while(true){

        cout << endl << endl << "MENU GLOWNE";
        cout << endl << "-------------";
        cout << endl << "1. Dodawanie";
        cout << endl << "2. Odejmowanie";
        cout << endl << "3. Mnozenie";
        cout << endl << "4. Dzielenie";
        cout << endl << "0. Wyjscie";
        cout << endl << "wybierz dzialanie: ";

        dzialanie = getch();

        switch(dzialanie){

        case '0':{
            exit(0);
            break;
        }

        case '1':{
            wynik = liczba1 + liczba2;
            cout << endl << "Wynik dodawania to: " << wynik;
            break;
        }

        case '2':{
            wynik = liczba1 - liczba2;
            cout << endl << "Wynik odejmowania to: " << wynik;
            break;
        }
        case '3':{
            wynik = liczba1 * liczba2;
            cout << endl << "Iloczyn to: " << wynik;
            break;
        }
        case '4':{
            if(liczba2 == 0) cout << endl << "Holero nie dziel przez zero!";
            else{
            wynik = liczba1 / liczba2;
            cout << endl << "Iloraz to: " << wynik;
            }
            break;
        }
        default:{
            cout << "Nie ma takiej opcji w menu!" << endl;
            break;
        }
        }

        getchar(); getchar();
        system("cls");

    }

    return 0;


}
