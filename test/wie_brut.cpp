#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);

    int n,q,a,b,k;
    cin>>n>>q;

    vector<int>tab(n);

    for(int i = 0;i<n;++i){
        cin>>tab[i];
    }

    for(int qq = 0;qq<q;++qq){
        cin>>a>>b>>k;
        --a; --b;
        int ile=0;
        for(int i = a;i<=b;++i){
            if(tab[i]<=k){
                ++ile;
            }
        }
        cout<<ile<<'\n';
    }
}