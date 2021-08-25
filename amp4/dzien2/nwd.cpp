#include <iostream>
#include <algorithm> 
#include <vector> 

using namespace std;

struct liczba{
    bool jest = false;
    bool ok = false;
    int id; 
};

liczba liczby[1000007] {};

bool por(liczba a, liczba b){
    return a.id < b.id;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int naj = 0;
    int liczb;
    cin >> liczb;
    for(int i = 0; i < liczb; i++){
        int a;
        cin >> a;
        naj = max(naj, a);
        liczby[a].jest = true;
        liczby[a].id = i;
    }

    for(int i = 2; i <= naj; i++){
        vector <int> ok;
        for(int k = i; k <= naj; k+=i){
            if(liczby[k].jest)
                ok.push_back(k);
        }
        if(ok.size() >= 3)
            for(int i = 0; i < ok.size(); i++)
                liczby[ok[i]].ok = true;
    }

    sort(liczby, liczby+liczb+1, por);

    for(int i = 0; i <= naj; i++)
        if(liczby[i].jest)
            cout << liczby[i].ok << ' ';

    return 0;

}