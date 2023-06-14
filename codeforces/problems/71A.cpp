// Way Too Long Words https://codeforces.com/problemset/problem/71/A

#include <iostream>

using namespace std;

int main(){
    int p;
    cin >> p;
    while(p-->0){
        string s;
        cin >> s;
        if(s.length() > 10)
            cout << s[0] << s.length()-2 << s[s.length()-1];
        else
            cout << s;
        cout << endl;
    }
    return 0;
}