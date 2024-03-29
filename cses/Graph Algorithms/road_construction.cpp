#include <iostream>

using namespace std;

const int MX = 1e5+7;

int s_size[MX];
int link[MX];

int max_size = 0;
int num;

int find(int x){
    while(x != link[x])
        x = link[x];
    return x;
}

bool same(int a, int b){
    return find(a) == find(b);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(s_size[a] < s_size[b])
        swap(a, b);
    s_size[a] += s_size[b];
    max_size = max(max_size, s_size[a]);
    link[b] = a;
    num--;
}

int main(){
    for(int i = 0; i < MX; i++){
        s_size[i] = 1;
        link[i] = i;
    }

    int n, m;
    cin >> n >> m;
    num = n;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(!same(a, b))
            unite(a, b);
        cout << num << " " << max_size << endl;
    }
    return 0;
}