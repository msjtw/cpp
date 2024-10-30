#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

const int MX = 2e5+7;

vector<int> arr;
bool vis[MX][2];


int solve(int l, int r, int n){
    if(n == 1){
        /* cout << l << endl; */
        return arr[l];
    }
    int pow = 1;
    while(pow<<1 < n){
        pow <<= 1;
    }
    /* cout << "--> " << l << " " << (l+r)/2 << " " << ((l+r)/2)+1 << " " << r << " ; " << n-pow << endl; */
    return solve(l, l+pow-1, n-pow) ^ solve(l+pow, r, n-pow);
}

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    int pow = 1;
    while(pow < n){
        pow <<= 1;
    }
    while(arr.size() < pow){
        arr.push_back(0);
    }

    cout << solve(0, pow-1, n);

    return 0;
}

