#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
 
using namespace std;
 
const int MX = 21;
const int MOD = 1e9+7;

vector<int> adj[MX];
vector<int> radj[MX];
 
long long int res[1<<MX][MX];
 
bool cmp(int left, int right){
    bitset<MX> l(left);
    bitset<MX> r(right);
    return l.count() < r.count();
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
 
    vector<int> nums;
    int tmp = 1;
    while(tmp != 1<<n){
        nums.push_back(tmp++);
    }

    sort(nums.begin(), nums.end(), cmp);

    for(int curr : nums){
        bitset<MX> curr_bit(curr);
        //cout << curr_bit.to_string() << "\t";
        for(int i = 0; i < MX; i++){ 
            if(curr_bit[i] == 1){
                bitset<MX> tmp_bit = curr_bit;
                tmp_bit[i] = false;
                if(tmp_bit.to_ulong() == 0){
                    res[curr_bit.to_ulong()][i+1] = 1;
                }
                for(int x : radj[i+1]){
                    res[curr_bit.to_ulong()][i+1] = (res[curr_bit.to_ulong()][i+1] + res[tmp_bit.to_ulong()][x])%MOD;
                    //res[curr_bit.to_ulong()][i+1] %= MOD;
                }
            }
        }
    }

    // for(auto a : nums){
    //     bitset<MX> curr_bit(a);
    //     cout << curr_bit.to_string() << "\t";
    //     for(int k = 0; k <= n; k++){
    //         cout << res[a][k] << "\t";
    //     }
    //     cout << endl;
    // }
 
    cout << res[(1<<n)-1][n];
 
    return 0;
}