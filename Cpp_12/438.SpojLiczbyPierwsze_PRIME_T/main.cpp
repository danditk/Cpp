#include <iostream>

using namespace std;

int n,x=0;
string text;

int main()
{
    cin >> n;
    for(int i=1; i<n; i++){
        for(int j=1; j<=i; j++){
            if(i%j==0){
                    x++;
            }
        }
        if(x!=2) text="NIE";
        else text="TAK";
        x=0;
        cout << text << endl;

    }
    return 0;
}
