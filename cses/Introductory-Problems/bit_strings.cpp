#include <iostream>

using namespace std;

typedef long long int ll;

const int MOD = 1e9+7;

int pow(int a, int n){
    if(n == 0)
        return 1;
    if(n & 1)
        return ((ll)a * pow(a, n-1))%MOD;
    else{
        int b = pow(a, n/2);
        return ((ll)b*b)%MOD;
    }
}

int main(){
    int a;
    cin >> a;
    cout << pow(2, a);
    return 0;
}
