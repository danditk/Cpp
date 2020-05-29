#include <iostream>
#include <windows.h>

using namespace std;

// Rozwoj bakterii

double bakterie_ilosc = 1;
int godziny;


int main()
{
    cout << "Przez ile godzin rozwijamy bakretie?: "; cin >> godziny;
    cout << godziny << " : - : " << bakterie_ilosc << endl;
    bakterie_ilosc = bakterie_ilosc + 1;
    while (godziny>=0){
        cout << godziny << " : - : " << bakterie_ilosc << endl;
        bakterie_ilosc *= bakterie_ilosc;
        godziny--;
        Sleep(500);
    }
    return 0;
}
