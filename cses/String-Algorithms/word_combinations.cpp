#include<iostream>

using namespace std;

const int TMX = 1e6+7;
const int MX = 5007;
const int MOD = 1e9+7;

int trie[TMX][30];
bool stop[TMX];
int next_node = 1;
int dp[MX];

void insert(string s){
    int idx = 0;
    for(char c : s){
        if(trie[idx][c-'a'] == 0){
            trie[idx][c-'a'] = next_node;
            next_node ++;
        }
        idx = trie[idx][c-'a'];
    }
    stop[idx] = true;
}

int main(){
    string text;
    int n;
    cin >> text >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        insert(s);
    }

    dp[text.size()] = 1;
    for(int i = text.size()-1; i >= 0; i--){
        int idx = 0;
        for(int k = i; k < text.size(); k++){
            if(trie[idx][text[k]-'a'] == 0)
                break;
            idx = trie[idx][text[k]-'a'];
            if(stop[idx]){
                dp[i] = (dp[i] + dp[k+1])%MOD;
            }
        }
    }

    cout << dp[0];

    return 0;
}
