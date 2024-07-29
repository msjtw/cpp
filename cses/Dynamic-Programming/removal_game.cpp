#include<iostream>
#include<vector>

using namespace std;

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}   

typedef long long int ll;
const ll SIZE = 1e15+7;

pair<ll,ll> player1(ll, ll);
pair<ll,ll> player2(ll, ll);

vector<ll> arr;

pair<ll,ll> memo1[5007][5007];
pair<ll,ll> memo2[5007][5007];
bool set1[5007][5007];
bool set2[5007][5007];

pair<ll,ll> player1(ll p, ll q){
    if(set1[p][q])
        return memo1[p][q];

    pair<ll,ll> ret;
    if(p == q)
        ret = {arr[p], 0};
    else{
        auto score1 = player2(p+1,q) + make_pair(arr[p],0LL);
        auto score2 = player2(p,q-1) + make_pair(arr[q],0LL);
        if(score1.first > score2.first)
            ret = score1;
        else
            ret = score2;
    }
    set1[p][q] = true;
    memo1[p][q] = ret;
    return ret;
}

pair<ll,ll> player2(ll p, ll q){
    if(set2[p][q])
        return memo2[p][q];

    pair<ll,ll> ret;
    if(p == q)
        ret = {0, arr[p]};
    else{
        auto score1 = player1(p+1,q) + make_pair(0LL, arr[p]);
        auto score2 = player1(p,q-1) + make_pair(0LL, arr[q]);
        if(score1.second > score2.second)
            ret = score1;
        else
            ret = score2;
    }\
    set2[p][q] = true;
    memo2[p][q] = ret;
    return ret;
}

int main(){
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        arr.push_back(a);
    }

    cout << player1(0,n-1).first;
    return 0;
}