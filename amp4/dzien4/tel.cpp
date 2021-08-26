#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);

    int tel, len;
    cin >> tel >> len;
    tel--;
    int pocz, kon;
    cin >> pocz >> kon;
    if(pocz != 0){
        cout << "NIE";
        return 0;
    }
    int lok, zas;
    while(tel--){
        cin >> lok >> zas;
        if(lok <= kon)
            kon = max(kon, zas);
        else{
            cout << "NIE";
            return 0;
        }
    }
    cout << (kon >= len ? "TAK" : "NIE");

    return 0;
}