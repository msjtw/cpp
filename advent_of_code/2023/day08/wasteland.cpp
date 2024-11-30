#include<iostream>
#include<map>

using namespace std;

const int SIZE = 718;

map <string,pair<string,string>> adj;

int main(){
    string ins;
    cin >> ins;
    for(int i = 0; i < SIZE; i++){
        string a, b, c;
        cin >> a >> b >> c;
        adj[a] = {b,c};
    }
    string curr = "AAA";
    int res = 0;
    while(true){
        if(curr == "ZZZ")
                break;
        for(int i = 0; i < ins.length(); i++){
            if(curr == "ZZZ")
                break;
            if(ins[i] == 'L')
                curr = adj[curr].first;
            if(ins[i] == 'R')
                curr = adj[curr].second;
            res++;
        }
    }
    cout << res;
    return 0;
}