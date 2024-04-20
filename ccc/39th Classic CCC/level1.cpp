#include<iostream>

using namespace std;

int main(){
    int p;
    cin >> p;
    while(p --> 0){
        int num[300] {};
        string s;
        cin >> s;
        for(char c : s)
            num[c]++;

        cout << num['W'] << " " << num['D'] << " " << num['S'] << " " << num['A'] << '\n';
    }
}