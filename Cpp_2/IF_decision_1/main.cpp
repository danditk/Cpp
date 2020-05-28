#include <iostream>

using namespace std;

string PIN = "0147";

int main()
{
    for (int i= 0; i<3; i++){

        cout << "Wprowadz poprawny PIN:";
        cin >> PIN;

        if (PIN == "0147"){
            cout << "Wprowadzono poprawny numer PIN" << endl << "Mozesz wypl acic pieniadze" << endl << endl;
            return 0;

        } else {
            cout << "Sprowadzono niepoprawny pin";
            if (i <2){
                cout << ", sprobuj ponownie" << endl << endl;
            } else cout << endl << endl;
            if (i == 1) cout << "Masz ostatnia szanse" << endl;
            if (i == 2) cout << "Bardzo nam przykro, karta zostaje zablokowana" << endl;
        }
    }

    return 0;
}
