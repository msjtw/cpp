#include<iostream>
#include<map>
#include<vector>

using namespace std;

int SIZE = 718;

map <string,pair<string,string>> adj;
vector<string> curr;

bool end(){
    for(auto a : curr){
        if(a[2] != 'Z')
            return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> SIZE;

    string ins;
    cin >> ins;
    for(int i = 0; i < SIZE; i++){
        string a, b, c;
        cin >> a >> b >> c;
        adj[a] = {b,c};
        if(a[2] == 'A')
            curr.push_back(a);
    }

    
    cout << curr.size() << endl;

    vector<int> res;
    for(auto a : curr){
        int r = 0;
        int i = 0;
        while(a[2] != 'Z'){
            if(i == ins.length())
                i =0;
            if(ins[i] == 'L')
                a = adj[a].first;
            else
                a = adj[a].second;
            i++;
            r++;
        }
        res.push_back(r);
    }


    for(auto a : res)
        cout << a << " ";
    return 0;
}