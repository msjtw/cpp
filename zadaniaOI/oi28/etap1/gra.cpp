// Stanislaw Fiedler VIII LO Poznan

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct col{
    int col;
    int poz;
};

bool por(col left, col right){
    return left.col > right.col;
}

vector <col> dziury;
vector <int> poziomy;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int poziomow, dlugosc, p;
    cin >> poziomow >> dlugosc >> p;
    poziomy.resize(poziomow+5);
    for(int i = 1; i <= poziomow; i++){
        int a, b;
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> b;
            col c;
            c.col = b;
            c.poz = i;
            dziury.push_back(c);
        }
    }

    sort(dziury.begin(), dziury.end(), por);

    for(int i = 0; i < dziury.size(); ++i){
        if(poziomy[dziury[i].poz+1] > poziomy[dziury[i].poz]+1 || dziury[i].poz == poziomow){
            poziomy[dziury[i].poz]++;
        }    
        else{ 
            poziomy[dziury[i].poz] = poziomy[dziury[i].poz+1];
        }
        if(poziomy[dziury[i].poz+1] > poziomy[dziury[i].poz] && dziury[i].poz != poziomow){
            poziomy[dziury[i].poz+1] = poziomy[dziury[i].poz];
        }
    }


    while(p--){
        int a;
        cin >> a;
        cout << poziomy[a] << '\n';
    }

    return 0;
}