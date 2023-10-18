#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int p;
    cin >> p;
    while(p --> 0){
        vector<int> v;
        int n;
        cin >> n;
        while(n --> 0){
            int a;
            cin >> a;
            v.push_back(a);
        }
        for(int i = v.size()-1; i >= 0; i--){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}