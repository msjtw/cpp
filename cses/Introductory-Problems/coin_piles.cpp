#include <iostream>

using namespace std;

int main(){
    int p;
    cin >> p;
    while(p --> 0){
        int a, b;
        cin >> a >> b;
        if((2*a >= b and a <= 2*b and (a+b)%3 == 0)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
