#include <iostream>
#include <string>

using namespace std;

float liczba, najwieksza;
int ileLiczb;

int a,b,c;

int main()
{
    cout << "Podaj ile liczb chesz sprawdziæ, podaj te liczby, powiem, ktora jest najwieksza" << endl;
    cout << "Podaj ile liczb: " << endl; cin >>ileLiczb;
    cout << "Podaj liczby: " << endl;
    for(int i=0; i<ileLiczb; i++){
        cin >> liczba;
        if(liczba>najwieksza)najwieksza=liczba;
    }
    cout << endl << "najwieksza liczba to: " << najwieksza << endl;

    /*

    cout << "Podaj 3 liczby rozdzielone spacja, powiem, ktora jest najwieksza: " << endl;
    cin >>a>>b>>c;

    if(a>=b && a>=c){
        cout << "Najwieksza liczba to: " << a;
    }else if(b>=a && b>=c){
        cout << "Najwieksza liczba to: " << b;
    }else if(c>=b && c>=a){
        cout << "Najwieksza liczba to: " << c;
    }
*/

    return 0;
}
