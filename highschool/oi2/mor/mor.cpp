#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct rejs{
    int cel;
    int odl;
    int id;
};

vector <int> szlaki[10010];
vector <rejs> rejsy[5010];
int odl[10010];
bool odp[1000010];

int portow, szlakow, op;

void bfs(int a){
    for(int i = 0; i <= portow*2 + 2; i++)
        odl[i] = INT_MAX;

    queue <int> kol;
    odl[a] = 0;
    kol.push(a);
    while(kol.size() > 0){
        int n = kol.front();
        kol.pop();
        for(int i = 0; i < szlaki[n].size(); i++){
            if(odl[szlaki[n][i]] == INT_MAX){
                odl[szlaki[n][i]] = odl[n]+1;
                kol.push(szlaki[n][i]);
            }    
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> portow >> szlakow >> op;

    for(int i = 0; i < szlakow; i++){
        int a, b;
        cin >> a >> b;
        szlaki[a].push_back(b+portow);
        szlaki[a+portow].push_back(b);
        szlaki[b].push_back(a+portow);
        szlaki[b+portow].push_back(a);
    }
    for(int i = 0; i < op; i++){
        int a, b, c;
        cin >> a >> b >> c;
        rejsy[a].push_back({b, c, i});

    }

    for(int i = 1; i <= portow; i++){
        if(rejsy[i].size() > 0 && szlaki[i].size() > 0){
            bfs(i);
            for(int k = 0; k < rejsy[i].size(); k++){
                if(rejsy[i][k].odl & 1){
                    if(rejsy[i][k].odl >= odl[rejsy[i][k].cel+portow])
                        odp[rejsy[i][k].id] = true;
                }
                else{
                    if(rejsy[i][k].odl >= odl[rejsy[i][k].cel])
                        odp[rejsy[i][k].id] = true;
                }
            }
        }
    }
    for(int i = 0; i < op; i++){
        if(odp[i]) 
            cout << "TAK" << endl;
        else 
            cout << "NIE" << endl;
    }

    // for(int i = 1; i < portow; i++){
    //     //if(rejsy[i].size() > 0){
    //         bfs(i);
    //         cout << i << " ";
    //         for(int k = 1; k <= portow*2; k++)
    //             cout << odl[k] << " ";
    //         cout << endl;
    //     //}
    // }

    return 0;
}