#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int V, E;
    cin >> V >> E;
    vector <int> graf[V+7];
    for(int i = 0; i < E; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int zap;
    cin >> zap;
    while(zap--){
        int p, q;
        cin >> p >> q;
        int odw[1007] {};
        odw[p] = 1;
        queue <int> kol;
        kol.push(p); 
        while(kol.size() > 0){
            int t = kol.front();
            if(t == q){
                cout << odw[t]-1 << endl;
                break;
            }
            kol.pop();
            for(int i = 0; i < graf[t].size(); i++){
                if(odw[graf[t][i]] == 0){
                    kol.push(graf[t][i]);
                    odw[graf[t][i]] = odw[t]+1;
                }
            }
        }
    }

    return 0;
}