#include <iostream>

using namespace std;

float liczba, najwieksza;

int main()
{
    cout << "Podaj 3 liczby, powiem, ktora jest najwieksza: " << endl;
    for(int i=0; i<3; i++){
        cin >> liczba;
        if(liczba>najwieksza)najwieksza=liczba;
    }
    cout << endl << "najwieksza liczba to: " << najwieksza;

    return 0;
}
