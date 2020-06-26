#include <iostream>

using namespace std;

int tests,v1,v2;

int main()
{
    cin >> tests;
    for(int i=0; i<tests; i++){
        cin >> v1 >> v2;
        cout << (2*v1*v2)/(v1+v2) << endl;
    }
    return 0;
}
