#include <iostream>
#include <string>

using namespace std;

string a, b;

int maxpow(int k, int i){
    int len = 0;
    while(k+len < i && i+len < a.size()){
        if(a[k+len] ==a[i+len])
            len++;
        else
            break;
    }
    return len;
}

int main(){
    cin >> a;

    for(int i = 0; i < a.size(); i++){
        bool skomp = false;
        for(int k = i-1; k >= 0; k--){
            int len = maxpow(k, i);
            if(len >= 3){
                cout << "#" << char(i-k) << char(len);
                i += len-1;
                skomp = true;
                break;
            }
        }
        if(!skomp)
            cout << a[i];
    }

    cout << b;

    return 0;
}