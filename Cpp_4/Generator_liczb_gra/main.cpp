#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int liczba;

int main()
{
    cout << "Hello, wybiesz liczb� od 1 - 100:" << endl;
    srand(time(NULL)); //start-randomizeing ( pobierz czas od 1970 do teraz )
    liczba = (rand()%100)+1; // ( przekazanie warto�ci do rand i wyci�gni�cie reszty z dzielenia przez 100 [0..99 dodanie 1 -> 1>>100] )
    //chc�c utworzy� liczb� z sakresu 57..75 -> liczba=(rand()%25) + 51
    // pierwsza liczba jest zalezna od sekund, jest cykliczna, warto przetworzy� funkcj�, aby zakry� t� losowo��
    cout << liczba <<endl;

    liczba = (rand()%100)+1;
    cout << liczba <<endl;
    liczba = (rand()%100)+1;
    cout << liczba <<endl;
    liczba = (rand()%100)+1;
    cout << liczba <<endl;
    liczba = (rand()%100)+1;
    cout << liczba <<endl;


    return 0;
}
