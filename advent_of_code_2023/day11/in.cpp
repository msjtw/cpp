#include <iostream>
#include <vector>

using namespace std;

vector <char> res[140];

int main(){
    string s;
    int k = 0;
    while(cin >> s){
        for(int i = 0; i < s.length(); i++){
            res[i].push_back(s[i]);
        }
        k++;
    }
    for(int i = 0 ; i < 140; i ++){
        for(auto a : res[i]){
            cout << a;
        }
        cout << endl;
    }

    return 0;
}