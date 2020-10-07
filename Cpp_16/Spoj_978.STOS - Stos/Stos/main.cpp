#include <iostream>

using namespace std;

string wybor;
int dane[10];
int rozmiar=0;


//------------------------------------------------------------------------


int main()
{
    while(true){
        cin >> wybor;
        if(wybor=="+" && rozmiar>-1 && rozmiar<10){
            rozmiar++;
            cin >> dane[rozmiar];
            cout << ":)" <<endl;
        }else if(wybor=="-" && rozmiar>0){
            cout << dane[rozmiar] <<endl;
            rozmiar--;
        }else{
        cout << ":(" <<endl;
        return 0;
        }
        if(rozmiar < 0) rozmiar = 0;
    };
    return 0;
}
