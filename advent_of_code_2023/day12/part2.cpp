#include <iostream>
#include <vector>
#include <thread>

using namespace std;

int res = 0;

int memo[1000] {};

int all(string s, int i, vector<int>& groups){
    if(memo[i] != -1)
        return memo[i];
    int ret = 0;
    if(i == s.size()){
        vector<int> groups2;
        int len = 0;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '#'){
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
            ret = 1;
        ret = 0;
    }
    else if(s[i] == '?'){
        s[i] = '#';
        res += all(s, i+1, groups);
        s[i] = '.';
        res += all(s, i+1, groups);
    }
    else{
        res += all(s, i+1, groups);
    }
    memo[i] = ret;
    return ret;
}

int main(){
    int p, p2;
    cin >> p;
    p2 = p;

    vector<string> rows;
    vector<vector<int>> groups;

    while(p --> 0){
        string row;
        cin >> row;
        row = row + "?" + row + "?" + row + "?" + row + "?" + row;
        int gr;
        cin >> gr;
        vector<int> group3;
        vector<int> group;
        for(int i = 0; i < gr; i++){
            int a;
            cin  >> a;
            group3.push_back(a);
        }
        int pp = 5;
        group.reserve(group3.size()*6);
        while(pp -->0 ){
            group.insert(group.end(),group3.begin(),group3.end());
        }
        rows.push_back(row);
        groups.push_back(group);
    }


    for(int i = 0; i < rows.size(); i++){
        for(int i = 0; i < 1000; i++){
            memo[i] = -1;
        }
        cout << rows[i] << endl;
        for(int a : groups[i])
            cout << a << " ";
        cout << endl; 
        res += all(rows[i], 0, groups[i]);
    }

    cout << res;

    return 0;
}