#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <string>


using namespace std;

//string dane_quiz[2], pytania[5], odpowiedzi[5][4], poprawna[5];
string dane_quiz[2], pytania[5], poprawna[5];
string odpowiedzA[5], odpowiedzB[5], odpowiedzC[5], odpowiedzD[5];
string odpowiedz;
int punkty=0;

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
    int nr_pytania = 0;

    while(getline(quiz, linia)){
        switch (nr_linii){
            case 1: dane_quiz[0] = linia;                    break;
            case 2: dane_quiz[1] = linia;                    break;
            case 3: pytania[nr_pytania] = linia;             break;
            case 4: odpowiedzA[nr_pytania] = linia;          break;
            case 5: odpowiedzB[nr_pytania] = linia;          break;
            case 6: odpowiedzC[nr_pytania] = linia;          break;
            case 7: odpowiedzD[nr_pytania] = linia;          break;
            case 8: poprawna[nr_pytania] = linia;            break;
            }

        if(nr_linii==8){nr_linii=2; nr_pytania++;}
        nr_linii++;
    }

    quiz.close();

    cout << "Zagrajmy w gre..." << endl;
    Sleep(500);

    cout << dane_quiz[0] << endl;
    cout << dane_quiz[1] << endl;

    for(int i=0; i<5; i++){
        cout << endl << pytania[i] << endl;
        cout << "A. " << odpowiedzA[i] << endl;
        cout << "B. " << odpowiedzB[i] << endl;
        cout << "C. " << odpowiedzC[i] << endl;
        cout << "D. " << odpowiedzD[i] << endl;

        cout << "Twoja odpowiedz: "; cin >> odpowiedz;

        transform(odpowiedz.begin(),odpowiedz.end(),odpowiedz.begin(), ::tolower);

        if(odpowiedz==poprawna[i]){
            cout << "Dobrze, zdobywasz punkt!" << endl;
            punkty++;
        }else cout << "Z³a odpowiedz, nie zdobywasz punktu! Poprawna odpowiedz to: " << poprawna[i] << endl;
    }

    cout << endl << "Udalo Ci sie zdoobyæ: " << punkty << " PUNKTOW." << endl;

    return 0;
}
