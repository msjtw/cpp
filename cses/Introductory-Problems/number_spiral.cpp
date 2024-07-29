#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t --> 0){
        long long int y, x;
        cin >> y >> x;
        long long int big = max(x-1, y-1);
        long long int ins = (2 + (big-1) *2) * big / 2;
        if(big & 1){
            //odd
            if( y <= x ){
                ins += y;
            }
            else{
                ins += y + (y-x);
            }
        }
        else{
            //even
            if( y >= x ){
                ins += x;
            }
            else{
                ins += x + (x-y);
            }

        }
        cout << ins << " ";
    }
    return 0;
}
