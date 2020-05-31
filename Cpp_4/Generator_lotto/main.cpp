#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int liczba;

int main()
{

    cout << "Witaj! Za 3 sekundy nastapi zwolnienie blokady maszyny losujacej:" << endl;
    Sleep(3000);
    srand(time(NULL));
    cout << "wylosowane liczby to:" << endl << endl;

    liczba = rand()%49+1;

    for(int i=0; i<6; i++){
        cout << liczba << "\a" << "  ";
        Sleep(500);
    }
    return 0;
}
