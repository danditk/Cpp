#include <iostream>

using namespace std;

long n=100000;
int x=0,l;
string text;

int main()
{
    for(int i=1; i<n; i++){
        cin>>l;
        for(int k= 1; k<=l; k++){
            for(int j=1; j<=k; j++){
                if(k%j==0){
                        x++;
                }
            }
            if(x!=2) text="NIE";
            else text="TAK";
            x=0;
        }
        cout << text << endl;
    }
    return 0;
}
