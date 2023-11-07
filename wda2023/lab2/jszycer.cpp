#include<iostream>

using namespace std;
 
string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFG";

 int main(){
    string s;
    while(getline(cin, s)){
        for(char c : s)
            if(c == ' ')
                cout << c;
            else
                cout << a[c-'A'+3];
            //cout <<  (c == ' ' ? " " : a[c-'A'+3]);
        cout << endl;
    }
    return 0;
 }