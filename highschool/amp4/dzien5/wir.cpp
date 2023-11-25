#include <iostream>
#include <vector>
#include <queue>

using namespace std;

    vector <int> graf[100000];
    bool odw[1000000] {};

int main(){
    ios_base::sync_with_stdio(0);


    int osob, znja;
    cin >> osob >> znja;

    for(int i = 0; i < znja; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    queue <int> Q;
    Q.push(1);
    odw[1] = true;
    int ilosc  = 1;

    while(Q.size() > 0){
        int p = Q.front();
        Q.pop();
        for(int i =0; i < graf[p].size(); i++){
            if(!odw[graf[p][i]]){
                Q.push(graf[p][i]);
                odw[graf[p][i]] = true;
                ilosc++;
            }
        }
    } 

    cout << ilosc;

    return 0;
}