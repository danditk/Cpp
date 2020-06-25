#include <iostream>

using namespace std;

float srednia(float *arg, int ile){
    float suma = 0;
    for(int i=0; i<ile; i++){
        suma+=*arg;
        arg++;
    }
    return suma/ile;
}

int main()
{

    float tab[3];

    tab[0]=1.5;
    tab[1]=2.3;
    tab[2]=0.75;

    float avg = srednia(tab,3);

    cout << "Srednia: " << avg << endl;
    return 0;
}
