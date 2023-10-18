#include <iostream>

using namespace std;

    int sito[1000007] {};
        int ilosc[1000007] {};

int main(){

    ios_base::sync_with_stdio(0);

    sito[0] = 1;
    sito[1] = 1;
    for(int i = 2; i < 1000007; i++){
        for(int k = i+i ; k < 1000007; k+=i){
            sito[k] = 1;
        }
    }



    for(int i = 1; i < 1000007; i++){
        ilosc[i] = ilosc[i-1];
        if(sito[i] == 0)
            ilosc[i]++;
    }

    int p;
    cin >> p;
    while(p--){
        int a, b;
        cin >> a >> b;
        cout << ilosc[b] - ilosc[a-1] << endl;;
    }

    return 0;
}