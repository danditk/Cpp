#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string jeden = "Ala ma ";
    string dwa = "kota";
    string trzy = jeden + dwa; // konkatenacja
    string piec = trzy;

    transform(trzy.begin(), trzy.end(),trzy.begin(),::toupper); // zamiana na duze litery
    string cztery = trzy;
    transform(cztery.begin(), cztery.end(),cztery.begin(),::tolower); // zamiana na male litery

    //cout << trzy << endl;
    //cout << cztery << endl;

    string szukaj = "kot";

    size_t pozycja = piec.find(szukaj);

    if (pozycja!=string::npos)/* Sprawdzenie czy znaleziono wyszukanie */{
        cout << "Znalezono na pozycji: " << pozycja << endl << endl;
    } else cout << "Nie znaleziono" << endl << endl;

    string temp = piec.erase(0,7); // usuwanie z ciagu
    piec = trzy; // przywracanie poprzedniej nazwy ciagu
    string szesc = piec.erase(3,8) + " " + temp.erase(3,1); // konkatenacja
    cout << szesc << endl << endl;

    szesc.insert(3, " zgubila"); // dokladanie do ciagu
    szesc.insert(15, "a"); // dokladanie do ciagu
    cout << szesc << endl << endl;

    szesc.replace(4,12, "to " + szukaj); // zastêpowanie w ciagu
    cout << szesc << endl << endl;

    string siedem = szesc.substr(4,6); // zapisywanie czesci ciagu w nowej zmiennej
    transform(siedem.begin(),siedem.end(), siedem.begin(), ::toupper);
    siedem += "!";
    cout << siedem << endl;

    return 0;
}
