#include <iostream>
#include <windows.h>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

//---------------------------------------------------------------------------------------------------------
// Efekt oczekiwania
void kropki(){
    for(int i=0; i<=15; i++){
        cout << ".";
        Sleep(25);
        if(i%5 == 0) system("cls");
    }
     system("cls");
}

//---------------------------------------------------------------------------------------------------------
// Menu główne
void menuGlowne(){
    system("cls");

}

//---------------------------------------------------------------------------------------------------------
// Wyświetlanie obliczonych danych na czystym ekranie
void wyswietl(int f_etap, int f_wiek, int f_NEAT, float f_BMI, float f_BMR, float f_TEF, float f_EAT, float f_TDEE){

    // Deklaracja zmiennych
    int stanBMI;
    float BMI_min, BMI_max;
    string parametr[10], oBMI[10], wBMI[10];

    if(f_etap >0){
        parametr[0]="Twoje BMI jest rowne: ";
        parametr[1]="Twoje BMR jest rowne: ";
        parametr[2]="Twoje TEF jest rowne: ";
        parametr[3]="Twoje EAT jest rowne: ";
        parametr[4]="Twoje NEAT jest rowne: ";
        parametr[5]="Twoje TDEE to: ";

        oBMI[0]="Klasyfikacja masy ciała osób dorosłych na podstawie BMI";
        oBMI[1]="Wyglodzenie	                    BMI < 16,0	    Waga ciała: niedowaga	Ryzyko chorob towarzyszacych otylosci: minimalne, ale zwiększony poziom wystąpienia innych problemów zdrowotnych";
        oBMI[2]="Wychudzenie	                    BMI 16,0–16,99	Waga ciała: niedowaga	Ryzyko chorob towarzyszacych otylosci: minimalne, ale zwiększony poziom wystąpienia innych problemów zdrowotnych";
        oBMI[3]="Niedowaga	                        BMI 17,0–18,49	Waga ciała: niedowaga	Ryzyko chorob towarzyszacych otylosci: minimalne, ale zwiększony poziom wystąpienia innych problemów zdrowotnych";
        oBMI[4]="Porządana masa ciała   	        BMI 18,5–24,99	Waga ciała: optimum	    Ryzyko chorob towarzyszacych otylosci: minimalne";
        oBMI[5]="Nadwaga	                        BMI 25,0–29,99	Waga ciała: niedowaga	Ryzyko chorob towarzyszacych otylosci: średnie";
        oBMI[6]="Otyłość I stopnia	                BMI 30,0–34,99	Waga ciała: otyłość	    Ryzyko chorob towarzyszacych otylosci: wysokie";
        oBMI[7]="Otyłość II stopnia (duza)	        BMI 35,0–39,99	Waga ciała: otyłość	    Ryzyko chorob towarzyszacych otylosci: bardzo wysokie";
        oBMI[8]="Otyłość II stopnia (chorobliwa)	BMI ≥ 40,0	    Waga ciała: otyłość	    Ryzyko chorob towarzyszacych otylosci: ekstremalny poziom ryzyka";

        wBMI[0]="Pożądany BMI zależy od wieku i wynosi odpowiednio:";
        wBMI[1]="BMI nie zostalo obliczone, poniewaz jest wskaznikiem dla osob powyzej 18 roku zycia";
        wBMI[2]="Wiek: 19 – 24 lata, BMI: 19 – 24";
        wBMI[3]="Wiek: 25 – 34 lata, BMI: 20 – 25";
        wBMI[4]="Wiek: 35 – 44 lata, BMI: 21 – 26";
        wBMI[5]="Wiek: 45 – 54 lata, BMI: 22 – 27";
        wBMI[6]="Wiek: 55 – 64 lata, BMI: 23 – 28";
        wBMI[7]="Wiek: ponad 64 lata, BMI: 24 – 29";

        system("cls");

        if(f_wiek >= 19 && f_wiek <= 24){
            BMI_min = 19.0;
            BMI_max = 24.0;
        }else if(f_wiek >= 25 && f_wiek <= 34){
            BMI_min = 20.0;
            BMI_max = 25.0;
        }else if(f_wiek >= 35 && f_wiek <= 44){
            BMI_min = 21.0;
            BMI_max = 26.0;
        }else if(f_wiek >= 45 && f_wiek <= 54){
            BMI_min = 22.0;
            BMI_max = 27.0;
        }else if(f_wiek >= 55 && f_wiek <= 64){
            BMI_min = 23.0;
            BMI_max = 28.0;
        }else if(f_wiek > 64){
            BMI_min = 24.0;
            BMI_max = 29.0;
        }
        if(f_wiek >= 19){
            parametr[0] += to_string(f_BMI);
                 if(f_BMI < 16)                      parametr[0] += " - " + oBMI[1];
            else if(f_BMI > 16,0 && f_BMI < 16,99)   parametr[0] += " - " + oBMI[2];
            else if(f_BMI > 17,0 && f_BMI < 18,49)   parametr[0] += " - " + oBMI[3];
            else if(f_BMI > 18,5 && f_BMI < 24,99)   parametr[0] += " - " + oBMI[4];
            else if(f_BMI > 25,0 && f_BMI < 29,99)   parametr[0] += " - " + oBMI[5];
            else if(f_BMI > 30,0 && f_BMI < 34,99)   parametr[0] += " - " + oBMI[6];
            else if(f_BMI > 35,0 && f_BMI < 39,99)   parametr[0] += " - " + oBMI[7];
            else if(f_BMI >= 40,0)                   parametr[0] += " - " + oBMI[8];
        }
        else{
            parametr[0] = wBMI[1];
        }

                            cout << parametr[0] <<                                      endl;
    }


    if(f_etap>1 && f_BMR>0)         cout << parametr[1] << trunc(f_BMR)            <<   endl;
    if(f_etap>2 && f_TEF>0) cout << parametr[2] << trunc(f_TEF)             << "%" <<   endl;
    if(f_etap>3 && f_NEAT>0)cout << parametr[4] << f_NEAT                          <<   endl;
    if(f_etap>4){
        if(f_EAT>0)         cout << parametr[3] << f_EAT                           <<   endl;
        if(f_TDEE>0)        cout << parametr[5] << f_TDEE                          <<   endl;
    }

    cout << endl;
}

//---------------------------------------------------------------------------------------------------------


// Deklaracja zmiennych
int     waga, wzrost, wiek, wsp_BMR, etap=0, NEAT=0;
float   BMR=0.0, BMI=0.0, EAT=0.0, TEF, TEA=0.0, EPOC=0.0, TDEE=0.0;
float   kcal_sila, kcal_wyt_lekka, kcal_wyt_srednia, kcal_wyt_wysoka, TEA_sila, TEA_wyt, EPOC_sila_min, EPOC_sila_max, EPOC_wyt;
int     typ_osoby, minut_sily, minut_wyt_lekka, minut_wyt_srednia, minut_wyt_wysoka, punkty;
int     trening_sily, trening_wyt_lekka, trening_wyt_srednia, trening_wyt_wysoka;
string  plec, trenuje, obliczam_sam, ekran[30];



//---------------------------------------------------------------------------------------------------------

int main()
{
    cout << "Witaj w tym prostym programie do obliczania Twojego 0 kalorycznego" << endl;
    Sleep(1000);
    cout << "Wpisuj dane liczbowe, zgodnie z komunikatami, aby program sie nie wysypal ;P" << endl;
    Sleep(1000);
    cout << "Obliczymy najpierw Twoje BMR oraz BMI..." << endl;
    Sleep(1000);
    cout << "Wprowadz parametry zaokraglone do pelnych liczb dziesietnych, liczbe zatwierdz klawiszem enter" << endl;
    cout << "Waga[kg]: ";       cin >> waga;
    cout << "Wzrost[cm]: ";     cin >> wzrost;
    cout << "Wiek[lat]: ";      cin >> wiek;
    cout << "Plec[K / M]: ";    cin >> plec;
    system("cls");

    //.....................................................................................................
    // Wspolczynnik zalezny od plci
    if(plec == "K" || plec == "k")      wsp_BMR = -161;
    else if(plec == "M" || plec == "m") wsp_BMR = +5;
    else{
        cout << "Nieprawidlowe dane!" << endl;
        cout << "Program zostanie zatrzymany, a ty sprobuj odpalic go ponownie ;)" << endl;
        kropki();
        exit(0);
    }

    //.....................................................................................................
    // Obliczanie BMI ze wzoru
    BMI = waga/pow(wzrost,2);

    etap=1;
    kropki();
    wyswietl(etap, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE);

    //.....................................................................................................
    // Obliczanie BMR ze wzoru
    BMR = trunc((9.99*waga)+(6.25*wzrost)-(4.92*wiek)+wsp_BMR);

    etap=2;
    kropki();
    wyswietl(etap, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE);

    //.....................................................................................................
    // Obliczanie BMR ze wzoru


    cout << "Kolejny krok to ustalenie TEF, na potrzeby obliczen przyjmiemy 7%"                 << endl;
    TEF = 0.07;
    Sleep(3000);

    etap=3;
    kropki();
    wyswietl(etap, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE);

    cout << "Przystąpmy do obliczenia NEAT i EAT [TEA + EPOC]"                                  << endl;
    cout << "Wybiesz jedną z opcji, zatwierdź przyciskiem Enter"                                << endl;
    cout << "Sądze, ze jestem..."                                                               << endl;
    cout << "1. Ektomorfikiem –  Osoba: drobna, szczupła, długie kończyny, szybki metabolizm"   << endl;
    cout << "2. Mezomorfikiem –  Osoba: postawna, umięśniona, smukła, szerokie barki"           << endl;
    cout << "3. Endomorfikiem –  Osoba: przysadzista, z tendencją do tycia, wolny metabolizm"   << endl;
    cout << "Wpisz liczbę od 1 do 3: ";                                                     cin >> typ_osoby;

    cout << endl;
    cout << "Czy uprawiasz regularnie aktywność sportową?"                                      << endl;
    cout << "Odpowiedź [T/N]: ";                                                            cin >> obliczam_sam;
    if(trenuje == "T" || trenuje == "t" || trenuje == "TAK" || trenuje == "tak"){
        cout << endl;
        cout << "Czy wiesz ile średnio kalorii spalasz dziennie w trakcie treningów?"               << endl;
        cout << "Odpowiedz tak[T], jeśli chcesz samodzielnie wpisać wartość spalanych kalorii"      << endl;
        cout << "( jeśli używasz do tego dokładnych przyżądów pomiarowych )"                        << endl;
        cout << "Nie[N], jeśli chcesz, aby obliczył to program [T/N]: ";                        cin >> obliczam_sam;
        if(obliczam_sam == "T" || obliczam_sam == "t" || obliczam_sam == "TAK" || obliczam_sam == "tak"){
            cout << "Podczas tygodnia treningowego spalam dziennie średnio [kcal'i]..."             << endl;
            cout << "Wpisz ile średnio dziennie spalasz [kcal]: ";                              cin >> TEA;
        }

        cout << endl;
        if(TEA=0){ // Jeśli użytkownik wpisał liczbę, nie trzeba obliczać TEA -> nie zadajemy tych pytań
            cout << "Spędzam średnio [minut] dziennie podczas ćwiczeń siłowych..."                  << endl;
            cout << "Wpisz liczbę minut [0-840]: ";                                             cin >> minut_sily;
            cout << "To stanowi [ile] treningów siłowych w tygodniu..."                             << endl;
        }
        cout << "Wpisz ilość treningów siłowych: ";                                             cin >> trening_sily;

        cout << endl;
        if(TEA=0){ // Jeśli użytkownik wpisał liczbę, nie trzeba obliczać TEA -> nie zadajemy tych pytań
        cout << "Spędzam średnio [minut] dziennie podczas ćwiczeń wytrzymałościowych o intensywności lekkiej..." << endl;
        cout << "Wpisz liczbę minut w 50-65% HR MAX [0-5880]: ";                                cin >> minut_wyt_lekka;
        cout << "Treningów o stricte takim chatakterze mam w tygodniu..."                           << endl;
        }
        cout << "Wpisz ilość treningów wytrzymałościowych intensywności lekkiej: ";             cin >> trening_wyt_lekka;

        cout << endl;
        if(TEA=0){ // Jeśli użytkownik wpisał liczbę, nie trzeba obliczać TEA -> nie zadajemy tych pytań
        cout << "Spędzam średnio [minut] dziennie podczas ćwiczeń wytrzymałościowych o intensywności średniej..." << endl;
        cout << "Wpisz liczbę minut w 66-80% HR MAX [0-3360]: ";                                cin >> minut_wyt_srednia;
        cout << "Treningów o stricte takim chatakterze mam w tygodniu..."                           << endl;
        }
        cout << "Wpisz ilość treningów wytrzymałościowych intensywności średniej: ";            cin >> trening_wyt_srednia;

        cout << endl;
        if(TEA=0){ // Jeśli użytkownik wpisał liczbę, nie trzeba obliczać TEA -> nie zadajemy tych pytań
        cout << "Spędzam średnio [minut] dziennie podczas ćwiczeń wytrzymałościowych o intensywności wysokiej..." << endl;
        cout << "Wpisz liczbę minut w 81-100% HR MAX [0-560]: ";                                cin >> minut_wyt_wysoka;
        cout << "Treningów o stricte takim chatakterze mam w tygodniu..."                           << endl;
        }
        cout << "Wpisz ilość treningów  wytrzymałościowych intensywności wysokiej: ";            cin >> trening_wyt_wysoka;

        //.....................................................................................................
        if(trening_sily     >1  || minut_sily       >20)    punkty++;
        if(trening_wyt_lekka>2  || minut_wyt_lekka  >120)   punkty++;
        if(trening_wyt_lekka>1  || minut_wyt_srednia>30)    punkty++;
        if(trening_wyt_lekka>0  || minut_wyt_wysoka >3)     punkty++;
    }else TEA=0;

    if(typ_osoby == 3){
        if(punkty < 1)      NEAT = 200;
        else if(punkty >= 1)NEAT = 300;
        else                NEAT = 400;
    }

    if(typ_osoby == 2){
        if(punkty < 2)      NEAT = 400;
        else                NEAT = 500;
    }

    if(typ_osoby == 1){
        if(punkty < 1)      NEAT = 700;
        else if(punkty >= 1)NEAT = 800;
        else                NEAT = 900;
    }

    etap=4;
    kropki();
    wyswietl(etap, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE);

    //.....................................................................................................
    if(obliczam_sam == "N" || obliczam_sam == "n" || obliczam_sam == "NIE" || obliczam_sam == "nie"){

        kcal_sila   = 8*minut_sily;
        TEA_sila    = kcal_sila;

        kcal_wyt_lekka      = 5*minut_wyt_lekka;
        kcal_wyt_srednia    = 7*minut_wyt_srednia;
        kcal_wyt_wysoka     = 9*minut_wyt_wysoka;
        TEA_wyt             = kcal_wyt_lekka+kcal_wyt_srednia+kcal_wyt_wysoka;

        TEA = TEA_sila+TEA_wyt;
    }

    //.....................................................................................................
    EPOC_wyt = trening_wyt_lekka*5+trening_wyt_srednia*35+trening_wyt_wysoka*180;

    EPOC    = EPOC_wyt;
    EAT     = TEA + EPOC;
    TDEE    = BMR + TEF + EAT + NEAT;

    etap=5;
    kropki();
    wyswietl(etap, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE);

    EPOC_sila_min = TDEE*0.04;
    EPOC_sila_max = TDEE*0.07;

    EPOC =  EPOC_sila_min + EPOC_wyt;

    return 0;
}
