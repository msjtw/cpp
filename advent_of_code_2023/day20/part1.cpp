#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<cctype>

using namespace std;

map<string, vector<string>> adj;
map<string, vector<string>> adj_rev;
map<string, char> type;
map<string, int> state;

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        string lab;
        int m;
        cin >> lab >> m;
        char t = lab[0];
        if(!isalpha(t))
            lab.erase(lab.begin()); 
        type[lab] = t;
        while(m --> 0){
            string a;
            cin >> a;
            adj[lab].push_back(a);
            adj_rev[a].push_back(lab);
        }
    }

    
    n = 1000;
    int pulses[] = {n,0};

    while(n --> 0){
        queue<pair<string, int>> q;
        q.push({"broadcaster", 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            string lab = p.first;
            int sig = p.second;
            if(type[lab] == '%'){
                if(sig == 0){
                    state[lab] = 1 - 1*state[lab];
                    for(string v : adj[lab]){
                        pulses[state[lab]]++;
                        q.push({v, state[lab]});
                    }
                }
            }
            else if(type[lab] == '&'){
                bool low = true;
                for(string v : adj_rev[lab]){
                    if(state[v] == 0)
                        low = false;
                }
                sig = (low ? 0 : 1);
                state[lab] = sig;
                for(string v : adj[lab]){
                    pulses[sig]++;
                    q.push({v, sig});
                }
            }
            else{
                state[lab] = sig;
                for(string v : adj[lab]){
                    pulses[state[lab]]++;
                    q.push({v, state[lab]});
                }
            }
        }
    }
    cout << pulses[0] * pulses[1];

    return 0;
}