#include <iostream>

using namespace std;

int main(){
    int a;
    cin >> a;

    int k = 2;

    while(a > 1){
        while(a%k == 0){
            cout << k << " ";
            a /= k;
        }
        k++;
    }

    return 0;
}