#include <iostream>

using namespace std;

typedef long long int ll;

const int MOD = 1e9+7;

int n, m; // n - collumns <= 10, m - rows <= 1000
int memo[1001][1<<10] {};

void zero(){
    for(int a = 0; a < 1001; a++){
        for(int b = 0; b < 1<<10; b++){
            memo[a][b] = -1;
        }
    }
}

int dp(int row, int mask){
    if(row == m){
        if(mask == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(memo[row][mask] != -1){
        return memo[row][mask];
    }

    int ret = 0;
    for(int new_mask = 0; new_mask < 1<<n; new_mask++){
        if(mask & new_mask) // if new_mask has vertical elements on the same places as mask
            continue;
        int tmp = new_mask | mask;
        int curr = 0;
        bool skip = false;
        for(int i = 0; i < n; i++){
            if(1<<i & ~tmp){
                curr++;
            }
            else{
                if(curr & 1){
                    skip = true;
                    break;
                }
                curr = 0;
            }
        }
        if(curr &1)
            skip = true;
        if(skip){
            continue;
        }
        new_mask = new_mask & ~mask;
        ret = ((ll)ret + dp(row+1, new_mask))%MOD;
    }

    memo[row][mask] = ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    zero();
    cout << dp(0, 0) << endl;
    return 0;
}
