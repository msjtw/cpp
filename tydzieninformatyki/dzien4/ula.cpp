#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

long double b = 0;

int main(){
    string s;
    cin >> s;
    for(int i = s.size()-1; i >= 2; i--){
        b+=(s[i]-'0');
        b*=0.5;
    }
    cout << setprecision(12) << b;

    return 0;
}