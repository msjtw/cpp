#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n,sum=0; cin>>n;
    vector<int>tab(n),stab,p,np;
    for(int i = 0;i<n;++i){
        cin>>tab[i];
    }
    stab=tab;
    sort(stab.begin(),stab.end());
    for(int i = 0;i<n;++i){
        if(i%2==0)p.push_back(stab[i]);
        else np.push_back(stab[i]);
    }
    for(int i = 0;i<n;++i){
        if(i%2==0){
            if(binary_search(np.begin(),np.end(),tab[i]))++sum;
        }
        else{
            if(binary_search(p.begin(),p.end(),tab[i]))++sum;
        }
    }
    if(sum%2==1)++sum;
    cout<<sum/2;
  
}