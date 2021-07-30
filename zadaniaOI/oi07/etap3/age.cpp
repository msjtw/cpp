#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main(){
    int miast, drog;
    cin >> miast >> drog;
    int ag_a, ag_b;
    cin >> ag_a >> ag_b;

    vector <int> siec[257]; 

    for(int i = 0; i < drog; i++){
        int a, b;
        cin >> a >> b;
        siec[a].push_back(b);
    }

    queue <int> mia_a;
    mia_a.push(ag_a);
    mia_a.push(0);
    queue <int> mia_b;
    mia_b.push(ag_b);
    mia_b.push(0);
    bool odw[257] {};

    int tura = 0;
    while(tura++){
        while(mia_a.front() != 0){
            int p = mia_a.front();
            mia_a.pop();
            odw[p] = false;
            for(int i = 0; i < siec[p].size(); i++)
                if(!odw[siec[p][i]]){
                    odw[siec[p][i]] = true;
                    mia_a.push(siec[p][i]);
                }
        }
        mia_a.pop();
        mia_a.push(0);

        while(mia_b.front() != 0){
            int p = mia_b.front();
            mia_b.pop();
            for(int i = 0; i < siec[p].size(); i++)
                if(odw[siec[p][i]]){
                    cout << tura;
                    return 0;
                }
                else{
                    mia_b.push(siec[p][i]);
                }
        }
        mia_b.pop();
        mia_b.push(0);
    }

    return 0;
}