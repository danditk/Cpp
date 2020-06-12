#include <iostream>
#include <fstream>
#include <conio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

string ans;
string user = "lesserr";
string path = "../files/" + user + "/results.txt";

string datePlay;
string addPlay;
int numberPlay;

int poziom[6]={1,2,3,4,5,0};
int wynik[6]={10,7,8,7,9};

string poziomIX[6];
int wynikIX[6];


int main()
{
    fstream results;

    for(int i=0;i<5;i++){
        wynik[5]+=wynik[i];
    }

    results.open(path, ios::out | ios::app);

    results << 1 << endl;
    results << "data" << endl;
    for(int i=0; i<6; i++){
        results<<poziom[i]<<":"<<wynik[i]<<endl;
    } results << endl;

    results.close();

/*
    cout << "Czy chcesz wyswietlic resultat? (t/n): "; cin >> ans;
    if(ans!="t" || ans!="T"){
        exit(0);
    }
*/

    results.open(path, ios::in);

    if(results.good()==false){
        cout << "Plik nie istnieje!";
        exit(0);
    }

    string line;
    int lineNr=1;
    while(getline(results, line)){
        cout << "lineNr: "  << lineNr << endl;
        switch(lineNr){
            case 1: numberPlay = atoi(line.c_str()); break;
            case 2: datePlay = line; break;
            case 3: poziomIX[0] = line; break;
            case 4: poziomIX[1] = line; break;
            case 5: poziomIX[2] = line; break;
            case 6: poziomIX[3] = line; break;
            case 7: poziomIX[4] = line; break;
            case 8: poziomIX[5] = line; break;
            case 9: addPlay = line; break;
        }
        if(lineNr==10) lineNr=0;
        lineNr++;
    }

    results.close();

    cout << numberPlay << endl;
    cout << datePlay << endl;
    for(int i=0;i<6;i++) cout << poziomIX << endl;
    cout << addPlay << endl;

    return 0;
}
