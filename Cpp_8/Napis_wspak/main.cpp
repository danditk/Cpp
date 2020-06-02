#include <iostream>
#include <string>

using namespace std;

string napis;
int dl;

int main()
{
    cout << "Wprowadz napis a ujzysz go od tylu" << endl;
    cin >> napis;

    dl = napis.length();

    for(int i=dl-1; i>=0; i--){
        cout << napis[i];
    }

    return 0;
}
