#include <iostream>

using namespace std;

typedef long long int ll;

const int MX = 20;

int arr[MX];
int n;

ll sum(int mask){
    ll ret = 0;
    int i = n-1;
    while(mask){
        if(mask&1)
            ret += arr[i];
        mask>>=1;
        i--;
    }
    return ret;
}

int main(){
    cin >> n;
    ll total = 0;
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
        total += arr[i];
    }
    ll mini = __INT64_MAX__;
    for(int mask = 0; mask < 1<<n; mask++){
        ll sum1 = sum(mask);
        ll sum2 = total - sum1;
        mini = min(mini, abs(sum1-sum2));
    }
    cout << mini;
    return 0;
}
