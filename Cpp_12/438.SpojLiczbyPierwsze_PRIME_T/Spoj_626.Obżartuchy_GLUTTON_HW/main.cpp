#include <iostream>

using namespace std;

int testQty, mObzatruchy, nCiastkaPudelko; // deklaracja ilosci testow, ilosci obzartuchow, ilosci ciastek w jednym pudelku
int secDay = 86400; // stala ilosc sekund w dniu
int czasObzartucha, ciastka, pudelka; // deklaracja tablic o dlugosci zaleznej od pobranych zmiennych

int main()
{
    cin >> testQty;

    for(int i=0; i<testQty; i++){ // petla powtarzajaca sie w zaleznosci od ilosci testow, jakie maja byc przeprowadzone
        cin >> mObzatruchy >> nCiastkaPudelko; // pobieranie wartosci od usera
        for(int j=0; j<mObzatruchy; j++){ // petla uwzgledniajaca wszytkich obzartuchow
            cin >> czasObzartucha; // pobranie wartosi sekundowej - czasu w ktorym obzartuch je jedno ciasteczko
            ciastka += secDay/czasObzartucha; // obliczanie ilosci ciastek jakie podczas doby zje jeden obzartuch, sumowanie kolejnych ciastek zjedzonych przez obzartucha
        }
        // obliczanie ilosci pudelek w zaleznosci od ilosci suby ciastek zjedzonych przez wszystkich obzartuchow
        (ciastka%nCiastkaPudelko==0)? (pudelka = ciastka/nCiastkaPudelko) :(pudelka = ciastka/nCiastkaPudelko + 1); //jesli okaze sie ze liczba ciasteczek nie jest rowna tyle, co zawartosc jedngo jednego pudelka trzeba dokupic jedno pudelko, najwyzej ktos doje te ciastka :D
        cout << pudelka;
        ciastka=0; pudelka=0;
    }
    return 0;
}
