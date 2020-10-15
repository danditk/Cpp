#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

string statki, brakuje;

//Koszt produkcyjny statku:
int k_metal = 20000, k_krysztal = 7000, k_dendyt = 2000;

//Tego surowca starczy na:
int s_metal,s_krysztal,s_dendyt, s_statek;

//Tego surowca brakuje na kolejny:
int b_metal,b_krysztal,b_dendyt;

//Surowce usera:
int u_metal,u_krysztal,u_dendyt;

int main()
{
    cout << "Wprowad¿ iloœæ posiadanych surowców, aby okreœliæ ile statków mo¿esz wyprodukowaæ..." << endl;
    Sleep(1000);

    cout << "Metal: "; cin >> u_metal;
    s_metal = trunc(u_metal/k_metal);
    b_metal = u_metal - (trunc(u_metal/k_metal)*k_metal);

    cout << "Krysztal: "; cin >> u_krysztal;
    s_krysztal = trunc(u_krysztal/k_krysztal);
    b_metal = u_krysztal - (trunc(u_krysztal/k_krysztal)*k_krysztal);

    cout << "Dendyt: "; cin >> u_dendyt;
    s_dendyt = trunc(u_dendyt/k_dendyt);
    b_dendyt = u_dendyt - (trunc(u_dendyt/k_dendyt)*k_dendyt);

    if(s_metal <= s_krysztal && s_metal <= s_dendyt){
        s_statek = s_metal;
    }else if(s_krysztal <= s_metal && s_krysztal <= s_dendyt){
        s_statek = s_krysztal;
    }else s_statek = s_dendyt;

    if(s_statek == 1){
        statki = " statek";
    }else if(s_statek > 1 && s_statek < 5){
        statki = " statki";
    }else{
        statki = " statków";
    }

    cout << "Mo¿esz kupiæ za to " << s_statek << statki << endl;
    cout << "Do zakupu kolejnego musisz jeszcze uzbieraæ:" << endl;
    cout << b_metal << " metalu;" << endl;
    cout << b_krysztal << " kryszta³u;" << endl;
    cout << b_dendyt << " dendytu" << endl;
    cout << "Powodzenia!" << endl;

    return 0;
}
