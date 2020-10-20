#include <iostream>
#include <windows.h>

using namespace std;

    // Kody pierwszych 16-stu kolorów tekstu:

    // 1 czarny tekst na czarnym tle
    // 1 ciemno niebieski tekst na czarnym tle
    // 2 ciemno zielony tekst na czarnym tle
    // 3 zielono-niebieski tekst na czarnym tle
    // 4 ciemno czerwony tekst na czarnym tle
    // 5 magenta ciemna tekst na czarnym tle
    // 6 oliwkowy tekst na czarnym tle
    // 7 jasny szary tekst na czarnym tle
    // 8 szary tekst na czarnym tle
    // 9 niebieski tekst na czarnym tle
    // 10 zielony tekst na czarnym tle
    // 11 jasno niebieski tekst na czarnym tle
    // 12 czerwony tekst na czarnym tle
    // 13 magenta tekst na czarnym tle
    // 14 ¿ó³ty tekst na czarnym tle
    // 15 bia³y tekst na czarnym tle
    // 16 czarny na ciemno niebieskim tle

int main(){
    setlocale(LC_CTYPE, "Polish");

    cout<<"Kolory konsoli uzyskiwane za pomoc¹ funkcji SetConsoleTextAttribute"<<endl<<endl;

    for(int i = 0; i < 256; i++){
        SetConsoleTextAttribute( // ta funkcja ustawia kolor tekstu i t³a
                GetStdHandle(STD_OUTPUT_HANDLE), // pobieranie standardowego uchwytu wyjœcia konsoli
                 i // kod koloru (dotyczy koloru t³a jak i tekstu
                 );
        cout<<"Kolor dla wartoœci: "<<i<<endl;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    cout<<endl<<"Wciœnij enter, aby zamkn¹æ program...";
    cin.get();
}
