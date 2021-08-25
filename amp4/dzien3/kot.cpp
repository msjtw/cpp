#include <iostream>
#include <vector>

using namespace std;

bool kot[100007];
bool odw[100007];
vector <int> graf[100007];
long long wyn = 0;
int wierz, kotow;

void dfs(int w, int kol){
    odw[w] = true;

    if(kot[w])
        kol++;
    else
        kol = 0;
    
    if(graf[w].size() > 1 && kol <= kotow)
        for(int i = 0; i < graf[w].size(); i++){
            if(!odw[graf[w][i]])
                dfs(graf[w][i] ,kol);
        }
    else{
        if(kol <= kotow && w != 1)
            wyn++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> wierz >> kotow;
    for(int i = 1; i <= wierz; i++)
        cin >> kot[i];

    for(int i = 0; i < wierz-1; i++){
        long long a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }   

    dfs(1, 0);

    cout << wyn; 

    return 0;
}