#include <iostream>

using namespace std;

int r(int a, int b){
    int wyn = 0;
    while(a){
        if(a%10 != b%10)
            wyn++;
        a /= 10;
        b /= 10;
    }
    return wyn;
}

int main(){
    ios_base::sync_with_stdio(0);

    int p;
    cin >> p;
    while(p--){
        int a;
        cin >> a;
        int b = a;
        while(b % 7 != 0)
            b--;
        int c = a;
        while(c % 7 != 0)
            c++;

        if(b < 100)
            cout << c << endl;
        else if(c > 999)
            cout << b << endl;
        else{
            if(r(a,b) > r(a,c))
                cout << c << endl;
            else
                cout << b << endl;
        }
    }
    return 0;
}