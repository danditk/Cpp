#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void kropki();
void wyswietl(int, float, int, float, float, float, float, float);
// Obliczenia
float obliczBMI(float, float);
float obliczBMR(string , float , float , float);
float obliczTDEEfull(float, float);
void rozmiarOkna(int, int);


//---------------------------------------------------------------------------------------------------------


// Deklaracja zmiennych
int wybor_w_menu=-1;
string cos_z_klawiatury;
bool zlaopcja;
float     waga, wzrost, wiek, wsp_BMR, etap=0;
float     BMR=0, BMI=0, EAT=0, TEF, NEAT=0, TEA=0, EPOC=0, TDEE=0;
float     kcal_sila, kcal_wyt_lekka, kcal_wyt_srednia, kcal_wyt_wysoka, TEA_sila, TEA_wyt, EPOC_sila_min, EPOC_sila_max, EPOC_wyt;
float     typ_osoby, minut_sily, minut_wyt_lekka, minut_wyt_srednia, minut_wyt_wysoka, punkty;
float     trening_sily, trening_wyt_lekka, trening_wyt_srednia, trening_wyt_wysoka;
string    plec, trenuje, obliczam_sam, ekran[30];

//Uchwyt do zmiany czciąki w konsoli
HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);

//---------------------------------------------------------------------------------------------------------

int main()
{

    while(wybor_w_menu!=0)
    {
        rozmiarOkna(90,40);
        SetConsoleTextAttribute(uchwyt, 15);//ZMIEN KOLOR NA NR 15=WHITE
        //MAIN MENU
        system("cls");
        cout<<"==================================================================================="<<endl;
        SetConsoleTextAttribute(uchwyt, 14);//ZMIEN KOLOR NA NR 14=YELLOW
        cout<<"                Obliczanie zapotrzebowania kalorycznego "<<endl;
        SetConsoleTextAttribute(uchwyt, 15);//PRZYWROC KOLOR BIALY
        cout<<"==================================================================================="<<endl;
        SetConsoleTextAttribute(uchwyt, 12);
        cout<<"                          Wybierz jedną z opcji "<<char(2)<<endl;
        SetConsoleTextAttribute(uchwyt, 15);
        cout<<"==================================================================================="<<endl;
        cout<<"  1.  Obliczanie wska«nika masy ciaˆa ";    SetConsoleTextAttribute(uchwyt, 11);
        cout<<" [ BMI ]"<<endl;                              SetConsoleTextAttribute(uchwyt, 15);
        cout<<"  2.  Podstawowa przemiana materii       ";    SetConsoleTextAttribute(uchwyt, 11);
        cout<<"[ BMR (PPM) ]"<<endl;                        SetConsoleTextAttribute(uchwyt, 15);
        cout<<"  3.  Szczeg¢ˆowa analiza kaloryki     ";    SetConsoleTextAttribute(uchwyt, 11);
        cout<<"[ TDEE ]"<<endl;                             SetConsoleTextAttribute(uchwyt, 15);
        cout<<"  4.  Szczeg¢ˆowa analiza kaloryki     ";    SetConsoleTextAttribute(uchwyt, 11);
        cout<<"[ TDEE ]"<<endl;                             SetConsoleTextAttribute(uchwyt, 15);
        cout<<"  5.  Wy˜cwietlanie przedziaˆ¢w BMI   ";    SetConsoleTextAttribute(uchwyt, 11);
        cout<<"[ Klasyfikacja BMI og¢lna ]"<<endl;          SetConsoleTextAttribute(uchwyt, 15);
        cout<<"  6.  Wy˜cwietlanie przedziaˆ¢w BMI   ";    SetConsoleTextAttribute(uchwyt, 11);
        cout<<"[ W zale¾no˜cci od wieku ]"<<endl;            SetConsoleTextAttribute(uchwyt, 15);
        cout<<"  7.  Kasowanie pami¥ci                 ";    SetConsoleTextAttribute(uchwyt, 11);
        cout<<"[ By obliczy˜c dla innych parametr¢w ] "<<endl;SetConsoleTextAttribute(uchwyt, 15);
        cout<<"  9.  Podzi¥kowania! Objaśnienie wyników"<<endl;
        cout<<"  0.  Koniec programu "<<endl;
        cout<<"==================================================================================="<<endl;
        SetConsoleTextAttribute(uchwyt, 12);
        cout<<"      Tw¢j wyb¢r (wpisz nr wybranej opcji): ";
        SetConsoleTextAttribute(uchwyt, 15);
        cin>>cos_z_klawiatury;

        //Walidacja CZY TO LICZBA?
        zlaopcja=false;
        for(int i=0; i<cos_z_klawiatury.length(); i++)
        {
            if ((cos_z_klawiatury[i]<48)||(cos_z_klawiatury[i]>57)) zlaopcja=true;
            //SPRAWDZ KODY W TABLICY ASCII - CZY TO NA PEWNO SAME CYFRY (48-57)?
        }
        if (zlaopcja==false) wybor_w_menu=atoi(cos_z_klawiatury.c_str());

        //USTAL KTORY PLIK ZAWIERA PYTANIA I OTWORZ GO DO ODCZYTU
        switch(wybor_w_menu)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            {
                if(waga == 0 || wzrost == 0 || wiek == 0){
                    cout << "Wprowad« parametry zaokr¥glone do peˆnych liczb dziesi©tnych, odpowied« zatwierdz klawiszem Enter" << endl;
                    cout << "Waga[kg]: ";       cin >> waga;
                    cout << "Wzrost[cm]: ";     cin >> wzrost;
                    cout << "Wiek[lat]: ";      cin >> wiek;
                    cout << "Pˆec[K/M]: ";      cin >> plec;
                    kropki();
                }
            }    break;

        }
        switch(wybor_w_menu){
            case 1:
            {
                BMI = obliczBMI(waga,wzrost);
                wyswietl(1, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE);
                system("pause");
            }break;
            case 2:
            {
                BMR = obliczBMR(plec,waga,wzrost,wiek);
                wyswietl(2, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE);
                system("pause");
            }break;
            //case 3: if(BMI==0) obliczBMI(waga,wzrost); obliczTDEEsimple(); wyswietl(5, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE); break;
            case 4: {if(BMI==0) BMI = obliczBMI(waga,wzrost); TDEE = obliczTDEEfull(BMR, wiek); wyswietl(5, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE);} break;
                system("pause");
            case 5: {wyswietl(10, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE); system("pause");} break;
            case 6: {wyswietl(11, wiek, NEAT, BMI, BMR, TEF, EAT, TDEE); system("pause");} break;
            case 7:
            {
                waga=0;
                wzrost=0;
                wiek=0;
                plec="";
            }break;
            case 0: {
                    cout<<endl<<"Koniec programu! Dzieki serdeczne!"<<endl;
                    kropki();
                    exit(0);
                    }break;
            default: zlaopcja=true; break;
        }

        if(wybor_w_menu==9) //PODZIEKOWANIA
        {
            cout<<endl;
            SetConsoleTextAttribute(uchwyt, 14);
            cout<<"======================================================================================="<<endl;
            cout<<"   Dzi©kuj© serdecznie za wsparcie i cierpliwo˜rcćo˜ci wszystkim wok¢ˆ mnie <3!"<<endl;
            cout<<"   Prosz©, je˜cli to nie problem, o feedback"<<char(1)<<" Like, komenta«, subskrypcj©."<<endl;
            cout<<"   W sprawie intrpretacji wyników odsyłam Cię do wpisu z dnia: 15 Października 2020r"<<endl;
            cout<<"   Odchudzanie, diety. Jak skutecznie się odchudzać bez efektu jo-jo  na blogu:"<<endl;
            cout<<"   https://lesserr4more.wordpress.com/"<<endl;
            cout<<"   !Jeśli Twoje ciało to żywa masa mięśniowa - wskaźnik BMI nie jest dla Ciebie!"<<endl;
            cout<<"   Pozdrawiam serdecznie! - L4M"<<endl;
            cout<<"======================================================================================="<<endl<<endl;
            SetConsoleTextAttribute(uchwyt, 15);
            system("pause");
        }
        else if (zlaopcja==true) //NIEPOPRAWNA OPCJA W MENU
        {
            cout<<endl;
            SetConsoleTextAttribute(uchwyt, 12);
            cout<<"==============================================================================="<<endl;
            cout<<"                         Nie ma takiej opcji w menu!"<<endl;
            cout<<"==============================================================================="<<endl<<endl;
            SetConsoleTextAttribute(uchwyt, 15);
            system("pause");
        }
    }

    return 0;
}

//---------------------------------------------------------------------------------------------------------
// Funkcje programu
//---------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------
// Efekt oczekiwania
void kropki(){
    for(int i=0; i<=15; i++){
        cout << ".";
        Sleep(25);
        if(i%5 == 0) system("cls");
    }
}



//---------------------------------------------------------------------------------------------------------
// Wy˜wietlanie obliczonych danych na czystym ekranie
void wyswietl(int f_etap, float f_wiek, int f_NEAT, float f_BMI, float f_BMR, float f_TEF, float f_EAT, float f_TDEE){

    // Deklaracja zmiennych
    float stanBMI;
    float BMI_min, BMI_max;
    int grupa1, grupa2;
    string parametr[10], oBMI1[10], oBMI2[10], wBMI[10];
    cout << setprecision(5);

    parametr[0]="Twoje BMI jest r¢wne:  ";
    parametr[1]="Twoje BMR jest r¢wne [kcal]:  ";
    parametr[2]="Twoje TEF jest r¢wne [kcal]:  ";
    parametr[3]="Twoje EAT jest r¢wne [kcal]:  ";
    parametr[4]="Twoje NEAT jest r¢wne [kcal]: ";
    parametr[5]="Twoje TDEE to [kcal]:         ";

    oBMI1[0]="         Klasyfikacja masy ciaˆa os¢b dorosˆych na podstawie BMI            ";
    oBMI1[1]="Wygˆodzenie                        |  BMI < 16,0      |  Waga ciaˆa: niedowaga";
    oBMI1[2]="Wychudzenie                         |  BMI 16,0-16,99  |  Waga ciaˆa: niedowaga";
    oBMI1[3]="Niedowaga                           |  BMI 17,0-18,49  |  Waga ciaˆa: niedowaga";
    oBMI1[4]="Porz¥dana masa ciaˆa              |  BMI 18,5-24,99  |  Waga ciaˆa: optimum  ";
    oBMI1[5]="Nadwaga                             |  BMI 25,0-29,99  |  Waga ciaˆa: niedowaga";
    oBMI1[6]="otyˆo˜ci I stopnia                |  BMI 30,0-34,99  |  Waga ciaˆa: otyˆo˜ci  ";
    oBMI1[7]="otyˆo˜ci II stopnia (duza)        |  BMI 35,0-39,99  |  Waga ciaˆa: otyˆo˜ci  ";
    oBMI1[8]="otyˆo˜ci II stopnia (chor¢bliwa) |  BMI ? 40,0      |  Waga ciaˆa: otyˆo˜ci  ";


    oBMI2[0]="             Klasyfikacja masy ciaˆa os¢b dorosˆych na podstawie BMI    ";
    oBMI2[1]="   |  Zwi©kszony poziom wyst¥pienia innych problem¢w zdrowotnych        ";
    oBMI2[2]="   |  Zwi©kszony poziom wyst¥pienia innych problem¢w zdrowotnych        ";
    oBMI2[3]="   |  Zwi©kszony poziom wyst¥pienia innych problem¢w zdrowotnych        ";
    oBMI2[4]="   |  Ryzyko chor¢b towarzyszacych otyˆo˜ci:  | minimalne                ";
    oBMI2[5]="   |  Ryzyko chor¢b towarzyszacych otyˆo˜ci:  | ˜rednie                   ";
    oBMI2[6]="|  Ryzyko chor¢b towarzyszacych otyˆo˜ci:  | wysokie                     ";
    oBMI2[7]="|  Ryzyko chor¢b towarzyszacych otyˆo˜ci:  | bardzo wysokie              ";
    oBMI2[8]="|  Ryzyko chor¢b towarzyszacych otyˆo˜ci:  | ekstremalny poziom ryzyka   ";

    wBMI[0]="              Po¾¥dany BMI zale¾y od wieku i wynosi odpowiednio:                   ";
    wBMI[1]="BMI nie zostalo obliczone, poniewa¾ jest wska«nikiem dla os¢b powy¾ej 18 roku ¾ycia";
    wBMI[2]="                  Wiek: 19 - 24 lata     -     BMI: 19 - 24                        ";
    wBMI[3]="                  Wiek: 25 - 34 lata     -     BMI: 20 - 25                        ";
    wBMI[4]="                  Wiek: 35 - 44 lata     -     BMI: 21 - 26                        ";
    wBMI[5]="                  Wiek: 45 - 54 lata     -     BMI: 22 - 27                        ";
    wBMI[6]="                  Wiek: 55 - 64 lata     -     BMI: 23 - 28                        ";
    wBMI[7]="                  Wiek: ponad 64 lata    -     BMI: 24 - 29                        ";

    //Uchwyt do zmiany czciąki w konsoli
    HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);

    switch(f_etap){
    case 1:{
        system("cls");

        if(f_wiek >= 19 && f_wiek <= 24){
            grupa2 = 1;
            BMI_min = 19.0;
            BMI_max = 24.0;
        }else if(f_wiek >= 25 && f_wiek <= 34){
            grupa2 = 2;
            BMI_min = 20.0;
            BMI_max = 25.0;
        }else if(f_wiek >= 35 && f_wiek <= 44){
            grupa2 = 3;
            BMI_min = 21.0;
            BMI_max = 26.0;
        }else if(f_wiek >= 45 && f_wiek <= 54){
            grupa2 = 4;
            BMI_min = 22.0;
            BMI_max = 27.0;
        }else if(f_wiek >= 55 && f_wiek <= 64){
            grupa2 = 5;
            BMI_min = 23.0;
            BMI_max = 28.0;
        }else if(f_wiek > 64){
            grupa2 = 6;
            BMI_min = 24.0;
            BMI_max = 29.0;
        }
        if(f_wiek >= 19){
                 if(f_BMI < 16){                        parametr[6] = oBMI1[1]; parametr[7] = oBMI2[1]; grupa1 = 1;}
            else if(f_BMI >= 16.0 && f_BMI <= 16.99){   parametr[6] = oBMI1[2]; parametr[7] = oBMI2[2]; grupa1 = 2;}
            else if(f_BMI >= 17.0 && f_BMI <= 18.49){   parametr[6] = oBMI1[3]; parametr[7] = oBMI2[3]; grupa1 = 3;}
            else if(f_BMI >= 18.5 && f_BMI <= 24.99){   parametr[6] = oBMI1[4]; parametr[7] = oBMI2[4]; grupa1 = 4;}
            else if(f_BMI >= 25.0 && f_BMI <= 29.99){   parametr[6] = oBMI1[5]; parametr[7] = oBMI2[5]; grupa1 = 5;}
            else if(f_BMI >= 30.0 && f_BMI <= 34.99){   parametr[6] = oBMI1[6]; parametr[7] = oBMI2[6]; grupa1 = 6;}
            else if(f_BMI >= 35.0 && f_BMI <= 39.99){   parametr[6] = oBMI1[7]; parametr[7] = oBMI2[7]; grupa1 = 7;}
            else if(f_BMI >= 40.0){                     parametr[6] = oBMI1[8]; parametr[7] = oBMI2[8]; grupa1 = 9;}
 /*
                 if((BMI_min-xxxxxxxxxxxxxxxxf_BMI)<=1 && (BMI_min-f_BMI)>0.1){
                        parametr[8] = "Zbli¾asz si© do dolnej granicy odpowiedniego dla Ciebie BMI. Zachowaj ostrożność.";
                 }
                 if((BMI_maxxxxxxxxxxxxxxxxxx-f_BMI)<=1 && (BMI_max-f_BMI)<0.1){
                        parametr[8] = "Zbli¾asz si© do g¢rnej granicy odpowiedniego dla Ciebie BMI. Zachowaj ostrożność.";
                        }
*/

            cout << parametr[0] << " " << f_BMI << ", co można rozumieć jako -" << endl;
            cout << "Optymalne BMI w Twoim wieku to: " << BMI_min << " - " << BMI_max   <<   endl;
        }else{
        grupa1 = 0; grupa2 = 0;
        parametr[0] = wBMI[1];
        cout << parametr[0] << endl;
        }
        cout << parametr[6] << endl << parametr[7]<< endl << parametr[8]           <<   endl;
        }break;
    case 2:{

    cout << setprecision(5);
        if(f_BMR>0) cout << parametr[1] << trunc(f_BMR)                            <<   endl;
        else cout << "Błąd danych, spróbuj usunąć panięć i spróbuj ponownie"       <<   endl;
    }break;
    case 3:{
        if(f_BMR>0)cout << parametr[1] << trunc(f_BMR)                             <<   endl;
        if(f_TEF>0) cout << parametr[2] << trunc(f_TEF*100)                 << "%" <<   endl;
        if(f_NEAT>0) cout << parametr[4] << trunc(f_NEAT*100)                      <<   endl;
    }break;
    case 4:{
        if(f_EAT>0) cout << parametr[3] << f_EAT                                   <<   endl;
        if(f_TDEE>0) cout << parametr[5] << f_TDEE                                  <<   endl;
    }break;
    case 6:{
        for(int i=0; i>=8; i++){
        if(i==0) SetConsoleTextAttribute(uchwyt, 14);//ZMIEN KOLOR NA NR 14=YELLOW
        else if(i == grupa1) SetConsoleTextAttribute(uchwyt, 11);//ZMIEN KOLOR NA NR 14=YELLOW
        else SetConsoleTextAttribute(uchwyt, 15);//PRZYWROC KOLOR BIALY
        cout << oBMI1[i];
        cout << endl;
        }
    }break;
    case 10:{
        rozmiarOkna(160,400);
        int i=0;
        while(i<9){
            if(i==0){
                cout<<"==================================================================================="<<endl;
                SetConsoleTextAttribute(uchwyt, 14);//ZMIEN KOLOR NA NR 14=YELLOW
                cout<< oBMI1[i] <<endl;
                SetConsoleTextAttribute(uchwyt, 15);//PRZYWROC KOLOR BIALY
                cout<<"==================================================================================="<<endl;
            }
            i++;
            cout << oBMI1[i] << oBMI2[i] << endl;
        }
        rozmiarOkna(90,40);
    }break;
    case 11:{
        rozmiarOkna(160,400);
        int i=0;
        while(i<9){
            if(i==0){
                cout<<"==================================================================================="<<endl;
                SetConsoleTextAttribute(uchwyt, 14);//ZMIEN KOLOR NA NR 14=YELLOW
                cout<< wBMI[i] <<endl;
                SetConsoleTextAttribute(uchwyt, 15);//PRZYWROC KOLOR BIALY
                cout<<"==================================================================================="<<endl;
            }
            i++;
            if(i!=1) cout << wBMI[i]  << endl;
        }
        system("pause");
        rozmiarOkna(90,40);
    }break;

    }
}


//.....................................................................................................
// Obliczanie BMI ze wzoru
float obliczBMI(float f_waga, float f_wzrost){
    kropki();
    return((round(100*f_waga/pow(f_wzrost/100,2)))/100);
}


//.....................................................................................................
// Obliczanie BMR ze wzoru
float obliczBMR(string f_plec, float f_waga, float f_wzrost, float f_wiek){
// Wspolczynnik zalezny od plci
    int wsp_BMR;
    if(f_plec == "K" || f_plec == "k")      wsp_BMR = -161;
    else if(f_plec == "M" || f_plec == "m") wsp_BMR = +5;
    else{
        cout << "Nieprawidłowo wprowadzona płeć!" << endl;
        cout << "Sprobuj ponownie ;)" << endl;
        kropki();
    }

    kropki();
    return(trunc((9.99*f_waga)+(6.25*f_wzrost)-(4.92*f_wiek)+wsp_BMR));
}


//.....................................................................................................
// Obliczanie TEF, TEA, NEET ze wzoru
float obliczTDEEfull(float f_BMR, float f_wiek){

float     BMI, NEAT=0, EAT=0, TEF, TEA=0, EPOC=0, TDEE=0;
float     kcal_sila, kcal_wyt_lekka, kcal_wyt_srednia, kcal_wyt_wysoka, TEA_sila, TEA_wyt, EPOC_sila_min, EPOC_sila_max, EPOC_wyt;
float     typ_osoby, minut_sily, minut_wyt_lekka, minut_wyt_srednia, minut_wyt_wysoka, punkty;
float     trening_sily, trening_wyt_lekka, trening_wyt_srednia, trening_wyt_wysoka;
string    trenuje, obliczam_sam;

    kropki();
    TEF = 0.07;
    cout << "Pierwszy krok, poza BMR, to zaˆo¾enie TEF. Na potrzeby naszych obliczeä przyjmiemy "<< trunc(TEF*100) << "%" << endl;
    Sleep(3000);
    wyswietl(3, f_wiek, NEAT, BMI, f_BMR, TEF, EAT, TDEE);

    cout << "Teraz obliczymy NEAT i EAT [TEA + EPOC]"                                           << endl;
    cout << "Wybiesz jedn¥ z opcji, zatwierd« przyciskiem Enter"                                << endl;
    cout << "S¥dze, ze jestem..."                                                               << endl;
    cout << "1. Ektomorfikiem -  Osob¥: drobna, szczupˆa, dˆugie koäczyny, szybki metabolizm"   << endl;
    cout << "2. Mezomorfikiem -  Osob¥: postawna, umi©˜niona, smukˆa, szerokie barki"            << endl;
    cout << "3. Endomorfikiem -  Osob¥: przysadzista, z tendencj¥ do tycia, wolny metabolizm"   << endl;
    cout << "Wpisz liczb© od 1 do 3: ";                                                     cin >> typ_osoby;

    cout << endl;
    cout << "Czy uprawiasz regularnie aktywno˜† fizyczn¥?"                                      << endl;
    cout << "Odpowied« [T/N]: ";                                                            cin >> trenuje;
    transform(trenuje.begin(), trenuje.end(), trenuje.begin(),::tolower);

    if(trenuje == "t" || trenuje == "tak"){
        cout << endl;
        cout << "Czy wiesz ile ˜rednio kalorii spalasz dziennie w trakcie aktywno˜ci?"              << endl;
        cout << "Odpowiedz tak[T], je˜li chcesz samodzielnie wprowadzi† ˜redni¥ warto˜†"             << endl;
        cout << " spalanych kalorii ( je˜li u¾ywasz do tego dokˆadnych przy¾¥d¢w pomiarowych )"    << endl;
        cout << "Nie[N], je˜li chcesz, aby obliczyˆ to program [T/N]: ";                        cin >> obliczam_sam;
    }

    transform(obliczam_sam.begin(), obliczam_sam.end(), obliczam_sam.begin(),::tolower);
    if(obliczam_sam == "t" || obliczam_sam == "tak"){
            cout << "Podczas tygodnia treningowego spalam dziennie ˜rednio [kcal'i]..."             << endl;
            cout << "Wpisz ile ˜rednio dziennie spalasz [kcal]: ";                              cin >> TEA;
            cout << "Wpisz ilo˜† trening¢w siˆowych: ";                                             cin >> trening_sily;
            cout << "Wpisz ilo˜† trening¢w wytrzymaˆo˜ciowych intensywno˜ci lekkiej: ";             cin >> trening_wyt_lekka;
            cout << "Wpisz ilo˜† trening¢w wytrzymaˆo˜ciowych intensywno˜ci ˜redniej: ";            cin >> trening_wyt_srednia;
            cout << "Wpisz ilo˜† trening¢w  wytrzymaˆo˜ciowych intensywno˜ci wysokiej: ";            cin >> trening_wyt_wysoka;
    }
    if(obliczam_sam == "n" || obliczam_sam == "nie"){
        cout << endl;
        if(TEA!=0){ // Je˜li u¾ytkownik wpisaˆ liczb©, nie trzeba oblicza† TEA -> nie zadajemy tych pytaä
            cout << "Sp©dzam ˜rednio [minut] dziennie podczas †wiczeä siˆowych..."                  << endl;
            cout << "Wpisz liczb© minut [0-840]: ";                                             cin >> minut_sily;
            cout << "To stanowi [ile] trening¢w siˆowych w tygodniu..."                             << endl;
        }
        cout << "Wpisz ilo˜† trening¢w siˆowych: ";                                             cin >> trening_sily;

        cout << endl;
        if(TEA!=0){ // Je˜li u¾ytkownik wpisaˆ liczb©, nie trzeba oblicza† TEA -> nie zadajemy tych pytaä
        cout << "Sp©dzam ˜rednio [minut] dziennie podczas †wiczeä wytrzymaˆo˜ciowych o intensywno˜ci lekkiej..." << endl;
        cout << "Wpisz liczb© minut w 50-65% HR MAX [0-5880]: ";                                cin >> minut_wyt_lekka;
        cout << "Trening¢w o stricte takim chatakterze mam w tygodniu..."                           << endl;
        }
        cout << "Wpisz ilo˜† trening¢w wytrzymaˆo˜ciowych intensywno˜ci lekkiej: ";             cin >> trening_wyt_lekka;

        cout << endl;
        if(TEA!=0){ // Je˜li u¾ytkownik wpisaˆ liczb©, nie trzeba oblicza† TEA -> nie zadajemy tych pytaä
        cout << "Sp©dzam ˜rednio [minut] dziennie podczas †wiczeä wytrzymaˆo˜ciowych o intensywno˜ci ˜redniej..." << endl;
        cout << "Wpisz liczb© minut w 66-80% HR MAX [0-3360]: ";                                cin >> minut_wyt_srednia;
        cout << "Trening¢w o stricte takim chatakterze mam w tygodniu..."                           << endl;
        }
        cout << "Wpisz ilo˜† trening¢w wytrzymaˆo˜ciowych intensywno˜ci ˜redniej: ";            cin >> trening_wyt_srednia;

        cout << endl;
        if(TEA!=0){ // Je˜li u¾ytkownik wpisaˆ liczb©, nie trzeba oblicza† TEA -> nie zadajemy tych pytaä
        cout << "Sp©dzam ˜rednio [minut] dziennie podczas †wiczeä wytrzymaˆo˜ciowych o intensywno˜ci wysokiej..." << endl;
        cout << "Wpisz liczb© minut w 81-100% HR MAX [0-560]: ";                                cin >> minut_wyt_wysoka;
        cout << "Trening¢w o stricte takim chatakterze mam w tygodniu..."                           << endl;
        }
        cout << "Wpisz ilo˜† trening¢w  wytrzymaˆo˜ciowych intensywno˜ci wysokiej: ";            cin >> trening_wyt_wysoka;

    }
    //.....................................................................................................
        if(trening_sily     >1  || minut_sily       >20)    punkty++;
        if(trening_wyt_lekka>2  || minut_wyt_lekka  >120)   punkty++;
        if(trening_wyt_lekka>1  || minut_wyt_srednia>30)    punkty++;
        if(trening_wyt_lekka>0  || minut_wyt_wysoka >3)     punkty++;
    else TEA=0;

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

    kropki();
    wyswietl(4, f_wiek, NEAT, BMI, f_BMR, TEF, EAT, TDEE);

    //.....................................................................................................

    if((trenuje == "T" || trenuje == "t" || trenuje == "TAK" || trenuje == "tak")  && (obliczam_sam == "N" || obliczam_sam == "n" || obliczam_sam == "NIE" || obliczam_sam == "nie")){

        kcal_sila   = 8*minut_sily;
        TEA_sila    = trunc(kcal_sila);

        kcal_wyt_lekka      = 5*minut_wyt_lekka;
        kcal_wyt_srednia    = 7*minut_wyt_srednia;
        kcal_wyt_wysoka     = 9*minut_wyt_wysoka;
        TEA_wyt             = trunc(kcal_wyt_lekka+kcal_wyt_srednia+kcal_wyt_wysoka);

        TEA = TEA_sila+TEA_wyt;

        cout << setprecision(5);
        cout << "TEA trening siˆa:               " << trunc(TEA_sila) << endl;
        Sleep(1500);
        cout << "TEA trening wytrzymaˆo˜c:     " << trunc(TEA_wyt) << endl;
        Sleep(1500);
        cout << "W sumie TEA:                   " << trunc(TEA) << endl;
        Sleep(1500);
    }

    //.....................................................................................................

    if(trenuje == "T" || trenuje == "t" || trenuje == "TAK" || trenuje == "tak"){
        EPOC_wyt = trunc(trening_wyt_lekka*5+trening_wyt_srednia*35+trening_wyt_wysoka*180);

        EPOC    = EPOC_wyt;
        EAT     = TEA + EPOC;
        TDEE    = f_BMR + TEF + EAT + NEAT;

        EPOC_sila_min = trunc(TDEE*0.04);
        EPOC_sila_max = trunc(TDEE*0.07);

        EPOC =  EPOC_sila_min + EPOC_wyt;

        cout << "Min. EPOC trening siˆa:        " << trunc(EPOC_sila_min) << endl;
        cout << "Max. EPOC trening siˆa:        " << trunc(EPOC_sila_max) << endl;
        Sleep(1500);
        cout << "EPOC trening wytrzymaˆo˜c:     " << trunc(EPOC_wyt) << endl;
        Sleep(1500);
        cout << "W sumie EPOC:                   " << trunc(EPOC) << endl;
        Sleep(1500);
    }
    cout << "EAT  = TEA + EPOC               " << trunc(EPOC) << endl;
    Sleep(1500);
    cout << "TDEE = BMR + TEF + EAT + NEAT   " << trunc(TDEE) << endl;

    system("pause");

    return(TDEE);
}

void rozmiarOkna(int x_s, int y_s){
    //Uchwyt do zmiany czciąki w konsoli
    HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c2; // struktura potrzebna do ustawienia rozmiarów bufora pamięci
    c2.X = x_s; // szerokość na 120 szerokości znaków
    c2.Y = y_s; // wysokość na 40 wysokości znaków
    SetConsoleScreenBufferSize(uchwyt, c2); // ustawia rozmiar bufora (wyświetlanego tekstu)
    SMALL_RECT sr; // struktura wykorzystywana do ustawienia rozmiaru okna
    sr.Left = 0; // na zero
    sr.Top = 0; // na zero
    sr.Right = c2.X+1; // szerokość o 1 mniejsza od bufora
    sr.Bottom = c2.Y-1; // wysokość o 1 mniejsza od bufora
    SetConsoleWindowInfo(uchwyt,true,&sr); // ustawia rozmiar okna (jednostka to szerokość i wysokość pojedynczego znaku)
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
