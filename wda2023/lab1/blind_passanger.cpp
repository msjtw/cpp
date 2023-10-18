#include<iostream>

using namespace std;

int main(){
    int p;
    cin >> p;
    while(p --> 0){
        int a;
        string s;
        cin >> a;
        if(a == 1){
            cout << "poor conductor" << endl;
            continue;
        }
        cout << (a+3)/5 << " ";
        a%=10;
        if(a == 1 or a == 2 or a == 6 or a == 7)
            cout << "W ";
        else if(a == 5 or a == 8)
            cout << "M ";
        else 
            cout << "A ";
        if(a < 4)
            cout << "L" << endl;
        else
            cout << "R" << endl;
    }
    return 0;
}