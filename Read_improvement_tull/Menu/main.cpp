#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

bool zalogowany = false;

char wybor;

int main()
{
    while(true){
        cout << "MAIN MENU" << endl;
        cout << "------------" << endl;
        cout << "0. GRAJ" << endl;
        cout << "1. ZACZNIJ OD WYBRANEGO POZIOMU" << endl;
        if(zalogowany==false){
            cout << "2. ZALOGUJ" << endl;
        }else if(zalogowany==true){
            cout << "2. WYLOGUJ" << endl;
        }

        if(zalogowany==true){
            cout << "3. SPRAWDZ WYNIKI" << endl;
        }
        cout << "5. WYJSCIE Z PROGRAMU" << endl;
        cout << "Wybierz opcje: "; wybor=getch();

        switch(wybor){
        case '0':{
            cout << "GRAMY SOBIE OD 0";
        }
        break;
        case '1':{
            cout << "WYBIERZ POZIOM: (CIN POBIERAMY OD USERA)" <<endl;
            cout << "GRAMY SOBIE OD POZIOMU: X" <<endl;
        }
        break;

        case '2':{
            cout << "PODAJ LOGIN: (CIN POBIERAMY OD USERA)" <<endl;
            cout << "PODAJ HASLO: (CIN POBIERAMY OD USERA)" <<endl;
            cout << "WALIDUJEMY" <<endl;
            zalogowany=!zalogowany;
            cout << "WITAJ USER: (LOGIN USERA)" <<endl;

        }
        break;
        case '3':{
            if(zalogowany!=true) return 0;
            system("CLS");
            cout << "0. MENU GLOWNE: (CIN POBIERAMY OD USERA)" <<endl;
            cout << "1. OSTATNIE WYNIKI: (CIN POBIERAMY OD USERA)" <<endl;
            cout << "2. WYNIKI WDG DATY: (CIN POBIERAMY OD USERA)" <<endl;
            cout << "3. NAJLEPSZE WYNIKI: (CIN POBIERAMY OD USERA)" <<endl;
            cout << "4. POKASZ PROGRES: (CIN POBIERAMY OD USERA)" <<endl;

        }
        break;
        case '5': exit(0);
        break;
        default: cout << "Nie ma takiej opcji ;(";
        }
        getchar();getchar();
        system("CLS");
    }

    return 0;
}
