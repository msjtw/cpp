#include<iostream>

using namespace std;

const int MOD = 1e9+7;

int exp(int x, int e){
    if(e == 0)
        return 1;
    if(e&1){
        return ((long long int)x*exp(x, e-1))%MOD;
    }
    else{
        long long int a = exp(x, e/2);
        return  (a*a)%MOD;
    }
}

int main(){
    int n;
    cin >> n;
    while(n --> 0){
        int a, b;
        cin >> a >> b;
        cout << exp(a, b) << "\n";
    }
    return 0;
}