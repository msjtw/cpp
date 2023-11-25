#include <iostream>
#include <string>
#include <climits>

using namespace std;

int na10(string a, int base){
    long long int wyn = 0;
    for(auto c : a){
        wyn *= base;
        wyn += c-'0';
    }
    return wyn;
}

int main(){
    long long int ilosc = 0;
    int p = 999;
    long long int mini = INT_MAX;
    long long int maxi = 0;
    string kod_mini;
    string kod_maxi;
    while(p --> 0){
        string a;
        cin >> a;
        int wart = na10(a.substr(0,a.length()-1), a[a.length()-1]-'0');
        if(wart < mini){
            mini = wart;
            kod_mini = a;
        }
        else if(wart > maxi){
            maxi = wart;
            kod_maxi = a;
        }
    }

    cout << kod_mini << endl;
    cout << kod_maxi << endl;
    cout << mini << endl;
    cout << maxi << endl;
    
    return 0;
}