#include <iostream>

using namespace std;

int testQty, mObzatruchy, nCiastkaPudelko; // deklaracja ilosci testow, ilosci obzartuchow, ilosci ciastek w jednym pudelku
int secDay = 86400; // stala ilosc sekund w dniu
int czasObzartucha, ciastka; // deklaracja tablic o dlugosci zaleznej od pobranych zmiennych

int main()
{
    cin >> testQty;

    for(int i=0; i<testQty; i++){ // petla powtarzajaca sie w zaleznosci od ilosci testow, jakie maja byc przeprowadzone
        cin >> mObzatruchy >> nCiastkaPudelko; // pobieranie wartosci od usera
        for(int j=0; j<mObzatruchy; j++){ // petla uwzgledniajaca wszytkich obzartuchow
            cin >> czasObzartucha; // pobranie wartosi sekundowej - czasu w ktorym obzartuch je jedno ciasteczko
            ciastka += secDay/czasObzartucha; // obliczanie ilosci ciastek jakie podczas doby zje jeden obzartuch, sumowanie kolejnych ciastek zjedzonych przez obzartucha
        }
        cout << ciastka << endl;
        ciastka=0;
    }
    return 0;
}
