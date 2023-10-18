#include <iostream>

using namespace std;

int main(){
    string nr;
    cin >> nr;
    int suma = 0;
    for(auto a : nr)
        suma += a-'0';

    int p;
    cin >> p;
    while(p-->0){
        int sms, ilosc;
        cin >> sms >> ilosc;
        long long int kontr = suma;
        while(ilosc --> 0){
            int t;
            cin >> t;
            t--;
            kontr = (kontr*(nr[t]-'0'))%1000000007;
        }
        if(kontr == sms)
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }

    return 0;
}