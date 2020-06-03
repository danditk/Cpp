#include <iostream>

using namespace std;


float metr;
string metrow = "metr";

float ile_cali(float m); // wczytanie do kompilatora funkcji, ktora znajduje sie pod dunkcja main
float ile_jardow(float y); // wczytanie do kompilatora funkcji, ktora znajduje sie pod dunkcja main
string zmiana_nazwy(float qty, char jednostka);  // wczytanie do kompilatora funkcji, ktora znajduje sie pod dunkcja main


int main()
{
    cout << "Wprowadz dlugosc w [m]: "; cin >> metr;

    float cale = ile_cali(metr);
    float yard = ile_jardow(metr);
    string slowo_m = zmiana_nazwy(metr,'m');
    string slowo_c = zmiana_nazwy(cale,'c');
    string slowo_y = zmiana_nazwy(yard,'y');

    cout << endl << metr << " metr" << slowo_m << " to: " << endl;
    cout << cale << " cal" << slowo_c << endl;
    cout << yard << " jard" << slowo_y << endl;

    return 0;
}


float ile_jardow(float y){

    return y * 1.0936;
    // mozna pominac wszelkie zmienne i umiescic dzialanie za funkcja return - ograniczenie ilosci kodu
}

float ile_cali(float m){

    float cal;
    cal = m * 39.37; // nalezy pamietac aby separatorem pomiecy calkowita a nie byla ".", a nie "," !

    return(cal);
}

string zmiana_nazwy(float qty, char jednostka){

    string koncowka;

    if (jednostka == 'm'){
        if (qty == 0) koncowka = "a";
        else if (qty == 1) koncowka = "";
        else if(qty>1 && qty<5) koncowka = "y";
        else koncowka = "ow";
    }

    else if (jednostka == 'c'){
        if (qty == 0) koncowka = "i";
        else if (qty < 2) koncowka = "a";
        else if(qty>1 && qty<5) koncowka = "e";
        else koncowka = "i";
    }

    else if (jednostka == 'y'){
        if (qty == 0) koncowka = "ow";
        else if (qty == 1) koncowka = "";
        else if (qty > 1 && qty < 2) koncowka = "a";
        else if(qty>1 && qty<5) koncowka = "y";
        else koncowka = "ow";
    }

    else koncowka = "x";

    return (koncowka);
}
