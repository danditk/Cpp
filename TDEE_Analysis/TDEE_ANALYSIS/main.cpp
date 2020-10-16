#include <iostream>
#include <windows.h>
#include <cmath>
#include <cstdio>

using namespace std;

// Efekt oczekiwania
void kropki(){
    for(int i=0; i<=15; i++){
        cout << ".";
        Sleep(50);
        if(i%5 == 0) system("cls");
    }
     system("cls");
}

// Wyświetlanie obliczonych danych na czystym ekranie
void wyswietl(int f_wiek, int f_BMI, int f_BMR, int f_TRF, int f_EAT, int f_NEAT, int f_TDEE){

    // Deklaracja tekstow
    string parametr[10], oBMI[10], wBMI[10];
    parametr[0]="Twoje BMI jest rowne: ";
    parametr[1]="Twoje BMR jest rowne: ";
    parametr[2]="Twoje TRF jest rowne: ";
    parametr[3]="Twoje EAT jest rowne: ";
    parametr[4]="Twoje NEAT jest rowne: ";
    parametr[5]="Twoje TDEE to: ";
    oBMI[0]="Klasyfikacja masy ciała osób dorosłych na podstawie BMI";
    oBMI[1]="Wygłodzenie	                    BMI < 16,0	    Waga ciała: niedowaga	Ryzyko chorob towarzyszacych otylosci: minimalne,
            ale zwiększony poziom wystąpienia innych problemów zdrowotnych";
    oBMI[2]="Wychudzenie	                    BMI 16,0–16,99	Waga ciała: niedowaga	Ryzyko chorob towarzyszacych otylosci: minimalne,
            ale zwiększony poziom wystąpienia innych problemów zdrowotnych";
    oBMI[3]="Niedowaga	                        BMI 17,0–18,49	Waga ciała: niedowaga	Ryzyko chorob towarzyszacych otylosci: minimalne,
            ale zwiększony poziom wystąpienia innych problemów zdrowotnych";
    oBMI[4]="Porządana masa ciała   	        BMI 18,5–24,99	Waga ciała: optimum	    Ryzyko chorob towarzyszacych otylosci: minimalne";
    oBMI[5]="Nadwaga	                        BMI 25,0–29,99	Waga ciała: niedowaga	Ryzyko chorob towarzyszacych otylosci: średnie";
    oBMI[6]="Otyłość I stopnia	                BMI 30,0–34,99	Waga ciała: otyłość	    Ryzyko chorob towarzyszacych otylosci: wysokie";
    oBMI[7]="Otyłość II stopnia (duza)	        BMI 35,0–39,99	Waga ciała: otyłość	    Ryzyko chorob towarzyszacych otylosci: bardzo wysokie";
    oBMI[8]="Otyłość II stopnia (chorobliwa)	BMI ≥ 40,0	    Waga ciała: otyłość	    Ryzyko chorob towarzyszacych otylosci: ekstremalny poziom ryzyka";
    wBMI[0]="Pożądany BMI zależy od wieku i wynosi odpowiednio:";
    wBMI[1]="Wiek: 19 – 24 lata, BMI: 19 – 24";
    wBMI[1]="Wiek: 25 – 34 lata, BMI: 20 – 25";
    wBMI[1]="Wiek: 35 – 44 lata, BMI: 21 – 26";
    wBMI[1]="Wiek: 45 – 54 lata, BMI: 22 – 27";
    wBMI[1]="Wiek: 55 – 64 lata, BMI: 23 – 28";
    wBMI[1]="Wiek: ponad 64 lata, BMI: 24 – 29";


    system("cls");

    if(wiek<19) BMI = -997;

    if(f_BMI==-997) cout << "BMI jest wskaznikiem dla osob powyzej 18 roku zycia" << endl;

    if(f_BMI>0) cout << parametr[0] << f_BMI << endl;
    if(f_BMR>0) cout << parametr[1] << f_BMR << endl;
    if(f_TRF>0) cout << parametr[2] << f_TRF << endl;
    if(f_EAT>0) cout << parametr[3] << f_EAT << endl;
    if(f_NEAT>0) cout << parametr[4] << f_NEAT << endl;
    if(f_TDEE>0) cout << parametr[5] << f_TDEE << endl;
}

// Deklaracja zmiennych
int waga, wzrost, wiek, plec, stopien_aktywnosci, wsp_BMR, TEF=6;
int BMI=0, BMR=0, TRF=0, EAT=0, NEAT=0, TDEE=0;

int main()
{
    cout << "Witaj w tym prostym programie do obliczania Twojego 0 kalorycznego" << endl;
    Sleep(000);
    system("cls");
    cout << "Wpisuj dane liczbowe, zgodnie z komunikatami, aby program sie nie wysypal ;P" << endl;
    Sleep(000);
    system("cls");
    cout << "Obliczymy najpierw Twoje BMR oraz BMI..." << endl;
    Sleep(000);
    system("cls");
    cout << "Wprowadz parametry zaokraglone do pelnych liczb dziesietnych, liczbe zatwierdz klawiszem enter" << endl;
    cout << "Waga[kg]: "; cin >> waga;
    cout << "Wzrost[cm]: "; cin >> wzrost;
    cout << "Wiek[lat]: "; cin >> wiek;
    cout << "Plec[K - wpisz 1 / M - wpisz 2]: "; cin >> plec;

    // Wspolczynnik zalezny od plci
    if(plec == 1) wsp_BMR = -161;
    else if(plec == 2) wsp_BMR = +5;
    else{
        cout << "Nieprawidlowe dane!" << endl;
        cout << "Program zostanie zatrzymany, a ty sprobuj odpalic go ponownie ;)" << endl;
        kropki();
        exit(0);
    }

    // Obliczanie BMR ze wzoru
    BMR = trunc((9.99*waga)+(6.25*wzrost)-(4.92*wiek)+wsp_BMR);

    kropki();
    wyswietl(BMI, BMR, TRF, EAT, NEAT, TDEE, wiek);

    return 0;
}
