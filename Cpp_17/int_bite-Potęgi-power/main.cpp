#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
long long int x;
unsigned int y=4294967295;

int main()
{
    //x=(pow(2,32)-1)/2;
    x=(pow(2,32)-1);
    //y=x+1;
    y=x; // +1 siê ju¿ nie mieœci, jest poza zakresem int
    cout << "MAX: " << y << endl;
    cout << setprecision(20);
    cout << x << endl;
    cout << sizeof(x) << endl;
    return 0;

}
