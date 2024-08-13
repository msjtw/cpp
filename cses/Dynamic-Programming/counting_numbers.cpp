#include <iostream>
#include <string>

using namespace std;

typedef long long int ll;

ll memo[20][10][2][2] {};
string upper;

void zero(){
    for(int a = 0; a < 20; a++){
        for (int b = 0; b < 10; b++){
            for(int c = 0; c < 2; c++){
                for(int d = 0; d < 2; d++){
                    memo[a][b][c][d] = -1;
                }
            }
        }
    }
}

ll dp(int n, int last, bool under, bool leading){

    if(memo[n][last][under][leading] != -1)
        return memo[n][last][under][leading];

    ll ret = 0;
    
    if(n == upper.size()){
       ret = 1;
    }
    else{
        for(int i = 0; i < 10; i++){
            if(!under and i > upper[n]-'0')
                break;
            if(i == last and !leading)
                continue;

            bool now_under = under;
            if(i < upper[n]-'0')
                now_under = true;
            bool now_leading = leading;
            if(i != 0 and leading)
                now_leading = false;
            ret += dp(n+1, i, now_under, now_leading);
        }
    }
    memo[n][last][under][leading] = ret;
    return ret;
}

int main(){
    ll a, b;
    cin >> a >> b;
    zero();
    upper = to_string(a-1);
    ll res_a = dp(0, 0, false, true);
    zero();
    upper = to_string(b);
    ll res_b = dp(0, 0, false, true);
    cout << res_b - res_a;
    return 0;
}
