#include <iostream>
#include <windows.h>
#include <cmath>
#include <cstdio>

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
// Wyświetlanie obliczonych danych na czystym ekranie
void wyswietl(int f_wiek, float f_BMI, float f_BMR, float f_TEF, float f_EAT, float f_NEAT, float f_TDEE){

    // Deklaracja tekstow
    string parametr[10], oBMI[10], wBMI[10];
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

    if(f_wiek<19) f_BMI = -997;
    if(f_BMI==-997) cout << wBMI[1] << endl;

    if(f_BMI>0) cout << parametr[0] << f_BMI << endl;
    if(f_BMR>0) cout << parametr[1] << f_BMR << endl;
    if(f_TEF>0) cout << parametr[2] << f_TEF << endl;
    if(f_EAT>0) cout << parametr[3] << f_EAT << endl;
    if(f_NEAT>0) cout << parametr[4] << f_NEAT << endl;
    if(f_TDEE>0) cout << parametr[5] << f_TDEE << endl;

    cout << endl;
}

//---------------------------------------------------------------------------------------------------------
// Deklaracja zmiennych
int waga, wzrost, wiek, wsp_BMR, NEAT=0;
float BMI=0, BMR=0, EAT=0, TEF, TEA=0.0, EPOC=0, TDEE=0;
float kcal_sila, kcal_wyt_lekka, kcal_wyt_srednia, kcal_wyt_wysoka, TEA_sila, TEA_wyt, EPOC_sila_min, EPOC_sila_max, EPOC_wyt;
int typ_osoby, minut_sily, minut_wyt_lekka, minut_wyt_srednia, minut_wyt_wysoka, punkty;
int trening_sily, trening_wyt_lekka, trening_wyt_srednia, trening_wyt_wysoka;
string plec, obliczam_sam;

//---------------------------------------------------------------------------------------------------------

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
    cout << "Plec[K / M]: "; cin >> plec;

    //.....................................................................................................
    // Wspolczynnik zalezny od plci
    if(plec == "K" || plec == "k") wsp_BMR = -161;
    else if(plec == "M" || plec == "m") wsp_BMR = +5;
    else{
        cout << "Nieprawidlowe dane!" << endl;
        cout << "Program zostanie zatrzymany, a ty sprobuj odpalic go ponownie ;)" << endl;
        kropki();
        exit(0);
    }

    //.....................................................................................................
    // Obliczanie BMR ze wzoru
    BMR = trunc((9.99*waga)+(6.25*wzrost)-(4.92*wiek)+wsp_BMR);

    kropki();
    wyswietl(wiek, BMI, BMR, TEF, EAT, NEAT, TDEE);

    cout << "Kolejny krok to ustalenie TEF, na potrzeby obliczen przyjmiemy 7%" << endl;
    TEF = 0.07;
    Sleep(000);
    cout << "Przystąpmy do obliczenia NEAT i EAT[TEA + EPOC]" << endl;
    cout << "Wybiesz jedną z opcji, zatwierdź przyciskiem Enter" << endl;
    cout << "Sądze, ze jestem..." << endl;
    cout << "1. Ektomorfikiem –  Osoba: drobna, szczupła, długie kończyny, szybki metabolizm" << endl;
    cout << "2. Mezomorfikiem –  Osoba: postawna, umięśniona, smukła, szerokie barki" << endl;
    cout << "3. Endomorfikiem –  Osoba: przysadzista, z tendencją do tycia, wolny metabolizm" << endl;
    cout << "Wpisz liczbę od 1 do 3: "; cin >> typ_osoby;

    cout << endl;
    cout << "Czy wiesz ile kalorii spalasz w trakcie treningów?" << endl;
    cout << "Odpowiedz tak[T], jeśli chcesz samodzielnie wpisać wartość spalanych kalorii" << endl;
    cout << "( jeśli używasz do tego dokładnych przyżądów pomiarowych )" << endl;
    cout << "Nie[N], jeśli chcesz, aby obliczył to program [T/N]: "; cin >> obliczam_sam;
    if(obliczam_sam == "T" || obliczam_sam == "t" || obliczam_sam == "TAK" || obliczam_sam == "tak"){
        cout << "Podczas tygodnia treningowego spalam średnio [kcal'i]..." << endl;
        cout << "Wpisz ile tygodniowo spalasz [kcal]: "; cin >> TEA;
    }

    cout << endl;
    cout << "Spędzam średnio [minut] dziennie podczas ćwiczeń siłowych..." << endl;
    cout << "Wpisz liczbę minut [0-840]: "; cin >> minut_sily;
    cout << "To stanowi [ile] treningów siłowych w tygodniu..." << endl;
    cout << "Wpisz ilość treningów siłowych: "; cin >> trening_sily;

    cout << endl;
    cout << "Spędzam średnio [minut] dziennie podczas ćwiczeń wytrzymałościowych o intensywności lekkiej..." << endl;
    cout << "Wpisz liczbę minut w 50-65% HR MAX [0-5880]: "; cin >> minut_wyt_lekka;
    cout << "Treningów o stricte takim chatakterze mam w tygodniu..." << endl;
    cout << "Wpisz ilość treningów siłowych: "; cin >> trening_wyt_lekka;

    cout << endl;
    cout << "Spędzam średnio [minut] dziennie podczas ćwiczeń wytrzymałościowych o intensywności średniej..." << endl;
    cout << "Wpisz liczbę minut w 66-80% HR MAX [0-3360]: "; cin >> minut_wyt_srednia;
    cout << "Treningów o stricte takim chatakterze mam w tygodniu..." << endl;
    cout << "Wpisz ilość treningów siłowych: "; cin >> trening_wyt_srednia;

    cout << endl;
    cout << "Spędzam średnio [minut] dziennie podczas ćwiczeń wytrzymałościowych o intensywności wysokiej..." << endl;
    cout << "Wpisz liczbę minut w 81-100% HR MAX [0-560]: "; cin >> minut_wyt_wysoka;
    cout << "Treningów o stricte takim chatakterze mam w tygodniu..." << endl;
    cout << "Wpisz ilość treningów siłowych: "; cin >> trening_wyt_wysoka;

    //.....................................................................................................
    if(minut_sily>20) punkty++;
    if(minut_wyt_lekka>120) punkty++;
    if(minut_wyt_lekka>30) punkty++;
    if(minut_wyt_lekka>3) punkty++;

    if(typ_osoby == 3){
        if(punkty < 1) NEAT = 200;
        else if(punkty >= 1) NEAT = 300;
        else NEAT = 400;
    }

    if(typ_osoby == 2){
        if(punkty < 2) NEAT = 400;
        else NEAT = 500;
    }

    if(typ_osoby == 1){
        if(punkty < 1) NEAT = 700;
        else if(punkty >= 1) NEAT = 800;
        else NEAT = 900;
    }

    kropki();
    wyswietl(wiek, BMI, BMR, TEF, EAT, NEAT, TDEE);

    //.....................................................................................................
    if(obliczam_sam == "N" || obliczam_sam == "n" || obliczam_sam == "NIE" || obliczam_sam == "nie"){

        kcal_sila = 8*minut_sily;
        TEA_sila = kcal_sila;

        kcal_wyt_lekka = 5*minut_wyt_lekka;
        kcal_wyt_srednia = 7*minut_wyt_srednia;
        kcal_wyt_wysoka = 9*minut_wyt_wysoka;
        TEA_wyt = kcal_wyt_lekka+kcal_wyt_srednia+kcal_wyt_wysoka;

        TEA = TEA_sila+TEA_wyt;
    }

    //.....................................................................................................
    EPOC_wyt = trening_wyt_lekka*5+trening_wyt_srednia*35+trening_wyt_wysoka*180;

    EPOC = EPOC_wyt;
    EAT = TEA + EPOC;
    TDEE = BMR + TEF + EAT + NEAT;

    kropki();
    wyswietl(wiek, BMI, BMR, TEF, EAT, NEAT, TDEE);

    EPOC_sila_min = TDEE*0.04;
    EPOC_sila_max = TDEE*0.07;

    EPOC =  EPOC_sila_min + EPOC_wyt;

    return 0;
}
