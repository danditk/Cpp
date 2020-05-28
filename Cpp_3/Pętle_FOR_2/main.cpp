#include <iostream>

using namespace std;

string imie;
int ile;

int main()
{

    cout << "Jak    Tobie   na      imie:"; cin >> imie;
    cout << endl << "Ile razy wypisac Twoje imie:"; cin >> ile;
    for (int i = 1; i<= ile; i++){
        cout << endl << i << ". " << imie;
    }
    return 0;
}
