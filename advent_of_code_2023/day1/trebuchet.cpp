#include <iostream>
#include <cctype>

using namespace std;

int main(){
    int res = 0;
    string s;
    while(cin >> s){
        int a, b;
        a =  b = -1;
        for(auto c : s){
            if(isdigit(c)){
                if(a == -1){
                    a = c - '0';
                }
                b = c - '0';
            }
        }
        res += a*10;
        res += b;
    }
    cout << res;
}