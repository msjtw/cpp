#include <iostream>

using namespace std;

const int SIZE = 4000;

int res = 0;

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
        res += myhash(s);
    }
    cout << res;
    return 0;
}