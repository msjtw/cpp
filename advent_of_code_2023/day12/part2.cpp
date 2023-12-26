#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long int ll;

long long int res = 0;

map<string, map<vector<int>, ll>> memo;

ll all(string row, vector<int> groups){
    if(memo.count(row) > 0){
        if(memo[row].count(groups) > 0){
            return memo[row][groups];
        }
    }

    if(row == ""){
        if(groups.empty())
            return 1;
        return 0;
    }
    if(groups.empty()){
        if(row.find('#') == string::npos)
            return 1;
        return 0;
    }

    ll ret = 0;

    if(row[0] != '.'){
        bool len = row.length() >= groups[0];
        bool can_fit = row.substr(0,min(groups[0],(int)row.length())).find('.') == string::npos;
        bool del_next = (row.length() == groups[0]) or (len and row[groups[0]] != '#');
        if(len and can_fit and del_next){
            vector<int> args (groups.begin()+1,groups.end());
            ret += all(row.substr(min(groups[0] + 1,(int)row.length())), args);
        }

    }
    if(row[0] != '#'){
        ret += all(row.substr(1), groups);
    }
 
    memo[row][groups] = ret;
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
        res += all(rows[i], groups[i]);
    }

    cout << res;

    return 0;
}