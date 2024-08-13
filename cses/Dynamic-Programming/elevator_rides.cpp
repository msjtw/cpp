#include <iostream>

using namespace std;

typedef pair<int,int> pii;

int weight[27] {};
int n, x;

pii res[1<<21];

int main(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> weight[i];
    }
    res[0] = {1,0};
    for(int i = 1; i < 1<<n; i++){
        res[i] = {n+1, 0};
        for(int k = 0; k < n; k++){
            if(!(i&(1<<k)))
                continue;
            pii prev = res[i^(1<<k)];
           // cout << (i^(1<<k)) << "  " << prev.first << " " << prev.second << endl;
            if(prev.second + weight[k+1] <= x){
                prev.second += weight[k+1];
            }
            else{
                prev.first++;
                prev.second = weight[k+1];
            }
            res[i] = min(res[i], prev);
            //cout << "<--" << i << "--" << res[i].first << "   ---   " << prev.first << endl;
        }
    }
   // for(int i = 0 ; i < 1<<n; i++){
   //     cout << res[i].first << endl;
   // }
    cout << res[(1<<n)-1].first;
}
