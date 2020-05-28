#include <iostream>

using namespace std;

int of_age = 18, president_age = 35;
string text[3] = {"Nie jestes pelnoletni i jeszcze nie mozesz zostac prezydentem",
"Jestes pelnoletni, ale jeszcze nie mozesz zostac prezydentem",
"Jestes pelnoletni i mozesz zostac prezydentem"};
int age;


int main()
{
    while(true){
        cout << endl << "Wpisz swoj wiek:" << endl;
        cin >> age;
        cout << endl;

        if ( age <= (of_age-1)) age = 0;
        else if ( age >= of_age && age < president_age) age = 1;
        else if ( age >= president_age) age = 2;
        else return false;

        switch(age){
        case 0:
            cout << text[0];
            break;
        case 1:
            cout << text[1];
            break;
        case 2:
            cout << text[2];
            break;

        default:
            cout << "defoult";
        }

    }

    return 0;
}
