#include<iostream>
#include<queue>
 
using namespace std;

typedef long long int ll;

const int TMX = 1e6+7;
const int MX = 1000;
const int MOD = 1e9+7;
 
int trie[TMX][30];
bool stop[TMX];
int next_node = 1;
ll res = 0;
ll dp[MX];
 
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

void zero(){
    for(int i = 0; i < MX; i++){
        dp[i] = 0;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        insert(s);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        zero();
        string text;
        cin >> text;
        dp[text.size()] = 1;
        for(int i = text.size()-1; i >= 0; i--){
            int idx = 0;
            for(int k = i; k < text.size(); k++){
                if(trie[idx][text[k]-'a'] == 0)
                    break;
                idx = trie[idx][text[k]-'a'];
                if(stop[idx]){
                    dp[i] = (dp[i] + dp[k+1]);
                }
            }
        }
        res += dp[0];
    }
 
    cout << res;
 
    return 0;
}
