#include <iostream>

using namespace std;



int main(){
    ios_base::sync_with_stdio(0);

    long long int liczba;
    cin >> liczba;

    int dziel = 0;

    while(!(liczba & 1)){
        dziel++;
        liczba >>= 1;
    }

    cout << dziel << " " << 1;

    return 0;
}