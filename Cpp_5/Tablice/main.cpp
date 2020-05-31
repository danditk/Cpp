#include <iostream>
#include <string>

using namespace std;

float oceny[5];
string ocenki;

int main()
{
    for(int i=0; i<5; i++){
        cout << "Podaj ocene numer " << i+1 << " :";
        cin >> oceny[i];
    }

    cout << endl;
    for(int i=0; i<5; i++){
        ocenki += to_string(oceny[i]) + ", ";
    }

    cout << ocenki;
    return 0;
}
