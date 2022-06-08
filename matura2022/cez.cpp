#include <iostream>

using namespace std;

int main(){
    int p;
    cin >> p;
    while(p --> 0){
        string a, b;
        cin >> a >> b;
        int k = b[0]-a[0];
        if(k < 0)
            k += 26;
        for(int i = 1; i < a.length(); i++){
            int t = b[i]-a[i];
            if(t < 0)
                t += 26;
            if(t != k){
                cout << a << endl;
                break;
            }
        }
    }
    return 0;
}