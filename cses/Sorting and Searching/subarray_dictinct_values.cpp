#include<iostream>
#include<map>
#include<vector>

using namespace std;

vector<int> arr;
map<int, int> vals;

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    long long int res = 0;

    for(int p = 0, q = 0; q < n; q++){
        vals[arr[q]]++;
        while(vals.size() > k){
            vals[arr[p]]--;
            if(vals[arr[p]] == 0)
                vals.erase(arr[p]);
            p++;
        }
        // for(int i = p; i <= q; i++){
        //     cout << arr[i] << " ";
        // }
        // cout << "    " << q-p+1 << endl;
        res += q-p+1;
    }

    cout << res;

    return 0;
}