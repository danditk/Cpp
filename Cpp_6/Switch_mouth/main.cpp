#include <iostream>
#include <stdlib.h>

using namespace std;

int miesiac;

int main()
{
    cout << endl << "Wybierz miesiac: ";

    if(!(cin >> miesiac)){
        cerr << "To nie jest liczba!";
        exit(0);
    }

    switch(miesiac){
    case 1:
    case 3:
    case 5:

    case 7:
    case 8:
    case 10:
    case 12:{
        cout << endl << "Wybrany miesiac ma 31 dni.";
        break;
    }
    case 4:
    case 6:
    case 9:
    case 11:{
        cout << endl << "Wybrany miesiac ma 30 dni.";
        break;
    }
    case 2:{
        int rok;
        cout << "Podaj rok: ";
        cin >> rok;

        if(((rok%4==0)&&(rok%100!=0))||(rok%400==0)){
            cout << "Ten miesiac ma 29 dni!";
        } else{
            cout << "Ten miesiac ma 28 dni!";
        }
        break;
    default: cout << "Nieprawidlowy numer miesiaca!";
    }
    }

    return 0;
}
