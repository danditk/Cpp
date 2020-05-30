#include <iostream>
#include <windows.h>

using namespace std;

// Rozwoj bakterii

double bakterie_ilosc, bakrie_now = 1;
int godziny = 0;

/*
int main()
{
    cout << "Przez ile godzin rozwijamy bakretie?: "; cin >> godziny;
    cout << godziny << " : - : " << bakterie_ilosc << endl;
    bakterie_ilosc ++;
    while (godziny>=0){
        cout << godziny << " : - : " << bakterie_ilosc << endl;
        bakterie_ilosc *= 2;
        godziny--;
        Sleep(500);
    }
    return 0;
}
*/

/*
int main()
{
    cout << "Ile ma powstaæ bakterii?: "; cin >> bakterie_ilosc;
    while (bakrie_now<=bakterie_ilosc){
        cout << godziny << " : - : " << bakrie_now << endl;
        bakrie_now *= 2;
        godziny++;
        Sleep(200);
    }
    return 0;
}
*/

int main()
{
    cout << "Ile ma powstaæ bakterii?: "; cin >> bakterie_ilosc;
    do {
        cout << godziny << " : - : " << bakrie_now << endl;
        bakrie_now *= 2;
        godziny++;
        Sleep(100);
    } while (bakrie_now<=bakterie_ilosc);
    return 0;
}
