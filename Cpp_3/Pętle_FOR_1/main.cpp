#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

int i = 15;

int main()
{
    for(i; i>=0; i--){
        cout << i;
        Sleep(1000);
        system("cls");
    }
    cout << "JEBUT!" << endl;
    return 0;
}
