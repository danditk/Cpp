#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int random_range(int beg, int fin);// deklaracja uzycia funkcji randomowych liczb
//int round(lvl);

int main()
{

    int numbers_l[5][100]={
    { 26, 53, 74, 79, 82, 63, 91, 73, 22, 53, 36, 29, 66, 24, 25, 31, 46, 02, 13, 85, 72, 45, 62, 67, 50, 76, 23, 06, 40, 28, 96, 88, 77, 84, 45, 15, 21, 60, 83, 49, 99, 78, 58, 87, 18, 03},
    { 277, 833, 013, 736, 226, 129, 903, 271, 736, 713, 413, 908, 862, 832, 864, 865, 837, 747, 107, 251, 982, 825, 211, 267, 837, 108, 864, 825, 953, 425, 736, 490, 363, 646, 726, 411, 361, 508, 864, 956, 525, 737, 635, 737, 107, 747, 837, 215, 847, 880, 626, 103},
    { 8638, 7875, 1178, 2277, 7426, 7655, 7777, 5433, 7657 }
    }; //deklaracja tablicy liczb dla poziomu 0 i 1 etc...


    string user_text;
    bool lvl_fin = false;
    int number_show;
    int counting=0;
    int score=0;

    cout << "Od ktorego poziomu chcesz zaczac?" << endl;
    getline(cin, user_text);
    int lvl = atoi(user_text.c_str());
    lvl-=1;
    system("cls");

    while(true){ // petla calego programu

        while(lvl_fin == false){ // petla jednego poziomu

        if(user_text != "r"){ // r jako repeat, jesli wartosc nie rowna sie repeat
            int randomowa = random_range(0,49); // wylosuj nowa liczbe z zakresu
            if (score%2 == 0) number_show = numbers_l[lvl][randomowa]; // ( parzysta lub nie, aby sie nie powtorzyla w trakcie jednej sekundy ta sama liczba)
            else number_show = numbers_l[0][randomowa+1]; // przypisz wartosc z tablicy liczb do wyswietlania
        }

        cout << number_show << endl; // wyswietl uzytkownikowi liczbe
        Sleep(100); // odczekaj
        system("cls"); // wyczysc konsole
        cout << "Wpisz wyswietlona liczbe: "; getline(cin, user_text); // odbierz od uzytkownika
        transform(user_text.begin(), user_text.end(),user_text.begin(),::tolower);// zmiana tekstu usera na male literki

        int number_user = atoi(user_text.c_str()); // zmiana tekstu na liczbe do porownania

        if(user_text == "end") return false;

        if(score == 15 || counting == 20){
            cout << "Gratulacje Twoj wynik to: " << score << "/" << counting;
            lvl_fin=true;
        }

        if(user_text != "r"){
            if(number_show == number_user){
                score++;
                cout << "Correct! Tour score: " << score << endl << endl;
            } else{
                cout << "Incorrect! Tour score: " << score << endl << endl;
            }

            Sleep(800);
            system("cls");

            counting++;
        }
        }
        lvl++;
        cout << endl << "Przeszedles poziom " << lvl << " Czy chcesz grac dalej? [t/n]"; getline(cin, user_text);
        transform(user_text.begin(), user_text.end(),user_text.begin(),::tolower);// zmiana tekstu usera na male literki
        lvl_fin = false;
        if(user_text!="t") return false;
    }

    return 0;
}


int random_range(int beg=1, int fin=10){

    int qty = fin-beg+1; // ustalanie dlugosci ciagu zakresu liczbowego

    srand(time(NULL)); // zatrzymanie odliczania sekund zegara od 1070 roku
    int rand1 = rand()%fin+1; // ustalenie przesunietego o jeden domyslnego zakresu liczb ( bo liczy od 0 )
    rand1 = rand()%qty+1; // wylosowanie liczby
    rand1 = rand()%qty+1;

    return (rand1);
}


int round(int l){

    l++;
    int x = (pow(10,l))-1;
    return random_range(1,x);
}
