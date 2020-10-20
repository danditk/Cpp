#include <iostream>
#include <windows.h>

using namespace std;

    // Kody pierwszych 16-stu kolor�w tekstu:

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
    // 14 ��ty tekst na czarnym tle
    // 15 bia�y tekst na czarnym tle
    // 16 czarny na ciemno niebieskim tle

int main(){
    setlocale(LC_CTYPE, "Polish");

    cout<<"Kolory konsoli uzyskiwane za pomoc� funkcji SetConsoleTextAttribute"<<endl<<endl;

    for(int i = 0; i < 256; i++){
        SetConsoleTextAttribute( // ta funkcja ustawia kolor tekstu i t�a
                GetStdHandle(STD_OUTPUT_HANDLE), // pobieranie standardowego uchwytu wyj�cia konsoli
                 i // kod koloru (dotyczy koloru t�a jak i tekstu
                 );
        cout<<"Kolor dla warto�ci: "<<i<<endl;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    cout<<endl<<"Wci�nij enter, aby zamkn�� program...";
    cin.get();
}
