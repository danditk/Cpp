#include <iostream>
#include <time.h>
#include <math.h>
#include <string>

using namespace std;


int random_range(int beg=1, int fin=10){

    int qty = fin-beg+1; // ustalanie dlugosci ciagu zakresu liczbowego

    srand(time(NULL)); // zatrzymanie odliczania sekund zegara od 1070 roku
    int rand1 = rand()%fin+1; // ustalenie przesunietego o jeden domyslnego zakresu liczb ( bo liczy od 0 )
    rand1 = rand()%qty+1; // wylosowanie liczby
    rand1 = rand()%qty+1;

    return (rand1);
}

string round(int lvl){

        lvl++;
        double x = (pow(10,lvl))-1;
        int number = random_range(1,x);

        string number_string = to_string(x);
        string number_show = to_string(number);
        if(number_string.length() > number_show.length()) number_show = "00000" + number_show;

        return number_show;
}


int main()
{
    int lvl = 1;

    string x = round(lvl);
    cout << x << "   liczba spotegowana" << endl;
    return 0;



}
