#include <iostream>

using namespace std;

int main ()
{
    int stos[10];
    char znak;
    int liczba, licznik = 0;
    while (cin >> znak)
    {
        if (znak == '+')
        {
            cin >> liczba;
            if (licznik <= 9)
            {
                stos[licznik] = liczba;
                licznik++;
                cout << ":)" << endl;
            }
            else
                cout << ":(" << endl;

        }
        else if (znak == '-')
        {
            if (licznik >= 1)
            {
                licznik--;
                cout << stos[licznik] << endl;
            }
            else
                cout << ":(" << endl;
        }
    }
    return 0;
}
