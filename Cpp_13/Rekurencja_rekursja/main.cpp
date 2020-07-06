#include <iostream>

using namespace std;

// Rekurencja - szybko�� kosztem wykorzystanej pami�ci


/* // example 1.
int f(int n){
    if (n==0) return 3;
    else return f(n-1)+2;
}
*/

/* // Ex 2. Pot�gowanie
long potegowanie (int p, int w){
    if (w == 0) return 1;
    else return p * potegowanie(p,w-1);
}
*/


// Ex 3. Ci�g fibonacciego
long fib (int n){
    if (n == 2 || n == 1) return 1;
    else return fib(n-1) + fib(n-2);
}


int main()
{
    cout << fib(8) << endl;
    return 0;
}
