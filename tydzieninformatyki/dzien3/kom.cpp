#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

vector <pair<int,int>> graf[107]; 
int czasy[107] {};

int main(){
    int wierz, pol;
    cin >> wierz >> pol;
    for(int i = 0 ; i < pol; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({b,c});
        graf[b].push_back({a,c});
    }

    bool odw[107] {};
    for(int i = 0; i < 107; i++, czasy[i]=__INT_MAX__);

    int p, q;
    cin >> p >> q;

    priority_queue <pair<int,int>> kol;
    kol.push({p, __INT_MAX__});
    while(kol.size() > 0){
        
    }

    return 0;
}