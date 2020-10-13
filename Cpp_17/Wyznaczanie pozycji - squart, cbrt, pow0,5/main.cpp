#include <iostream>
#include <math.h>

using namespace std;

float x_1,y_1,x_2,y_2, d;
float z_1,z_2, d3d;

int main()
{
    cout << cbrt(27) << endl;
    cout << pow(27,1.0/3.0) << endl; // aby dzia³a³o trzeba u¿yæ float'a czyli zamiast 1/3 to 1.0/3.0

    cout << "Podaj wspó³¿êdne pierwszej postaci:" << endl;
    cout << "x = "; cin >> x_1;
    cout << "y = "; cin >> y_1;

    cout << "Podaj wspó³¿êdne drugiej postaci:" << endl;
    cout << "x = "; cin >> x_2;
    cout << "y = "; cin >> y_2;

    d = sqrt(pow(x_2-x_1,2)+pow(y_2+y_1,2));

    d3d = sqrt(pow(x_2-x_1,2)+pow(y_2+y_1,2)+pow(z_2+z_1,2));

    cout << "Odleg³oœæ to: " << d << endl;

    return 0;
}
