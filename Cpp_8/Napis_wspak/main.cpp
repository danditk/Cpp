#include <iostream>
#include <string>

using namespace std;

string napis;
int dl;

int main()
{
    cout << "Wprowadz napis a ujzysz go od tylu" << endl;
    getline(cin,napis); // - czyta cala linie niezaleznie czy znajduja sie w niej spacje na poczatku
    //cin >> napis; // - jesli na poiczatku znajduje sie spacja otrzymamy tylko pierwszy wyraz

    dl = napis.length();

    for(int i=dl-1; i>=0; i--){
        cout << napis[i];
    }

    return 0;
}
