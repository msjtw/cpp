#include <iostream>

using namespace std;

int dp[5007][5007];

int main(){
    for(int i = 0 ; i < 5007; i++){
        dp[i][0] = i;
        dp[0][i] = i;
    }

    string s1, s2;
    cin >> s1 >> s2;

    for(int i = 1; i <= s1.length(); i++){
        for(int k = 1; k <= s2.length(); k++){
            int v1 = dp[i-1][k] + 1;
            int v2 = dp[i][k-1] + 1;
            int v3 = dp[i-1][k-1] + (s1[i-1] == s2[k-1] ? 0 : 1);
            dp[i][k] = min(v1, min(v2, v3));
        }
    }

    // for(int i = 0; i <= s1.length(); i++){
    //     for(int k = 0; k <= s2.length(); k++){
    //         cout << dp[i][k] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[s1.length()][s2.length()];

    return 0;
}