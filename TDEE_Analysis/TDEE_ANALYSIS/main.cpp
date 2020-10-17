#include <iostream>
#include <windows.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <iomanip>

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
// Menu gˆ¢wne
void menuGlowne(){
    system("cls");

}

//---------------------------------------------------------------------------------------------------------
// Wy˜wietlanie obliczonych danych na czystym ekranie
void wyswietl(float f_etap, float f_wiek, int f_NEAT, float f_BMI, float f_BMR, float f_TEF, float f_EAT, float f_TDEE){

    // Deklaracja zmiennych
    float stanBMI;
    float BMI_min, BMI_max;
    string parametr[10], oBMI1[10], oBMI2[10], wBMI[10];

    if(f_etap >0){
        parametr[0]="Twoje BMI jest r¢wne: ";
        parametr[1]="Twoje BMR jest r¢wne: ";
        parametr[2]="Twoje TEF jest r¢wne: ";
        parametr[3]="Twoje EAT jest r¢wne: ";
        parametr[4]="Twoje NEAT jest r¢wne: ";
        parametr[5]="Twoje TDEE to: ";

        oBMI1[0]="Klasyfikacja masy ciaˆa os¢b dorosˆych na podstawie BMI";
        oBMI1[1]="Wygˆodzenie  |  BMI < 16,0  |  Waga ciaˆa: niedowaga";
        oBMI1[2]="Wychudzenie  |  BMI 16,0-16,99  |  Waga ciaˆa: niedowaga";
        oBMI1[3]="Niedowaga  |  BMI 17,0-18,49  |  Waga ciaˆa: niedowaga";
        oBMI1[4]="Porz¥dana masa ciaˆa  |  BMI 18,5-24,99  |  Waga ciaˆa: optimum";
        oBMI1[5]="Nadwaga  |  BMI 25,0-29,99  |  Waga ciaˆa: niedowaga";
        oBMI1[6]="otyˆo˜ci I stopnia  |  BMI 30,0-34,99  |  Waga ciaˆa: otyˆo˜ci";
        oBMI1[7]="otyˆo˜ci II stopnia (duza)  |  BMI 35,0-39,99  |  Waga ciaˆa: otyˆo˜ci";
        oBMI1[8]="otyˆo˜ci II stopnia (chor¢bliwa)  |  BMI ? 40,0  |  Waga ciaˆa: otyˆo˜ci";

        oBMI2[0]="Klasyfikacja masy ciaˆa os¢b dorosˆych na podstawie BMI";
        oBMI2[1]="Zwi©kszony poziom wyst¥pienia innych problem¢w zdrowotnych";
        oBMI2[2]="Zwi©kszony poziom wyst¥pienia innych problem¢w zdrowotnych";
        oBMI2[3]="Zwi©kszony poziom wyst¥pienia innych problem¢w zdrowotnych";
        oBMI2[4]="Ryzyko chor¢b towarzyszacych otyˆo˜ci: minimalne";
        oBMI2[5]="Ryzyko chor¢b towarzyszacych otyˆo˜ci: ˜rednie";
        oBMI2[6]="Ryzyko chor¢b towarzyszacych otyˆo˜ci: wysokie";
        oBMI2[7]="Ryzyko chor¢b towarzyszacych otyˆo˜ci: bardzo wysokie";
        oBMI2[8]="Ryzyko chor¢b towarzyszacych otyˆo˜ci: ekstremalny poziom ryzyka";

        wBMI[0]="Po¾¥dany BMI zale¾y od wieku i wynosi odpowiednio:";
        wBMI[1]="BMI nie zostalo obliczone, poniewa¾ jest wska«nikiem dla os¢b powy¾ej 18 roku ¾ycia";
        wBMI[2]="Wiek: 19 - 24 lata, BMI: 19 - 24";
        wBMI[3]="Wiek: 25 - 34 lata, BMI: 20 - 25";
        wBMI[4]="Wiek: 35 - 44 lata, BMI: 21 - 26";
        wBMI[5]="Wiek: 45 - 54 lata, BMI: 22 - 27";
        wBMI[6]="Wiek: 55 - 64 lata, BMI: 23 - 28";
        wBMI[7]="Wiek: ponad 64 lata, BMI: 24 - 29";

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
            cout << parametr[0] << " " << f_BMI;
                 if(f_BMI < 16){                      parametr[6] = " - " + oBMI1[1]; parametr[7] = oBMI2[1];}
            else if(f_BMI > 16.0 && f_BMI < 16.99){   parametr[6] = " - " + oBMI1[2]; parametr[7] = oBMI2[2];}
            else if(f_BMI > 17.0 && f_BMI < 18.49){   parametr[6] = " - " + oBMI1[3]; parametr[7] = oBMI2[3];}
            else if(f_BMI > 18.5 && f_BMI < 24.99){   parametr[6] = " - " + oBMI1[4]; parametr[7] = oBMI2[4];}
            else if(f_BMI > 25.0 && f_BMI < 29.99){   parametr[6] = " - " + oBMI1[5]; parametr[7] = oBMI2[5];}
            else if(f_BMI > 30.0 && f_BMI < 34.99){   parametr[6] = " - " + oBMI1[6]; parametr[7] = oBMI2[6];}
            else if(f_BMI > 35.0 && f_BMI < 39.99){   parametr[6] = " - " + oBMI1[7]; parametr[7] = oBMI2[7];}
            else if(f_BMI >= 40.0){                   parametr[6] = " - " + oBMI1[8]; parametr[7] = oBMI2[8];}

                 if((f_BMI-BMI_min)<1) parametr[8] = "Niebezpoecznie zbli¾asz si© do dolnej granicy Twojej wagi";
                 if((BMI_max-f_BMI)<1) parametr[8] = "Niebezpoecznie zbli¾asz si© do g¢rnej granicy Twojej wagi";
        }
        else{
            parametr[0] = wBMI[1];
        }

        cout << parametr[6] << endl << parametr[7]<< endl << parametr[8]           <<   endl;
    }

    cout << setprecision(5);
    if(f_etap>1 && f_BMR>0) cout << parametr[1] << trunc(f_BMR)                    <<   endl;
    if(f_etap>2 && f_TEF>0) cout << parametr[2] << trunc(f_TEF*100)         << "%" <<   endl;
    if(f_etap>3 && f_NEAT>0)cout << parametr[4] << f_NEAT                          <<   endl;
    if(f_etap>4){
        if(f_EAT>0)         cout << parametr[3] << f_EAT                           <<   endl;
        if(f_TDEE>0)        cout << parametr[5] << f_TDEE                          <<   endl;
    }

    cout << endl;
}

//---------------------------------------------------------------------------------------------------------


// Deklaracja zmiennych
float     waga, wzrost, wiek, wsp_BMR, etap=0, NEAT=0;
float     BMR=0, BMI=0, EAT=0, TEF, TEA=0, EPOC=0, TDEE=0;
float     kcal_sila, kcal_wyt_lekka, kcal_wyt_srednia, kcal_wyt_wysoka, TEA_sila, TEA_wyt, EPOC_sila_min, EPOC_sila_max, EPOC_wyt;
float     typ_osoby, minut_sily, minut_wyt_lekka, minut_wyt_srednia, minut_wyt_wysoka, punkty;
float     trening_sily, trening_wyt_lekka, trening_wyt_srednia, trening_wyt_wysoka;
string    plec, trenuje, obliczam_sam, ekran[30];



//---------------------------------------------------------------------------------------------------------

int main()
{
    cout << "Witaj programie do obliczania Twojego 0 kalorycznego" << endl;
    Sleep(1000);
    cout << "Obliczymy najpierw Twoje BMR oraz BMI..." << endl;
    Sleep(1000);
    cout << "Wprowad« parametry zaokr¥glone do peˆnych liczb dziesi©tnych, odpowied« zatwierdz klawiszem Enter" << endl;
    cout << "Waga[kg]: ";       cin >> waga;
    cout << "Wzrost[cm]: ";     cin >> wzrost;
    cout << "Wiek[lat]: ";      cin >> wiek;
    cout << "Pˆec[K/M]: ";      cin >> plec;
    system("cls");

    //.....................................................................................................
    // Wspolczynnik zalezny od plci
    if(plec == "K" || plec == "k")      wsp_BMR = -161;
    else if(plec == "M" || plec == "m") wsp_BMR = +5;
    else{
        cout << "Nieprawidlowe dane!" << endl;
        cout << "Program zostanie zatrzymany, a Ty sprobuj odpalic go ponownie ;)" << endl;
        kropki();
        exit(0);
    }

    //.....................................................................................................
    // Obliczanie BMI ze wzoru
    BMI = ceil(waga/pow(wzrost,2)*1000000)/100;

    etap=1;
    kropki();
    wyswietl(etap, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE);

    //.....................................................................................................
    // Obliczanie BMR ze wzoru
    BMR = trunc((9.99*waga)+(6.25*wzrost)-(4.92*wiek)+wsp_BMR);
    Sleep(4000);

    etap=2;
    kropki();
    wyswietl(etap, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE);
    Sleep(4000);

    //.....................................................................................................
    // Obliczanie BMR ze wzoru


    cout << "Kolejny krok to zaˆo¾enie TEF, na potrzeby naszych obliczeä przyjmiemy 7%"         << endl;
    TEF = 0.07;
    Sleep(4000);

    etap=3;
    kropki();
    wyswietl(etap, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE);

    cout << "Teraz obliczymy NEAT i EAT [TEA + EPOC]"                                           << endl;
    cout << "Wybiesz jedn¥ z opcji, zatwierd« przyciskiem Enter"                                << endl;
    cout << "S¥dze, ze jestem..."                                                               << endl;
    cout << "1. Ektomorfikiem -  Osob¥: drobna, szczupˆa, dˆugie koäczyny, szybki metabolizm"   << endl;
    cout << "2. Mezomorfikiem -  Osob¥: postawna, umi©˜niona, smukˆa, szerokie barki"           << endl;
    cout << "3. Endomorfikiem -  Osob¥: przysadzista, z tendencj¥ do tycia, wolny metabolizm"   << endl;
    cout << "Wpisz liczb© od 1 do 3: ";                                                     cin >> typ_osoby;

    cout << endl;
    cout << "Czy uprawiasz regularnie aktywno˜† fizyczn¥?"                                      << endl;
    cout << "Odpowied« [T/N]: ";                                                            cin >> obliczam_sam;
    if(trenuje == "T" || trenuje == "t" || trenuje == "TAK" || trenuje == "tak"){
        cout << endl;
        cout << "Czy wiesz ile ˜rednio kalorii spalasz dziennie w trakcie aktywno˜ci?"              << endl;
        cout << "Odpowiedz tak[T], je˜li chcesz samodzielnie wprowadzi† ˜redni¥ warto˜†"            << endl;
        cout << " spalanych kalorii ( je˜li u¾ywasz do tego dokˆadnych przy¾¥d¢w pomiarowych )"     << endl;
        cout << "Nie[N], je˜li chcesz, aby obliczyˆ to program [T/N]: ";                        cin >> obliczam_sam;
        if(obliczam_sam == "T" || obliczam_sam == "t" || obliczam_sam == "TAK" || obliczam_sam == "tak"){
            cout << "Podczas tygodnia treningowego spalam dziennie ˜rednio [kcal'i]..."             << endl;
            cout << "Wpisz ile ˜rednio dziennie spalasz [kcal]: ";                              cin >> TEA;
        }

        cout << endl;
        if(TEA=0){ // Je˜li u¾ytkownik wpisaˆ liczb©, nie trzeba oblicza† TEA -> nie zadajemy tych pytaä
            cout << "Sp©dzam ˜rednio [minut] dziennie podczas †wiczeä siˆowych..."                  << endl;
            cout << "Wpisz liczb© minut [0-840]: ";                                             cin >> minut_sily;
            cout << "To stanowi [ile] trening¢w siˆowych w tygodniu..."                             << endl;
        }
        cout << "Wpisz ilo˜† trening¢w siˆowych: ";                                             cin >> trening_sily;

        cout << endl;
        if(TEA=0){ // Je˜li u¾ytkownik wpisaˆ liczb©, nie trzeba oblicza† TEA -> nie zadajemy tych pytaä
        cout << "Sp©dzam ˜rednio [minut] dziennie podczas †wiczeä wytrzymaˆo˜ciowych o intensywno˜ci lekkiej..." << endl;
        cout << "Wpisz liczb© minut w 50-65% HR MAX [0-5880]: ";                                cin >> minut_wyt_lekka;
        cout << "Trening¢w o stricte takim chatakterze mam w tygodniu..."                           << endl;
        }
        cout << "Wpisz ilo˜† trening¢w wytrzymaˆo˜ciowych intensywno˜ci lekkiej: ";             cin >> trening_wyt_lekka;

        cout << endl;
        if(TEA=0){ // Je˜li u¾ytkownik wpisaˆ liczb©, nie trzeba oblicza† TEA -> nie zadajemy tych pytaä
        cout << "Sp©dzam ˜rednio [minut] dziennie podczas †wiczeä wytrzymaˆo˜ciowych o intensywno˜ci ˜redniej..." << endl;
        cout << "Wpisz liczb© minut w 66-80% HR MAX [0-3360]: ";                                cin >> minut_wyt_srednia;
        cout << "Trening¢w o stricte takim chatakterze mam w tygodniu..."                           << endl;
        }
        cout << "Wpisz ilo˜† trening¢w wytrzymaˆo˜ciowych intensywno˜ci ˜redniej: ";            cin >> trening_wyt_srednia;

        cout << endl;
        if(TEA=0){ // Je˜li u¾ytkownik wpisaˆ liczb©, nie trzeba oblicza† TEA -> nie zadajemy tych pytaä
        cout << "Sp©dzam ˜rednio [minut] dziennie podczas †wiczeä wytrzymaˆo˜ciowych o intensywno˜ci wysokiej..." << endl;
        cout << "Wpisz liczb© minut w 81-100% HR MAX [0-560]: ";                                cin >> minut_wyt_wysoka;
        cout << "Trening¢w o stricte takim chatakterze mam w tygodniu..."                           << endl;
        }
        cout << "Wpisz ilo˜† trening¢w  wytrzymaˆo˜ciowych intensywno˜ci wysokiej: ";            cin >> trening_wyt_wysoka;

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
    Sleep(4000);

    //.....................................................................................................
    if(obliczam_sam == "N" || obliczam_sam == "n" || obliczam_sam == "NIE" || obliczam_sam == "nie"){

        kcal_sila   = 8*minut_sily;
        TEA_sila    = trunc(kcal_sila);

        kcal_wyt_lekka      = 5*minut_wyt_lekka;
        kcal_wyt_srednia    = 7*minut_wyt_srednia;
        kcal_wyt_wysoka     = 9*minut_wyt_wysoka;
        TEA_wyt             = trunc(kcal_wyt_lekka+kcal_wyt_srednia+kcal_wyt_wysoka);

        TEA = TEA_sila+TEA_wyt;
    }

    //.....................................................................................................
    EPOC_wyt = trunc(trening_wyt_lekka*5+trening_wyt_srednia*35+trening_wyt_wysoka*180);

    EPOC    = EPOC_wyt;
    EAT     = TEA + EPOC;
    TDEE    = BMR + TEF + EAT + NEAT;

    etap=5;
    kropki();
    wyswietl(etap, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE);

    EPOC_sila_min = trunc(TDEE*0.04);
    EPOC_sila_max = trunc(TDEE*0.07);

    EPOC =  EPOC_sila_min + EPOC_wyt;

    return 0;
}































/*
        oBMI2[0]="Klasyfikacja masy ciaˆa os¢b dorosˆych na podstawie BMI";
        oBMI2[1]="Wyglodzenie  |  BMI < 16,0  |  Waga ciaˆa: niedowaga	Zwi©kszony poziom wyst¥pienia innych problem¢w zdrowotnych";
        oBMI2[2]="Wychudzenie  |  BMI 16,0-16,99  |  Waga ciaˆa: niedowaga	Zwi©kszony poziom wyst¥pienia innych problem¢w zdrowotnych";
        oBMI2[3]="Niedowaga  |  BMI 17,0-18,49  |  Waga ciaˆa: niedowaga Zwi©kszony poziom wyst¥pienia innych problem¢w zdrowotnych";
        oBMI2[4]="Porz¥dana masa ciaˆa  |  BMI 18,5-24,99  |  Waga ciaˆa: optimum Ryzyko chor¢b towarzyszacych otyˆo˜ci: minimalne";
        oBMI2[5]="Nadwaga  |  BMI 25,0-29,99  |  Waga ciaˆa: niedowaga	Ryzyko chor¢b towarzyszacych otyˆo˜ci: ˜rednie";
        oBMI2[6]="otyˆo˜ci I stopnia  |  BMI 30,0-34,99  |  Waga ciaˆa: otyˆo˜ci Ryzyko chor¢b towarzyszacych otyˆo˜ci: wysokie";
        oBMI2[7]="otyˆo˜ci II stopnia (duza)  |  BMI 35,0-39,99  |  Waga ciaˆa: otyˆo˜ci Ryzyko chor¢b towarzyszacych otyˆo˜ci: bardzo wysokie";
        oBMI2[8]="otyˆo˜ci II stopnia (chor¢bliwa)  |  BMI ? 40,0  |  Waga ciaˆa: otyˆo˜ci Ryzyko chor¢b towarzyszacych otyˆo˜†: ekstremalny poziom ryzyka";
*/
