#include<iostream>

using namespace std;

typedef long long int lli;

const int MOD = 1e9+7;
const int SIZE = 1e6+7;

int one[SIZE];
int two[SIZE];

int main(){
    one[1] = 1;
    two[1] = 1;

    for(int i = 2; i < 1e6+1; i++){
        one[i] = (2LL*one[i-1] + two[i-1])%MOD;
        two[i] = (4LL*two[i-1] + one[i-1])%MOD;
    }

    int n;
    cin >> n;
    while(n --> 0){
        int a;
        cin >> a;
        cout << ((lli)one[a]+two[a])%MOD << endl;
    }

    return 0;
}
