#include <iostream>

using namespace std;

int x=0,qty, l;
string text;

int main()
{
    cin >> qty;
    long tab[qty];
    for(int i=0; i<qty; i++) cin >> tab[i];

    for(int i=0; i<qty; i++){
        l = tab[i];
        for(int k=1; k<=l; k++){
            if(l>2 && l%2==0){
                text="NIE";
                break;
            }
            for(int j=1; j<=k; j++){
                if(k%j==0) x++;
                if(x>2) break;
            }
            if(x!=2) text="NIE";
            else text="TAK";
            x=0;
        }
        cout << text << endl;
    }
    return 0;
}
