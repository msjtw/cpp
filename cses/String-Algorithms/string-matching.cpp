// Rabin-Karp version

#include <iostream>

using namespace std;

typedef long long int ll;

const int MOD = 1e9+9;
const int P = 9973;
const int MX = 1e6+7;

ll ppow[MX];
ll pfx_hash[MX];

int res = 0;

int main(){
    string s, pattern;
    cin >> s >> pattern;
    ppow[0] = 1;
    for(int i = 1 ; i < MX; i++){
       ppow[i] = (ppow[i-1]*P)%MOD; 
    }

    ll pattern_hash = 0;
    for(int i = 0; i < pattern.size(); i++){
        pattern_hash = (pattern_hash + (pattern[i]-'a'+1)*ppow[i])%MOD;
    }

    for(int i = 0; i < s.size(); i++){
        pfx_hash[i+1] = (pfx_hash[i] + (s[i]-'a'+1)*ppow[i])%MOD;
    }

    for(int i = 0; i+pattern.size()-1 < s.size(); i++){
        int a = i, b = i+pattern.size();
        ll sub_hash = pfx_hash[b] - pfx_hash[a]+MOD;
        sub_hash %= MOD;
        if(sub_hash == (pattern_hash*ppow[a])%MOD){
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
