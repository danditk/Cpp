#include <iostream>
#include <cmath>

using namespace std;

float liczba;

int main()
{
    cout << "Podaj liczb�: "; cin >> liczba;

    cout << "Funkcja round: " << round(liczba) << endl; // zaokr�glanie zwyk�e
    cout << "Funkcja ceil: " << ceil(liczba) << endl; // zaokr�glanie w g�re - do sufitu CEIL
    cout << "Funkcja floor: " << floor(liczba) << endl; // zaokr�glanie w d� - do pod�ogi FLOOR
    cout << "Funkcja trunc: " << trunc(liczba) << endl; // wycinanie tego, co jest po przecinku - Obci�� TRUNCATE

    return 0;
}
