#include <iostream>
#include <iomanip>

using namespace std;

long double fib[100000]; int n, zlota_liczba;

int main()
{
    cout << "Ile liczb Fibonnacciego chcesz wyznaczyc: ";
    cin >> n;

    fib[0]=1;
    fib[1]=1;

    cout << "0. " << fib[0];

    cout << setprecision(1000000);

    for(int i=2; i<n; i++){

        fib[i] = fib[i-1] + fib[i-2];
       // cout << endl << i+1 << ". " << fib[i];
    }

    cout << endl << n+1 << ". " << fib[n-1];

    cout << endl << "Zlota liczba: " << fib[n-1]/ fib[n-2];

    return 0;
}
