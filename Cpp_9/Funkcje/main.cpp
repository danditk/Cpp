#include <iostream>

using namespace std;


float metr;
string metrow = "metr";

float ile_cali(float m){

    float cal;
    cal = m * 39.37; // nalezy pamietac aby separatorem pomiecy calkowita a nie byla ".", a nie "," !

    return(cal);
}

string zmiana_nazwy(float qty, char jednostka){

    string koncowka;

    if (jednostka >= 'm'){
        if (qty <= 1) koncowka = "";
        else if(qty>1 && qty<5) koncowka = "y";
        else koncowka = "ow";
    }
    return (koncowka);
}

int main()
{
    cout << "Wprowadz dlugosc w [m]: "; cin >> metr;

    float cale = ile_cali(metr);
    string slowo = zmiana_nazwy(metr,'m');

    cout << endl << metr << " metr" << slowo << " to: ";
    cout << cale << " cala";

    return 0;
}
