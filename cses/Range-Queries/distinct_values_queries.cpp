#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef tuple<int, int, int, int> tiiii;

const int MX = 2e5+7;

vector<tiiii> queries;
set<int> svals;
vector<int> vals;
int arr[MX];
int res[MX];
int n, q;
int k;

int nums[MX];
int ncount = 0;

bool cmp1(tiiii l, tiiii r){
    int a1 = get<2>(l);
    int a2 = get<2>(r);
    int b1 = get<1>(l);
    int b2 = get<1>(r);
    if(a1 == a2)
        return b1 < b2;
    return a1 < a2;
}

// int val_map(int a){
//     int k = 0;
//     for(int b = vals.size()/2; b > 0; b/=2){
//         while(k+b < vals.size() and vals[k+b] <= a)
//             k += b;
//     }
//     return k;
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    k = 555;
    int next_val = 0;
    map<int, int> val_map;
    for(int i =1 ;i <= n; i++){
        cin >> arr[i];
        if(val_map.find(arr[i]) == val_map.end()){
            val_map[arr[i]] = next_val;
            next_val++;
        }
        arr[i] = val_map[arr[i]];
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        queries.push_back({a,b,a/k,i});
    }

    sort(queries.begin(), queries.end(), cmp1);

    // for(int  : svals){
    //     vals.push_back(a);
    // }
    // for(int i = 1; i <= n; i++){
    //     // cout << arr[i] << " ";
    //     arr[i] = val_map(arr[i]);
    //     // cout << arr[i] << endl;
    // }

    int l = get<0>(queries[0]);
    int r = get<0>(queries[0]);
    ncount = 1;
    nums[arr[r]]++;
    for(auto query : queries){
        int a, b, y, x;
        tie(a, b, y, x) = query;
        while(l < a){
            nums[arr[l]]--;
            if(nums[arr[l]] == 0)
                ncount--;
            l++;
        }
        while(a < l){
            l--;
            if(nums[arr[l]] == 0)
               ncount++;
            nums[arr[l]]++;
        }
        while(r < b){
            r++;
            if(nums[arr[r]] == 0)
                ncount++;
            nums[arr[r]]++;
        }
        while(b < r){
            nums[arr[r]]--;
            if(nums[arr[r]] == 0)
                ncount--;
            r--;
        }
        res[x] = ncount;
        // cout << a << " " << b << " " << x <<  ": ";
        // cout << l << " " << r << endl;
        // for(int i = 0 ; i <= n; i++){
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
    }

    for(int i = 0; i < q; i++)
        cout << res[i] << " ";

    return 0;
}
