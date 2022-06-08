#include <iostream>
#include <string>

using namespace std;

string bin(int a){
    string w;
    while(a){
        w = char(a%2 + '0') + w;
        a /= 2;
    }
    return w;
}

string hex(int a){
    string symbols = "0123456789ABCDEF";
    string w;
    while(a){
        w = symbols[a%16] + w;
        a /= 16;
    }
    return w;
}

int main(){
    int a;
    cin >> a;
    cout << bin(a) << endl << hex(a);
    return 0;

}