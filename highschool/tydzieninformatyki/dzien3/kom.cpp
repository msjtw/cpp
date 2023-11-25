#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int INF = 1000000009;

int main(){
    int wierz, pol;
    vector <pair<int,int>> graf[107]; 
    cin >> wierz >> pol;
    for(int i = 0 ; i < pol; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({b,c});
        graf[b].push_back({a,c});
    }
    int p, q;
    cin >> p >> q;

    int odl[107];

    for(int i = 0; i < 107; i++)
        odl[i] = INF;
    
    priority_queue <pair<int,int>> kol;
    kol.push({INF, p});
    odl[p] = 0;
    while(!kol.empty()){
        auto t = kol.top();
        kol.pop();
        for(int i = 0; i < graf[t.second].size(); i++){
            if(odl[graf[t.second][i].first] > odl[t.second]+graf[t.second][i].second){
                odl[graf[t.second][i].first] = odl[t.second]+graf[t.second][i].second;
                kol.push({INF-odl[odl[graf[t.second][i].first]], graf[t.second][i].first});
            }
        }
    }

    if(odl[q] <= 5)
        cout << 51;
    else if(odl[q] <= 10)
        cout << 10;
    else if(odl[q] <= 20)
        cout << 20;
    else if(odl[q] <= 40)
        cout << 40;
    else 
        cout << "IDZ  PIECHOTA.  NIE  MASZ PIENIEDZY";

    return 0;
}