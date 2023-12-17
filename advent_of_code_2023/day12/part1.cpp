#include <iostream>
#include <vector>pl

using namespace std;

int solve(string s, vector<int> gr){
    s = "?" + s;
    int dp[1000][1000] {};
    for(int i = 1; i < gr.size(); i++){
        for(int k = 1; k < s.length(); k++){
            if(k - gr[i] >= 0){
                if(s[k] != '.'){
                    if(s[k-gr[i]] != '#'){
                        string s2 = s.substr(k-gr[i]+1,gr[i]);
                        int nhash = gr[i];
                        for(auto a : s2)
                            if(a == '.')
                                nhash--;
                        if(nhash == gr[i]){
                            dp[i][k] = dp[i][k-gr[i]] +1;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int res = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int m;
        cin >> m;
        vector<int>groups ;
        groups.push_back(0);
        for(int k =0; k < m; k++){
            int a;
            cin >> a;
            groups.push_back(a);
        }
        res += solve(s, groups);
    }
}