#include<iostream>

using namespace std;

int main(){
    int p;
    cin >> p;
    while(p-->0){
        unsigned int a;
        cin >> a;
        a = ~a;
        cout << a << endl;
    }

    return 0;
}