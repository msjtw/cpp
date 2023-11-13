#include <iostream>

using namespace std;

int main(){
    int maxi = 0;
    int a, b;
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        for(int k = i ; k <=b; k++){
            maxi = max(maxi, i^k);
        }
    }
    cout << maxi;
    return 0;
}