#include <iostream>

using namespace std;

/* // example 1.
int f(int n){
    if (n==0) return 3;
    else return f(n-1)+2;
}
*/

int potegowanie (int p, int w){
    if (w == 0) return 1;
    else return p * potegowanie(p,w-1);
}

int main()
{
    cout << potegowanie(2,5) << endl;
    return 0;
}
