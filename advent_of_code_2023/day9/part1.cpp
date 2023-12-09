#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int res = 0;

int main(){
    int n;
    while(cin >> n){
        vector<int> arr[n+7];
        for(int i =0 ;i < n; i++){
            int a;
            cin >> a;
            arr[0].push_back(a);
        }
        for(int i = 1; i < n ; i++){
            for(int k = 0 ; k < arr[i-1].size()-1; k++){
                arr[i].push_back(arr[i-1][k+1] - arr[i-1][k]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(arr[i].begin(), arr[i].end());
        }
        arr[n-1].push_back(0);
        for(int i = n-2; i >= 0; i--){
            arr[i].push_back(arr[i][n-i-1] - arr[i+1][n-i-1]);
        }
        res += arr[0][n];
        for(int i = 0; i < n; i++){
            for(int k = 0; k < arr[i].size(); k++){
                cout << arr[i][k] << " ";
            }
            cout << endl;
        }
    }
    cout << res;
}