#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

struct rule{
    ll start;
    ll dest;
    ll range;
};

vector<pair<ll,ll>> seeds;

vector<rule> rules[10];

ll convert(ll a, ll b, ll rule){
    if(rule == 7)
        return a;
    ll ret = __INT_MAX__;
    ll i = 0;
    while(a < b){
        if(i == rules[rule].size()){
            ret = min(ret, convert(a,b, rule+1));
            a = b;
        }
        if(a < rules[rule][i].start){
            ret = min(ret, convert(a, min(b, rules[rule][i].start + rules[rule][i].range), rule+1));
            a = min(b, rules[rule][i].start + rules[rule][i].range);
        }
        else if(a < rules[rule][i].start + rules[rule][i].range){
            ll diff = rules[rule][i].dest - rules[rule][i].start;
            ret = min(ret, convert(a + diff, min(b, rules[rule][i].start + rules[rule][i].range) + diff, rule+1));
            a = min(b, rules[rule][i].start + rules[rule][i].range);
        }
        i++;
    }
    return ret;
}

bool cmp(rule l, rule r){
    return l.start < r.start;
}

int main(){
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        seeds.push_back({a,b});
    }

    for(ll i = 0; i < 7; i++){
        while(true){
            ll a, b, c;
            cin >> a;
            if(a == -1){
                break;
            }
            cin >> b >> c;
            rules[i].push_back({b, a, c});
        }
        sort(rules[i].begin(), rules[i].end(), cmp);
    }

    ll res = __INT_MAX__;

    for(ll i = 0; i < n; i++){
        res = min(res, convert(seeds[i].first, seeds[i].first+seeds[i].second, 0));
    }

    cout << res;

    return 0;
}