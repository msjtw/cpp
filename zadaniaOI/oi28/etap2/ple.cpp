#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef long long int ll;

const int MX = 5007;
ll arr[MX][MX] {};
const ll INF = MX*1e9;

vector<int> things;

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        things.push_back(a);
    }

    for(int i = 1; i <= n; i++){
        arr[i][n] = INF;
    }

    for(int i = 1; i <= n; i++){
        for(int k = n-1; k >= 0; k--){
            if(arr[i][k+1] >= things[k]){
                arr[i][k] = things[k] + arr[i-1][k+1];
            }
            else{
                arr[i][k] = arr[i][k+1];
            }
        }
        cout << arr[i][0] << " ";
    }

    return 0;
}
