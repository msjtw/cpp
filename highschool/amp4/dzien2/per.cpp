// Stanislaw Fiedler VIII LO Poznan

#include <iostream>

using namespace std;

int liczby[1000007];

int main(){
    ios_base::sync_with_stdio(0);

    int liczb;
    int wyn = 0;
    cin >> liczb;
    for(int i =0; i < liczb; i++){
        int a;
        cin >> a;
        liczby[a] = i;
    }
    int mini = liczby[1], maxi = liczby[1];
    for(int i = 1; i <= liczb; i++){
        maxi = max(maxi, liczby[i]);
        mini = min(mini, liczby[i]);
        if(maxi - mini + 1 == i)
            wyn++;
    }

    cout << wyn;

    return 0;
}
