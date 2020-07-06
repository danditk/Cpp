#include <iostream>
#include <time.h>
#include <cstdlib>

clock_t start, stop; // deklaracja zmiennych typu clock_t
double czas;

using namespace std;

// Rekurencja - szybkość kosztem wykorzystanej pamięci

// example 1.
int f(int n){
    if (n==0) return 3;
    else return f(n-1)+2;
}

// Ex 2. Potęgowanie
long int pot_rek (int p, int w){
    if (w == 0) return 1;
    else return p * pot_rek(p,w-1);
}

// Ex 3. Ciąg fibonacciego
long int fib_rek (int n){
    if (n == 2 || n == 1) return 1;
    else return fib_rek(n-1) + fib_rek(n-2);
}

// Ex 4. Silnia
long int sil_rek (int n){
    if (n == 0) return 1;
    else return n * sil_rek(n-1);
}

// Ex 1. Potęgowanie - iteracyjne
long int pot_it (int p, int w){
    int x=p;
    if (w==0) return 1;
    else{
        for(int i=1; i<w; i++){
            x*=p;
        }
    }
    return x;
}

// Ex 3. Ciąg fibonacciego - iteracyjnie
long int fib_it (int n){
    int x=0, y=1, z=0;
    if(n==y||n==2*y) return 1;
    else{
        for(int i=1; i<=n; i++){
            z=x+y;
            x=y;
            y=z;
        }
    return x;
    }
}

// Ex 4. Silnia - iteracyjnie
long int sil_it (int n){
    int x=1;
    for(int i=1; i<=n; i++){
        x *= i;
    }
    return x;
}


int main()
{
    /*
    //Poręgowanie
    start=clock(); // odczyt czasu z procesora
    cout << pot_it(2,90000) << endl;
    stop=clock(); // odczyt czasu z procesora
    czas=(double)(stop-start) / CLOCKS_PER_SEC; // zutowanie roznicy w czasie na zmienna double i zmiana jej dziel¹c ja przez stala (c_p_s)
    cout<<"Czas potegowania funkcja iteracyjna: "<<czas<<endl;

    start=clock(); // odczyt czasu z procesora
    cout << pot_rek(2,90000) << endl;
    stop=clock(); // odczyt czasu z procesora
    czas=(double)(stop-start) / CLOCKS_PER_SEC; // zutowanie roznicy w czasie na zmienna double i zmiana jej dziel¹c ja przez stala (c_p_s)
    cout<<"Czas potegowania funkcja rekurencyjna: "<<czas<<endl<<endl;
    */

    /*
    //Ciąg fibonacciego
    start=clock(); // odczyt czasu z procesora
    cout << fib_it(40) << endl;
    stop=clock(); // odczyt czasu z procesora
    czas=(double)(stop-start) / CLOCKS_PER_SEC; // zutowanie roznicy w czasie na zmienna double i zmiana jej dziel¹c ja przez stala (c_p_s)
    cout<<"Czas Fibonacci funkcja iteracyjna: "<<czas<<endl;

    start=clock(); // odczyt czasu z procesora
    cout << fib_rek(40) << endl;
    stop=clock(); // odczyt czasu z procesora
    czas=(double)(stop-start) / CLOCKS_PER_SEC; // zutowanie roznicy w czasie na zmienna double i zmiana jej dziel¹c ja przez stala (c_p_s)
    cout<<"Czas Fibonacci funkcja rekurencyjna: "<<czas<<endl;

    */


    //Silnia
    start=clock(); // odczyt czasu z procesora
    cout << sil_it(900) << endl;
    stop=clock(); // odczyt czasu z procesora
    czas=(double)(stop-start) / CLOCKS_PER_SEC; // zutowanie roznicy w czasie na zmienna double i zmiana jej dziel¹c ja przez stala (c_p_s)
    cout<<"Czas silnia funkcja iteracyjna: "<<czas<<endl;

    start=clock(); // odczyt czasu z procesora
    cout << sil_rek(900) << endl;
    stop=clock(); // odczyt czasu z procesora
    czas=(double)(stop-start) / CLOCKS_PER_SEC; // zutowanie roznicy w czasie na zmienna double i zmiana jej dziel¹c ja przez stala (c_p_s)
    cout<<"Czas silnia funkcja rekurencyjna: "<<czas<<endl;



    return 0;
}
