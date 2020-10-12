#include <iostream>
#include <math.h>
using namespace std;

int guy1, guy2, corect = 2025, sub1, sub2;

int main()
{
    cout << "Na jaki rok zaplanowano powstanie witryny Dariusza Tkaczuk?" << endl;
    cout << "Zawodnik pierwszy odpowiada: "; cin >> guy1;
    cout << "Zawodnik drugi odpowiada: "; cin >> guy2;
    if(abs(corect-guy1)< abs(corect-guy2)){
        cout << "Wygrywa zawodnik 1" << endl;
    }else if(abs(corect-guy2)< abs(corect-guy1)){
        cout << "Wygrywa zawodnik 2" << endl;
    }else{
        cout << "Remis" << endl;
    }
    return 0;
}
