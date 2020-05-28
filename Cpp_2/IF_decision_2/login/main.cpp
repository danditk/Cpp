#include <iostream>

using namespace std;

string ulog, upass;

string log = "admin";
string pass = "szarlotka";

int main()
{
    while (true){
        cout << "Wpisz login:";
        cin >> ulog;

        cout  << endl << "Wpisz haslo:";
        cin >> upass;

        if(log == ulog && pass == upass){
            cout << endl << "Wszystko Ok, zapraszamy" << endl << endl;
            return true;
        } else if(log != ulog &&  pass == upass){
            cout << endl << "Wprowadzono nieprawidlowy login" << endl << endl;
        } else if(log == ulog &&  pass != upass){
            cout << endl << "Wprowadzono nieprawidlowe haslo" << endl << endl;
        } else{
            cout << endl << "Wprowadzono nieprawidlowy login i haslo" << endl << endl;
        }
    }


    return 0;
}
