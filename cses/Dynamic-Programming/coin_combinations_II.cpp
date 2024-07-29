#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9+7;

int main(){
    int n, x;
    cin >> n >> x;

    vector<int> coins;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        coins.push_back(a);
    }

    int res[107][1000007] {};
    for(int i = 1; i <= 100; i++)
        res[i][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= x; k++){
            res[i][k] += res[i-1][k];
            if(k-coins[i-1] >= 0){
                res[i][k] += res[i][k-coins[i-1]];
            }
            res[i][k] %= MOD;
        }
    } 

    // for(int i = 0 ; i<= n; i++){
    //     for(int k = 0; k <= x; k++){
    //         cout << res[i][k] << " ";
    //     }
    //     cout << endl;
    // }

    cout << res[n][x] % MOD;   
}