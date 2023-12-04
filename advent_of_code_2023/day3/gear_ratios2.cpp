#include<iostream>
#include<cstdio>
#include<set>
#include<vector>

using namespace std;

long long res = 0;
int arr[150][150];

int main(){
    int n = 142;

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            arr[i][k] = getchar();
            if(arr[i][k] == '*')
                arr[i][k] = -1;
            else if(!isdigit(arr[i][k]))
                arr[i][k] = -2;
        }
        getchar();
    }
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            cout << arr[i][k] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 1; i < n-1; i++){
        for(int k = 1; k < n-1; k++){
            if(isdigit(arr[i][k])){
                int j = k;
                int val = 0;
                for(; j < n and isdigit(arr[i][j]); j++){
                    val *= 10;
                    val += (arr[i][j] - '0');
                }
                for(;k < j; k++){
                    arr[i][k] = val;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            cout << arr[i][k] << " ";
        }
        cout << endl;
    }

    for(int i = 1; i < n-1; i++){
        for(int k = 1; k < n-1; k++){
            if(arr[i][k] == -1){
                set<int> adj;
                if(arr[i-1][k] > 0){
                    adj.insert(arr[i-1][k]);
                }
                if(arr[i-1][k+1] > 0){
                    adj.insert(arr[i-1][k+1]);
                }
                if(arr[i][k+1] > 0){
                    adj.insert(arr[i][k+1]);
                }
                if(arr[i+1][k+1] > 0){
                    adj.insert(arr[i+1][k+1]);
                }
                if(arr[i+1][k] > 0){
                    adj.insert(arr[i+1][k]);
                }
                if(arr[i+1][k-1] > 0){
                    adj.insert(arr[i+1][k-1]);
                }
                if(arr[i][k-1] > 0){
                    adj.insert(arr[i][k-1]);
                }
                if(arr[i-1][k-1] > 0){
                    adj.insert(arr[i-1][k-1]);
                }

                
                int sum = 1;
                for(auto a : adj)
                    cout << a << " ";
                cout << endl;


                if(adj.size() == 2){
                    // for(auto a : adj)
                    //     sum *= a;
                    if(arr[i-1][k] > 0)
                        sum *= arr[i-1][k];
                    if(arr[i-1][k+1] > 0)
                        sum *= arr[i-1][k+1];
                    if(arr[i][k+1] > 0)
                        sum *= arr[i][k+1];
                    if(arr[i+1][k+1] > 0)
                        sum *= arr[i+1][k+1];
                    if(arr[i+1][k] > 0)
                        sum *= arr[i+1][k];
                    if(arr[i+1][k-1] > 0)
                        sum *= arr[i+1][k-1];
                    if(arr[i][k-1] > 0)
                        sum *= arr[i][k-1];
                    if(arr[i-1][k-1] > 0)
                        sum *= arr[i-1][k-1];
                    res += sum;
                }
            }
        }
    }

    cout << res;

    return 0;
}