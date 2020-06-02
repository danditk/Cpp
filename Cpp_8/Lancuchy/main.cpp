#include <iostream>
#include <string>

using namespace std;

int main()
{
    string imie = "", ostatnia;

    while(imie != "."){

        cout << "Podaj imie:"; cin >> imie;

        int dlugosc = imie.length();
        ostatnia = imie[dlugosc-1];

        if(ostatnia == 'a')
            cout << "Jestes kobieta..." << endl << endl;
        else if(imie == ".")
            cout  << "SEE YOU SOON!" << endl << endl;
        else
            cout  << "Jestes mezczyzna." << endl << endl;
    }

    return 0;
}
