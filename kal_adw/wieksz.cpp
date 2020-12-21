#include <iostream>
#include <algorithm>

using namespace std;

int tab[1000] {};

int main(){
    for(int i = 0; i < 10000; i++){
        int a;
        cin >> a;
        tab[a]++;
    }
    int m = 0;
    for(int i = 0; i < 1000; i++){
        m = max(m,tab[i]);
    }
    cout << m;
    return 0;
}