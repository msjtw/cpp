#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> arr;
set <int> res;

bool memo[107][100007] {};

void sums(int n, int s){
    if(memo[n][s] == true)
        return;
    if(n == arr.size())
        res.insert(s);
    else{
        sums(n+1, s);
        memo[n+1][s] = true;
        sums(n+1, s + arr[n]);
        memo[n+1][s + arr[n]] = true;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    sums(0,0);

    res.erase(res.begin());
    cout << res.size() << endl;
    for(auto a : res)
        cout << a << " ";

    return 0;
}