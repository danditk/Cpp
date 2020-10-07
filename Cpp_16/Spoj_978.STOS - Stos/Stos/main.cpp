#include <iostream>
#include <windows.h>

using namespace std;

string wybor;
int dane[10];
int rozmiar=0;


//------------------------------------------------------------------------


int main()
{
    while(true){
        cin >> wybor;

        if(wybor=="+" && rozmiar<=10){
            rozmiar++;
            cin >> dane[rozmiar];
            cout << ":)" <<endl;
        }else if(wybor=="-" && rozmiar>0){
            rozmiar--;
            cout << dane[rozmiar] <<endl;
        }else{
        cout << ":(" <<endl;
        }
    };
    return 0;
}
