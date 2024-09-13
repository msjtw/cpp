#include <cstdint>
#include <iostream>

using namespace std;

typedef long long int ll;

ll res = 0;
ll primes[22];
ll ptest;

int main(){
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> primes[i];
    }
    for(int mask = 1; mask < 1<<k; mask++){
        ll prod = 1;
        int nn = 0;
        for(int i = 0; i < k; i++){
            if(1<<i & mask){
                if(prod > INT64_MAX/primes[i]){
                    nn = -1;
                    break;
                }
                else{
                    prod *= primes[i];
                    nn++;
                }
            }
        }
        if(!(nn & 1)){
            res -= n/prod;
        }
        else if(nn != -1){
            res += n/prod;
        }

    }
    cout << res;
    return 0;
}
