#include <iostream>
#include <queue>

using namespace std;

struct banan{
    long long int ilosc, dzien;
};

queue <banan> dostawy;

long long podatek(long long ilosc, long long dni){
    dni = dni*(dni+1)/2;
    return ((ilosc%1000000007)*(dni%1000000007))%1000000007;
}

int main(){
    ios_base::sync_with_stdio(0);

    int dni;
    long long suma = 0;
    cin >> dni;

    for(int i = 0; i < dni; i++){
        long long int prz, wyj;
        cin >> prz >> wyj;
        dostawy.push({prz, i});
        while(wyj > 0){
            banan b = dostawy.front();
            if(b.ilosc >= wyj){
                suma += podatek(wyj, i-b.dzien);
                dostawy.front().ilosc -= wyj;
                wyj = 0;
            }
            else{
                suma += podatek(b.ilosc, i-b.dzien);
                wyj -= b.ilosc;
                dostawy.pop();
            }
        }
        suma %= 1000000007;
    }

    cout << suma;

    return 0;
}