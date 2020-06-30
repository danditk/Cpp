#include <iostream>

using namespace std;

int q, x;
string text;

bool czyPierwsza(int s){

    if (s==1) return false;
    for (int i=2; i<(s/2)+1; i++){
        if(s%i==0) return false;
    }
    return true;
}

int main()
{
    cin >> q;
    for(int i=0; i<q; i++){
        cin >> x;
        text = czyPierwsza(x) == true ? "TAK" : "NIE";
        cout << text << endl;
    }

    return 0;
}
