#include <iostream>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;

const int SIZE = 4000;

int res = 0;

deque<string> boxes[256];
map<string, int> focal;

int myhash(string s){
    int ret = 0;
    for(auto a : s){
        ret += int(a);
        ret *= 17;
        ret %= 256;
    }
    return ret;
}

int main(){
    for(int i = 0; i < SIZE; i++){
        string s;
        cin >> s;
        string label = "";
        string op = "";
        int box_id = 0;
        int k = 0 ;
        while(s[k] != '-' and s[k] != '='){
            label += s[k];
            k++;
        }
        op = s[k];
        if(op == "="){
            focal[label] = s[k+1]-'0';
        }
        box_id = myhash(label);
        if(op == "-"){
            auto poz = find(boxes[box_id].begin(),boxes[box_id].end(),label);
            if(poz != boxes[box_id].end()){
                boxes[box_id].erase(poz);
            }
        }
        if(op == "="){
            auto poz = find(boxes[box_id].begin(),boxes[box_id].end(),label);
            if(poz != boxes[box_id].end()){
                *poz = label;
            }
            else{
                boxes[box_id].push_back(label);
            }
        }
    }
    for(int i = 0; i < 256; i++){
        int k = 1;
        for(string label : boxes[i]){
            res += ((i+1)*k*focal[label]);
            k++;
        }
    }
    cout << res;
    return 0;
}