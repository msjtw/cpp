#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int p;
    cin >> p;
    while(p--){
        int wierz, kraw;
        cin >> wierz >> kraw;
        vector <int> graf[wierz+7];
        int ka, kb;
        for(int i = 0; i < kraw; i++){
            cin >> ka >> kb;
            graf[ka].push_back(kb);
            graf[kb].push_back(ka);
        }
        int odw[507] {};
        bool popsuted = false;
        for(int i = 1; i <= wierz && !popsuted; i++){
            if(odw[i] == 0){
                odw[i] = 1;
                queue <int> kol;
                kol.push(i);
                while(kol.size() > 0){
                    int t = kol.front();
                    kol.pop();
                    for(int k = 0; k < graf[t].size() && !popsuted; k++){
                        if(odw[graf[t][k]] == 0){
                            odw[graf[t][k]] = odw[t]*-1;
                            kol.push(graf[t][k]);
                        }
                        else if(odw[graf[t][k]] == odw[t]){
                            popsuted = true;
                        }
                    }
                }
            }
        }
        cout << (popsuted ? "NIE\n" : "TAK\n");
    }
    return 0;
}