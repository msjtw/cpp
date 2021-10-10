#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct node{
    int nr;
    bool l = 0, r = 0;
};

vector <int> graf[100007];
vector <int> order;
int h[100007];
int pier[100007];
int drz[1<21];
int base = 1<20;


bool odw[100007];


void insert(int drz_prz[], int id, int val){
    int i = id + base;
    drz_prz[i] = val;
    while(i > 0){
        i >>= 1;
        drz_prz[i] = min(drz_prz[2*i], drz_prz[2*i+1]);
    }
}

int query(int drz_prz[], int p, int q){
    int ret = INT_MAX;
    p = p + base -1;
    q = q + base +1;
    while(p/2 != q/2){
        if(p % 2 == 0)
            ret = min(ret, drz_prz[p+1]);
        if(q % 2 == 1)
            ret = min(ret, drz_prz[q-1]);
        p >>= 1;
        q >>= 1;
    } 
    return ret;
}

void dfs(int id, int height){
    odw[id] = true;
    order.push_back(id);
    insert(drz, order.size()-1, height);
    pier[id] = order.size()-1;
    h[id] = height;
    for(int i = 0 ; i < graf[id].size(); i++){
        if(!odw[graf[id][i]]){
            dfs(graf[id][i], height+1);
            order.push_back(id);
        }
    }
}

int main(){
    int w;
    cin >> w;
    for(int i = 1; i < w; i++){
        int a,b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    dfs(1,1);

    int p;
    cin >> p;
    while(p--){
        int a, b;
        cin >> a >> b;
        if(pier[a] > pier[b])
            swap(a,b);
        int mini = query(drz,pier[a],pier[b]);
        cout << (h[a]-mini)+(h[b]-mini) << endl;
    }
    

    return 0;
}