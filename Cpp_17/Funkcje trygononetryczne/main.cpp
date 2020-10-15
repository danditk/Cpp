#include <iostream>
#include <math.h>

using namespace std;

float kat;

int main()
{
    cout << "Podaj wartoœæ kata: " << endl;
    cin >> kat;

    cout << sin(kat*M_PI/180) << endl;
    cout << cos(kat*M_PI/180) << endl;
    cout << tan(kat*M_PI/180) << endl;
    cout << 1/tan(kat*M_PI/180) << endl;

    return 0;
}
