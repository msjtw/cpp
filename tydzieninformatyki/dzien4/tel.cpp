#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int btd(int a){
    int b = 0;
    vector <int> v;
    while(a > 0){
        v.push_back(a%10);
        a/=10;
    }
    reverse(v.begin(), v.end());
    for(int c : v){
        b *= 2;
        b+=c;
    }
    return b;
}

int main(){
    string s;
    int a;
    while(cin >> a){
        cout << char(btd(a));
    }

    //cout << s;

    return 0;
}