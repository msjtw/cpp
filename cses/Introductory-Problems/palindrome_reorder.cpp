#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int letters[300] {};
    for(char c : s)
        letters[c]++;
    bool one_odd = false;
    string res;
    for(char c = 'A'; c <= 'Z'; c++){
        if(letters[c] % 2 == 0){
            string tmp = "";
            for(int i = 0 ; i < letters[c]/2; i++){
                tmp += c;
            }
            res = tmp + res + tmp;
        }
        else if(!one_odd){
            one_odd = true;
            string tmp = "";
            for(int i = 0 ; i < letters[c]/2; i++){
                tmp += c;
            }
            res = tmp + res + tmp;
            string mid(1, c);
            res.insert(res.length()/2, mid);
        }
        else{
            cout << "NO SOLUTION";
            return 0;
        }
    }
    cout << res;
    return 0;
}
