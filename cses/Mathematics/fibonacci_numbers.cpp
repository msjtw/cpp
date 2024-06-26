#include<iostream>
#include<bitset>
#include<algorithm>

using namespace std;

typedef long long int ll;

const int MOD = 1e9+7;

void mul(ll a[][2], ll b[][2]){
    ll res[2][2];
    res[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    res[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    res[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    res[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];

    a[0][0] = res[0][0] % MOD;
    a[0][1] = res[0][1] % MOD;
    a[1][0] = res[1][0] % MOD;
    a[1][1] = res[1][1] % MOD;
}

int main(){
    ll n;
    cin >> n;
    ll m_pow[2][2] =
            {{0, 1},
             {1, 1}};
    ll m[2][2] =
            {{1, 0},
             {0, 1}};

    auto pow = bitset<64> (n);

    for(int i = 0 ; i < 64; i++){
        if(pow[i]){
            mul(m,m_pow);
        }
        mul(m_pow, m_pow);
    }

    cout << m[0][1];

    return 0;
}