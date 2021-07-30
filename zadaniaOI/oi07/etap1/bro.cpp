#include <iostream>

using namespace std;

struct mia{
    int nast, piwo;
};

mia miasta[10007] {};
int r_id[10007] {};
int l_id[10007] {};
int r_dys[10007] {};
int l_dys[10007] {};
int l_cena[10007] {};
int l_cena[10007] {};

int wyn[10007] {};

int main(){
    ios_base::sync_with_stdio(0);

    int miast;
    cin >> miast;

    for(int i = 0; i < miast; i++){
        cin >> miasta[i].piwo >> miasta[i].nast;
    }

    for(int i = 0; i < miast; i++){
        r_id[i];
        while(abs(r_id[i]%miast - l_id[i]%miast) != 1){

        }
    }


    return 0;
}