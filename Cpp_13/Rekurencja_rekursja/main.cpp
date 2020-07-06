#include <iostream>

using namespace std;

// Rekurencja - szybkoœæ kosztem wykorzystanej pamiêci


/* // example 1.
int f(int n){
    if (n==0) return 3;
    else return f(n-1)+2;
}
*/

/* // Ex 2. Potêgowanie
long potegowanie (int p, int w){
    if (w == 0) return 1;
    else return p * potegowanie(p,w-1);
}
*/

/*
// Ex 3. Ci¹g fibonacciego
long fib (int n){
    if (n == 2 || n == 1) return 1;
    else return fib(n-1) + fib(n-2);
}
*/


// Ex 4. Silnia
long sil (int n){
    if (n == 0) return 1;
    else return n * sil(n-1);
}




int main()
{
    cout << sil(10) << endl;
    return 0;
}
