#include <iostream>

using namespace std;

int main(){
    int len;
    cin >> len;
    int licznik = 0;
    int maxi = 0;
    for(int i = 0 ; i < len; i++){
        int a;
        cin >> a;
        if(a == 0)
            licznik++;
        else{
            maxi = max(maxi, licznik);
            licznik = 0;
        }
    }
            maxi = max(maxi, licznik);

    

    cout << maxi;

    return 0;
}