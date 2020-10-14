#include <iostream>
#include <cmath>

using namespace std;

float liczba;

int main()
{
    cout << "Podaj liczbê: "; cin >> liczba;

    cout << "Funkcja round: " << round(liczba) << endl; // zaokr¹glanie zwyk³e
    cout << "Funkcja ceil: " << ceil(liczba) << endl; // zaokr¹glanie w góre - do sufitu CEIL
    cout << "Funkcja floor: " << floor(liczba) << endl; // zaokr¹glanie w dó³ - do pod³ogi FLOOR
    cout << "Funkcja trunc: " << trunc(liczba) << endl; // wycinanie tego, co jest po przecinku - Obci¹æ TRUNCATE

    return 0;
}
