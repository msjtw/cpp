#include <iostream>

using namespace std;

const int MX = 2e6+7;

int p[MX];

int main(){
    string txt1, txt = "#";
    cin >> txt1;
    for(char c : txt1){
        string s{c};
        txt += s + "#";
    }
    txt = "^" + txt + "$";
    int l = 1, r = 1;
    for(int i = 1; i < txt.size(); i++){
        p[i] = max(0, min(r-i, p[l+r-i]));
        while(txt[i-p[i]] == txt[i+p[i]])
            p[i]++;
        if(i+p[i] > r){
            l = i-p[i];
            r = i+p[i];
        }
    }
    int maxi = 0;
    int imaxi;
    for(int i = 0; i < txt.size(); i++){
        if(p[i] > maxi){
            maxi = p[i];
            imaxi = i;
        }
    }
    string res = txt.substr(imaxi-maxi+1,maxi*2-1);
    for(auto c : res){
        if(c != '#')
            cout << c;
    }
    return 0;
}
