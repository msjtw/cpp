#include <iostream>

using namespace std;


int main(){
    int wyn  = 0;
    int p;
    cin >> p;
    while(p--){
        int a;
        cin >> a;
        int n = 0;
        do{
            n = 0;
            while(a){
                n+=a%10;
                a/=10;
            }
            a = n;
        }while(n > 9);
        if(n == 1)
            wyn++;
    }
    cout << wyn;
    return 0;
}