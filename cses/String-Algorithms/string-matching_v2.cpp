// Knuth-Morris-Pratt

#include <iostream>

using namespace std;

const int MX = 2e6+7;

int pi[MX];

int main(){
    string text, pattern;
    cin >> text >> pattern;
    string s = pattern + "+" + text;
    for(int i = 1; i < s.size(); i++){
        int j = pi[i-1];
        while(j > 0 and s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }

    int res = 0;
    for(int i = 0; i < s.size(); i++){
        if(pi[i] == pattern.size())
            res++;
    }

    cout << res;
    return 0;

}
