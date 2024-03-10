#include<iostream>
#include<vector>

using namespace std;

typedef long long int ll;

vector<int> arr;

int div(ll max_sum){
    int d = 0;
    ll sum = 0;
    for(int a : arr){
        if(a > max_sum)
            return __INT_MAX__;
        else if(sum + a > max_sum){
            sum = a;
            d++;
        }
        else{
            sum += a;
        }
    }
    if(sum > 0)
        d++;
    return d;
}

int main(){
    int n, k;
    cin >> n >> k;
    ll total = 0;
    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        total += a;
        arr.push_back(a);
    }

    ll res = 0;
    for(ll b = total/2; b >= 1; b/=2){
        while(div(res + b) > k)
            res += b;
    }

    
    cout << res+1;

    return 0;
}