#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);

    long long int ha = 0, hb = 0;
    int ia, ib;
    int klocki_a[100007] {}, klocki_b[100007] {};
    cin >> ia >> ib;
    for(int i = 0; i < ia; i++){
        cin >> klocki_a[i];
        ha += klocki_a[i];
    }
    for(int i = 0; i < ib; i++){
        cin >> klocki_b[i];
        hb += klocki_b[i];
    }
    ia--;
    ib--;
    int wyn = 0;
    while(ha != hb){
        wyn++;
        if(ha > hb && ia >= 0)
            ha -= klocki_a[ia--];
        else if(ib >= 0)
            hb -= klocki_b[ib--];
    }

    cout << wyn;

    return 0;
}