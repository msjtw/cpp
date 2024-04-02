#include<iostream>

using namespace std;

const int MX = 1e6+7;

int divisors[MX];

int main(){
    for(int i = 1; i < MX; i++){
        for(int k = i; k < MX; k += i){
            divisors[k]++;
        }
    }
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        cout << divisors[a] << "\n";
    }
    return 0;
}