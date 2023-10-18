#include <iostream>
#include <map>
#include <climits>

using namespace std;

struct grzyb{
    int ilosc = 0;
    int p = INT_MAX;
    int q = 0;
};

int main(){

    map <int, grzyb> grzyby;

    int ilosc;
    cin >> ilosc;

    for(int i = 1; i <= ilosc; i++){
        int a;
        cin >> a;
        if(a > 0){
            grzyby[a].ilosc++;
            grzyby[a].p = min(grzyby[a].p, i);
            grzyby[a].q = max(grzyby[a].q, i);
        }
    }

    int rodzaj;
    grzyb gr;

    for(auto a : grzyby){
        if(a.second.ilosc >= gr.ilosc){
            gr = a.second;
            rodzaj = a.first;
        }
    }

    cout << rodzaj << " " <<  gr.p << " " << gr.q;

    return 0;
}