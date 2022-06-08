#include <iostream>

using namespace std;


int nwd(int a, int b){
    while(b)
        swap(a%=b,b);
    return a;
}

int wlen = 0, wpier, wnwdd;

int main(){
    int p;
    cin >> p;
    int tab[2007] {};
    for(int i = 0; i < p; i++){
        cin >> tab[i];
    }
    for(int i = 0; i < p; i++){
        int pier = tab[i];
        int nwdd = tab[i];
        int len = 1;
        int k = i+1;
        while(k < p && nwd(nwdd, tab[k]) != 1){
            nwdd = nwd(nwdd, tab[k]);
            k++;
            len++;
        }
        if(len > wlen){
            wlen = len;
            wpier = pier;
            wnwdd = nwdd;
        }
    }

    cout << wpier << " " << wlen << " " << wnwdd;

    return 0;
}

