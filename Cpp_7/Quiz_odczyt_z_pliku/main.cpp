#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdlib.h>


using namespace std;

string dane_quiz[2], pytania[5], odpowiedzi[5][4], poprawna[5];
int punkty;

int main()
{
    fstream quiz;
    quiz.open("quiz.txt", ios::in);

    if(quiz.good()==false){
        cout << "Error. Plik nie istnieje!";
        exit(0);
    }

    string linia;
    int nr_linii = 1;
    int nr_pytanie = 0;
    int nr_poprawna = 0;

    while(getline(quiz, linia)){
        switch (nr_linii){
            case 1: dane_quiz[0] = linia; break;
            case 2: dane_quiz[1] = linia; break;
            case 3: case 9: case 15: case 21: case 27:{
                pytania[nr_pytanie] = linia;
                nr_pytanie++;
                break;
            }
            case 8: case 14: case 20: case 26: case 32:{
                poprawna[nr_poprawna] = linia;
                nr_poprawna++;
                break;
            }

        }

        nr_linii++;

        if(nr_linii==4){
            for(int i=0; i<4; i++){
                odpowiedzi[0][i] = linia;
                nr_linii++;
            }
        }
    }

    cout << "Zagrajmy w gre..." << endl;
    Sleep(500);

    cout << dane_quiz[0] << endl;
    cout << dane_quiz[1] << endl;

    for(int i=0; i<5; i++){
        cout << "Pytania: " << pytania[i] << endl;
        cout << "Odpowiedzi: " << odpowiedzi[0][i] << endl;
        cout << "Poprawna: " << poprawna[i] << endl;

    }

    return 0;
}
