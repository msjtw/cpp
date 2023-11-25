#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct plant{
    int x, y, age;
};

int plansza[507][507];

bool por(plant l, plant r){
    return l.age < r.age;
}

int roz(plant roslina){
    bool odw[507][507] {};
    odw[roslina.x][roslina.y] = true;
    int pol = 0;
    queue <plant> kol;
    kol.push(roslina);
    while(kol.size() > 0){
        plant t = kol.front();
        pol++;
        kol.pop();
        if(plansza[t.x+1][t.y] <= t.age && !odw[t.x+1][t.y]){
            odw[t.x+1][t.y] = true;
            kol.push({t.x+1,t.y,t.age});
        }
        if(plansza[t.x-1][t.y] <= t.age && !odw[t.x-1][t.y]){
            odw[t.x-1][t.y] = true;
            kol.push({t.x-1,t.y,t.age});
        }
        if(plansza[t.x][t.y+1] <= t.age && !odw[t.x][t.y+1]){
            odw[t.x][t.y+1] = true;
            kol.push({t.x,t.y+1,t.age});
        }
        if(plansza[t.x][t.y-1] <= t.age && !odw[t.x][t.y-1]){
            odw[t.x][t.y-1] = true;
            kol.push({t.x,t.y-1,t.age});
        }
    }
    return pol;
}

int main(){
    int bok, jezioro;
    cin >> bok >> jezioro;

    vector <plant> rosliniki;
    for(int i = 0; i < 507; i++){
        plansza[0][i] = 1000007;
        plansza[bok+1][i] = 1000007;
        plansza[i][0] = 1000007;
        plansza[i][bok+1] = 1000007;
        
    }

    for(int i = 1; i <= bok; i++){
        for(int k = 1; k <= bok; k++){
            cin >> plansza[i][k];
            rosliniki.push_back({i,k,plansza[i][k]});
        }
    }

    sort(rosliniki.begin(), rosliniki.end(), por);

    for(plant ros : rosliniki){
        // int r = roz(ros);
        // cout << ros.age << " " << r << " " << ros.x << " " << ros.y << endl;
        if(roz(ros) >= jezioro){
            cout << ros.age;
            break;
        }
    }

    return 0;
}