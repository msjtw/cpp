#include <iostream>
#include <vector>

using namespace std;

void all(string s, int i, vector<string>& per){
    if(i == s.size()){
        per.push_back(s);
        return;
    }
    if(s[i] == '?'){
        s[i] = '#';
        all(s, i+1, per);
        s[i] = '.';
        all(s, i+1, per);
    }
    else{
        all(s, i+1, per);
    }
}

int main(){
    int p;
    int res = 0;
    cin >> p;
    while(p --> 0){
        string row;
        cin >> row;
        int gr;
        cin >> gr;
        vector<int> groups;
        for(int i = 0; i < gr; i++){
            int a;
            cin  >> a;
            groups.push_back(a);
        }
        vector<string> per;
        all(row, 0, per);
        for(string ver : per){
            vector<int> groups2;
            int len = 0;
            for(int i = 0 ; i < ver.length(); i++){
                if(ver[i] == '#'){
                    len++;
                }
                else{
                    if(len > 0)
                        groups2.push_back(len);
                    len = 0;
                }
            }
            if(len > 0)
                groups2.push_back(len);
            if(groups == groups2)
                res++;
        }
        
    }
    cout << res;
    return 0;
}