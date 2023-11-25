#include <iostream>

using namespace std;

int todec(string a){
    int wyn = 0;
    for(auto c : a){
        wyn *= 2;
        wyn += c-'0';
    }
    return wyn;
}

void tobin(int a){
    cout << a << endl;
    string wyn;
    while(a > 0){
        wyn = char(a%2) + wyn;
        a /= 2;
    }
    cout << wyn;
}

int main(){
    int p;
    int ilosc = 0;
    string naj;
    int wart = 0;
    cin >> p;

    while(p --> 0){
        string a;
        cin >> a;
        int b = todec(a);
        if(b > wart && b <= 65535){
            wart = b;
            naj = a;
        }
    }

    cout << naj << endl << wart;

    return 0;
}