#include <iostream>
#include <string>

using namespace std;

int main(){
    string slowo = "";
    string a;
    int max_ilosc = 0;
    for(int i = 0; i < 1000; i++){
        int maxi = 0, mini = 500;
        cin >> a;
        for(auto c : a){
            mini = min(mini, (int)c);
            maxi = max(maxi, (int)c);
        }
        if(maxi-mini <= 10){
            cout << a << "\r\n";
        }
    }
    return 0;
}