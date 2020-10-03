#include <iostream>
#include <cstring>

using namespace std;

char *tr(char *str)
  {
   static char buff[256];
   char cp[]="\245\206\251\210\344\242\230\276\253\244\217\250\235\343\340\227\275\215����䢘�����������";
   if(strlen(str)>=sizeof(buff)) return str;
   char *bf=buff;
   while(*str)
     {
      char *pos=strchr(cp+18,*str);
      *(bf++)=pos?*(pos-18):*str;
      ++str;
     }
   *bf=0;
   return buff;
  }

string napis;

int main()
{
    /*
    cout << "Za\253\242\210\206 g\251\230l\245 ja\276\344" << endl;
    cin >> napis;
    cout << "Wpisany ci\245g znak\242w: " << napis << endl;
    */

    /*
    Polskie znaki diakrytyczne - kodowanie ogonk�w

    \245 - �  \244 - �
    \206 - �  \217 - �
    \251 - �  \250 - �
    \210 - �   \235 - �
    \344 - �  \343 - �
    \242 - �  \340 - �
    \230 - �  \227 - �
    \253 - �  \215 - �
    \276 - �  \275 - �
    przed liczba \


    Mo�na tak�e zmieni� kodowawanie w notpadzie ++. Zmiana formatowania jest bardzo prosta ;)
            Poni�ej zmiana na kodowanie windowsowe -> �rodkowoeuropejski -> OEM 852
    */

    cout << tr("Za���� g��l� ja��") << endl;
    cin >> napis;
    cout << tr("Wpisany ci�g znak�w: ") << napis << endl;

    return 0;
}
