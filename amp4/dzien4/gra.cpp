#include<iostream>
#include<string>
using namespace std;
int main(){
    string s,t; cin>>s>>t;
    int a = 0;
    for(int i = 0;i<s.size();i+=2){
        if((s[i]=='[' && t[i]=='(')||(s[i]=='(' && t[i]=='8')||(s[i]=='8' && t[i]=='['))++a;
        else if((t[i]=='[' && s[i]=='(')||(t[i]=='(' && s[i]=='8')||(t[i]=='8' && s[i]=='['))--a;
    }
    if(a>0)cout<<"EKIPA 1 WYGRYWA";
    else if(a==0)cout<<"REMIS";
    else cout<<"EKIPA 2 WYGRYWA";
}