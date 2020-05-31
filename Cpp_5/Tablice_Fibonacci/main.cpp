#include <iostream>

using namespace std;

int fib[100000]; int n, zlota;

int main()
{
    cout << "Ile liczb Fibonnacciego chcesz wyznaczyc: ";
    cin >> n;

    fib[0]=0;
    fib[1]=1;

    cout << "0. " << fib[0];

    for(int i=2; i<n; i++){

        fib[i] = fib[i-1] + fib[i-2];
        cout << endl << i << ". " << fib[i];
    }

    cout << "Dzielenie ostatnich dwuch ostatnich liczb: " << zlota_liczba << endl;

    return 0;
}
