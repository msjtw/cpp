#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);

    int wierz, szar;
    cin >> wierz >> szar;
    int sz[1007] {};

    for(int i = 0; i < szar; i++){
        int a, b;
        cin >> a >> b;
        sz[a]++;
        sz[b]++;
    }

    int rozno = 0;

    for(int i = 1; i <= wierz; i++)
        rozno += sz[i] * (wierz - sz[i] - 1);
    
    rozno /= 2;

    cout << (wierz*(wierz-1)*(wierz-2)/6 )- rozno;

    return 0;
}