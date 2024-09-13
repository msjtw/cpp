#include<iostream>
#include<stack>

using namespace std;

const int MX= 1e6+7;

int pi[MX];

int main(){
    string s;
    cin >> s;
    for(int i = 1; i < s.size(); i++){
        int k = pi[i-1];
        while(k > 0 and s[i] != s[k])
            k = pi[k-1];
        if(s[i] == s[k])
            k++;
        pi[i] = k;
    }

    stack <int> res;
    int k = pi[s.size()-1];
    while(k > 0){
        res.push(k);
        k = pi[k-1];
    }

    while(!res.empty()){
        cout << res.top() << " ";
        res.pop();
    }

    return 0;
}
