#include <iostream>

using namespace std;


float metr;
string metrow = "metr";

float ile_cali(float m); // wczytanie do kompilatora funkcji, ktora znajduje sie pod dunkcja main
float ile_jardow(float m); // wczytanie do kompilatora funkcji, ktora znajduje sie pod dunkcja main
void ile_mil(float m);
float ile_milki(float m);
string zmiana_nazwy(float qty, char jednostka);  // wczytanie do kompilatora funkcji, ktora znajduje sie pod dunkcja main


int main()
{
    cout << "Wprowadz dlugosc w [m]: "; cin >> metr;

    float cale = ile_cali(metr);
    float yard = ile_jardow(metr);

    string slowo_m = zmiana_nazwy(metr,'m');
    string slowo_c = zmiana_nazwy(cale,'c');
    string slowo_y = zmiana_nazwy(yard,'y');
    string slowo_e = zmiana_nazwy(ile_milki(metr),'e'); // parametrem funkcji jak sam sie przekonalem moze byc funkcja, a nie koniecznie zmienna :D!!!

    cout << endl << metr << " metr" << slowo_m << " to: " << endl;
    cout << cale << " cal" << slowo_c << endl;
    cout << yard << " jard" << slowo_y << endl;
    ile_mil(metr); cout << slowo_e << endl;

    return 0;
}


float ile_jardow(float m){

    return m * 1.0936;
    // mozna pominac wszelkie zmienne i umiescic dzialanie za funkcja return - ograniczenie ilosci kodu
}

float ile_cali(float m){

    float cal;
    cal = m * 39.37; // nalezy pamietac aby separatorem pomiecy calkowita a nie byla ".", a nie "," !

    return(cal);
}

void ile_mil(float m){

    cout << m * 0.0006213 << " mil";

}

float ile_milki(float m){

    return m * 0.0006213;
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

    else if (jednostka == 'e'){
        if (qty == 0) koncowka = "";
        else if (qty == 1) koncowka = "a";
        else if (qty > 0 && qty < 2) koncowka = "i";
        else if(qty>1 && qty<5) koncowka = "e";
        else koncowka = "";
    }

    else koncowka = "x";

    return (koncowka);
}
