#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int wagi[] = {7,3,1,7,3,1,7,3};

int main(){
    for(int i = 0; i < 200; i++){
        string iden;
        cin >> iden;
        string iden2 = iden;
        int kont = iden[3]-'0';
        iden.erase(iden.begin()+3);
        int suma = 0;
        for(int i = 0; i < 3; i++){
            suma += (iden[i]-55)*wagi[i];
        }
        for(int i = 3; i < iden.size(); i++){
            suma += (iden[i]-'0')*wagi[i];
        }
        if(suma%10 != kont)
            cout << iden2 << endl;
    }

    return 0;
}