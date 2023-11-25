#include <iostream>

using namespace std;

int main(){
    int m;
    cin >> m;
    int t[1000007] {};
    int licznik = 0;
    for(int i = 0; i < m; i++){
        cin >> t[i];
    }
    for(int i = m-1; i > 0; i--){
        if(t[i-1] >= t[i]){
            licznik++;
            t[i-1] = t[i]-1;
            if(t[i-1] < 0){
                cout << -1;
                return 0;
            }
        }
    }

    cout << licznik;

    return 0;
}