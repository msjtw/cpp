#include<iostream>
#include<vector>
#include<tuple>
#include<set>

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef tuple<char,int,int> tcii;

const int BASE = 1<<20;


vector<int> compr;
set<int> sc;
vector<int> salaries; 
vector<tcii> queries;

int emp[BASE];
int sal[2*BASE];

void add(int p, int val){
    p += BASE;
    sal[p] += val;
    while(p > 0){
        p >>= 1;
        sal[p] = sal[2*p] + sal[2*p+1];
    }
}

int query(int p, int q){
    int ret =0 ;
    p += BASE -1;
    q += BASE +1;
    while(p>>1 != q>>1){
        if(not(p&1)){
            ret += sal[p+1];
        }
        if(q&1){
            ret += sal[q-1];
        }
        p >>= 1;
        q >>= 1;
    }
    return ret;
}

int idx_map(int a){
    int k = 0;
    for(int b = compr.size()/2; b > 0; b/=2){
        while(k+b < compr.size() and compr[k+b] <= a)
            k += b;
    }
    if(compr[k] == a)
        return k;
    else{
        return -1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for(int i = 1 ; i <= n; i++){
        int a;
        cin >> a;
        salaries.push_back(a);
        sc.insert(a);
    }
    for(int i = 0 ; i < q; i++){
        char op;
        int a, b;
        cin >> op >> a >> b;
        queries.push_back({op,a,b});
        sc.insert(a);
        sc.insert(b);
    }

    auto it = sc.begin();
    while(it != sc.end()){
        compr.push_back(*it);
        it++;
    }

    for(int i = 1; i <= n; i++){
        int a;
        a = salaries[i-1];
        emp[i] = a;
        a = idx_map(a);
        add(a, 1);
    }

    for(tcii quer : queries){
        char op;
        int a, b;
        tie(op, a, b) = quer;
        if(op == '!'){
            add(idx_map(emp[a]), -1);
            emp[a] = b;
            add(idx_map(emp[a]), 1); 
        }
        else{
            a = idx_map(a);
            b = idx_map(b);
            cout << query(a, b) << "\n";
        }
    }

    return 0;
}
