#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int miast, lini, pocz;
int pociag, samolot;

vector <int> kolej[100007];
vector <int> loty[100007];

int main(){
    ios_base::sync_with_stdio(0);


    cin >> miast >> lini;
    cin >> pocz;
    cin >> pociag >> samolot;

    for(int i = 0; i < lini; i++){
        int a, b;
        cin >> a >> b;
        kolej[a].push_back(b);
        kolej[b].push_back(a);
    }

    for(int i = 0; i < miast; i++){
        set <int> jest;
        jest.insert(i);
        for(int k = 0 ; k < (int)kolej[i].size(); k++)
            jest.insert(kolej[i][k]);

        for(int miasto : jest){
            for(int k = 0; k < (int)kolej[miasto].size(); k++){
                if(jest.find(kolej[miasto][k]) == jest.end()){
                    loty[i].push_back(kolej[miasto][k]);
                    loty[kolej[miasto][k]].push_back(i);
                    jest.insert(kolej[miasto][k]);
                }
            }
        }
    }

    for(int i = 0; i <= miast; i++){
        cout << i << ": ";
        for(int k : loty[i])
            cout << k << ", ";
        cout << endl;
    }


    return 0;
}