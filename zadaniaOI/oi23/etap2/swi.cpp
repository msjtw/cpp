#include <iostream>
#include <vector>

using namespace std;

vector <int> lamp[500007];
bool odw[500007] {};

void bfs(int n){
    odw[n] = true;
    for(int i = 0; i < lamp[n].size(); i++)
        if(!odw[lamp[n][i]])
            bfs(lamp[n][i]);
}

int main(){
    ios_base::sync_with_stdio(0);
    int lampek, wymagan;
    cin >> lampek >> wymagan;

    while(wymagan--){
        int a, b, l;
        cin >> a >> b >> l;
        for(int i = 0; i < l; i++){
            lamp[a+i].push_back(b+i);
            lamp[b+i].push_back(a+i);
        }
    }

    int kol = 0;

    for(int i = 1; i <= lampek; i++){
        if(!odw[i]){
            kol++;
            bfs(i);
        }
    }

    cout << kol;

    return 0;
}