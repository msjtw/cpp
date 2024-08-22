#include<iostream>

using namespace std;

typedef long long int ll;

int exp(int a, int b, int MOD){
    if(b == 0)
        return 1;
    if(b & 1){
        return ((ll)a * exp(a, b-1, MOD))%MOD;
    }
    ll tmp = exp(a, b/2, MOD);
    return (tmp*tmp)%MOD;
}

int main(){
    int p;
    cin >> p;
    while(p --> 0){
        int a, b ,c;    
        cin >> a >> b >> c;
        int exp1 = exp(b, c, 1e9+6);
        cout << exp(a, exp1, 1e9+7) << endl;
    }
    return 0;
}
