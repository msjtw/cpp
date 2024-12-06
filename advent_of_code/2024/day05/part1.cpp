#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<int,int> pii;

vector<pii> rules;

bool is_rule(pii a){
    for(auto rule : rules){
        if(a == rule)
            return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int a, b;
        a = stoi(s.substr(0,s.find('|')));
        s.erase(0, s.find('|')+1);
        b = stoi(s);
        rules.push_back({a, b});
    }
    
    int res = 0;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        vector<int> order;
        string s;
        cin >> s;
        while(!s.empty()){
            int a;
            int poz = s.find(',');
            if(poz != string::npos){
                a = stoi(s.substr(0,poz));
                s.erase(0, s.find(',')+1);
            }
            else{
                a = stoi(s);
                s = "";
            }
            order.push_back(a);
        }
        bool popsuted = false;
        for(int i = 0; i < order.size()-1; i++){
            for(int k = i+1; k < order.size(); k++){
                if(is_rule({order[k], order[i]})){
                    popsuted = true;
                }
            }
        }
        if(!popsuted){
            res += order[order.size()/2];
        }
    }

    cout << res;

    return 0;
}
