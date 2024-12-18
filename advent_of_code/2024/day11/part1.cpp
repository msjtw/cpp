#include <iostream>
#include <map>

using namespace std;

typedef long long int ll;
typedef pair<int, ll> pii;

map <pii, ll> chache;

ll dp(int it, ll num){
    if(chache.find({it, num}) != chache.end()){
        return chache[{it, num}];
    }
    ll r;
    if(it == 75)
        r = 1;
    else if(num == 0){
        r = dp(it+1, 1);
    }
    else if(!(to_string(num).length() &1)){
        string s_num = to_string(num);
        ll a = stoi(s_num.substr(0, s_num.length()/2));
        ll b = stoi(s_num.substr(s_num.length()/2, s_num.length()/2));
        r = dp(it+1, a) + dp(it+1, b);
    }
    else {
        r = dp(it+1, num*2024);
    }
    chache[{it, num}] = r;
    return r;
}

int main(){
    ll res = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        res += dp(0,a);
    }
    cout << res;
    return 0;
}
