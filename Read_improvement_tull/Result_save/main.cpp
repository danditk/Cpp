#include <iostream>
#include <fstream>

using namespace std;


int poziom[6]={1,2,3,4,5,0};
int wynik[6]={10,7,8,5,9};

int main()
{
    fstream results;

    for(int i=0;i<5;i++){
        wynik[5]+=wynik[i];
    }

    results.open("../files/lesserr/results.txt", ios::out);

    for(int i=0; i<6; i++){
        results<<poziom[i]<<":"<<wynik[i]<<endl;
    } cout << endl;

    results.close();

    return 0;
}
