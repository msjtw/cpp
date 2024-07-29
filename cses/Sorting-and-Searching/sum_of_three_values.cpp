#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
vector<int> arr;
map<int,int> pos;
 
int main(){
    int n, x;
    cin >> n >> x;
 
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
        pos[a] = i;
    }
 
    for(int i = 0; i < n; i++){
        for(int k = i +1; k < n; k++){
            int a = x - arr[i] - arr[k];
            if(pos.count(a) != 0 and pos[a] != i+1 and pos[a] != k+1){
                cout << pos[a] << " " << i+1 << " " << k+1;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}