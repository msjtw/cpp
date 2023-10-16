// https://codeforces.com/problemset/problem/4/C

#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, int> names;
    int p;
    cin >> p;
    while(p --> 0){
        string s;
        cin >> s;
        if(names[s]==0){
            cout << "OK" << endl;
        }
        else{
            cout << s << names[s] << endl;
        }
        names[s]++;
    }
}