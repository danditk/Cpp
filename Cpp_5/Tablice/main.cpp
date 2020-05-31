#include <iostream>
#include <string>

using namespace std;

float oceny[5], suma=0, srednia;

int main()
{
    cout << "Aby obliczyc srednia..." << endl;
    for(int i=0; i<5; i++){
        cout << "Podaj ocene numer " << i+1 << " :";
        cin >> oceny[i];
        suma += oceny[i];
    }

    srednia = suma /5;
    cout << endl << "Srednia ocen to: " << srednia << endl;

    return 0;
}
