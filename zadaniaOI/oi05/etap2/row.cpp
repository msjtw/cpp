#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> graf[10007];
int odw[10007] {};

void dfs(int i){
    odw[i] = true;
    for(int k = 0; k < graf[i].size(); k++)
        if(!odw[graf[i][k]])
            dfs(graf[i][k]);
}

void wyp(int pot){
    vector <int> l;
    l.push_back(1);
    for(int i = 0; i < pot; i++){
        for(int k = 0; k < l.size(); k++){
            l[k] *= 2;
        }
        for(int k = 0; k < l.size()-1; k++){
            if(l[k] > 9){
                l[k] -= 10;
                l[k+1] += 1;
            }
        }
        if(l[l.size()-1] > 9){
            l[l.size()-1] -= 10;
            l.push_back(1);
        }
    }
    for(int i = l.size()-1; i >= 0; i--){
        cout << l[i];
    }
    cout << endl;
}

int main(){
    int licznik = 0;
    ios_base::sync_with_stdio(0);
    int rownan;
    cin >> rownan;
    while(rownan--){
        licznik++; 
        for(int i = 0; i < 10007; i++){
            odw[i] = false;
            graf[i].clear();
        }
        int zmiennych;
        cin >> zmiennych;
        int len[100] {};
        int pocz[100] {};

        for(int i = 0; i < zmiennych; i++){
            cin >> len[i];
        }
        pocz[0] = 2;
        for(int i = 0; i < zmiennych; i++){
            pocz[i+1] = pocz[i] + len[i];
        }

        int ll, lp;
        string sl, sp;
        vector <int> l;
        vector <int> p;
        cin >> ll >> sl;
        cin >> lp >> sp;

        if(zmiennych == 0){
            cout << 1 << endl;
            continue;
        }

        for(char a : sl){
            if(a == '0' || a == '1')
                l.push_back(a-'0');
            else
                for(int i = 0; i < len[a-'a']; i++)
                    l.push_back(pocz[a-'a']+i);
        }
        for(char a : sp){
            if(a == '0' || a == '1')
                p.push_back(a-'0');
            else
                for(int i = 0; i < len[a-'a']; i++)
                    p.push_back(pocz[a-'a']+i);
        }
                 
        if(p.size() != l.size()){
            cout << 0 << endl;
            continue;
        }

        int nr = pocz[zmiennych-1] + len[zmiennych-1];
        long long int wyn = 0;
        for(int i = 0; i < l.size(); i++){
            graf[l[i]].push_back(p[i]);
            graf[p[i]].push_back(l[i]);
        }
            
        dfs(0);
        
        if(odw[1]){
            cout << 0 << endl;
            continue;
        }
        dfs(1);
        for(int i = 2; i < nr; i++){
            if(!odw[i]){
                wyn ++;
                dfs(i);
            }
        }
        
        wyp(wyn);
    }

    return 0;
}