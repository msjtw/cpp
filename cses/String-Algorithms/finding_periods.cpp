#include<iostream>

using namespace std;

typedef long long int ll;

const int MX = 1e6+7;
const int MOD = 1e9+9;
const int P = 9973;

ll pfx_hash[MX];
ll ppow[MX];

int main(){
    string s;
    cin >> s;
    /* cout << s.length() << endl; */
    
    ppow[0] = 1;
    for(int i = 1; i < MX; i++){
        ppow[i] = (ppow[i-1]*P)%MOD;
    }

    for(int i = 0; i < s.size(); i++){
        pfx_hash[i+1] = (pfx_hash[i] + (s[i]-'a'+1)*ppow[i])%MOD;
    }
    bool popsuted = false;
    for(int l = 1; l <= s.length(); l++){
        popsuted = false;
        /* cout << l << ": " << endl; */
        for(int i = 0 ; i < s.length(); i+=l){
            /* cout << i; */
            if(i+l <= s.size()){
                /* cout << "a"; */
                ll cur_hash = (pfx_hash[i+l]-pfx_hash[i]+MOD)%MOD;
                if(cur_hash != (pfx_hash[l]*ppow[i])%MOD)
                    popsuted = true;
                /* cout << (popsuted ? 1 : 0) << " "; */
            }
            else{
                /* cout << "b"; */
                int le = s.size() - i;
                ll cur_hash = (pfx_hash[i+le]-pfx_hash[i]+MOD)%MOD;
                if(cur_hash != (pfx_hash[le]*ppow[i])%MOD)
                    popsuted = true;
                /* cout << (popsuted ? 1 : 0) << " "; */
            }
        }
        /* cout << endl; */
        if(!popsuted)
            cout << l << " ";
    }
    return 0;
}
