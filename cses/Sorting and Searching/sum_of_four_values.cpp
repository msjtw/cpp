#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;

struct num{
    int val;
    int pos;
};

vector<int> arr;
map<int, pair<num, num>> vals;
 
bool diff(int a, int b, int c, int d){
    if(a == b or a == c or a == d)
        return false;
    if(b == c or b == d)
        return false;
    if(c == d)
        return false;
    return true;
}

int main(){
    int n, x;
    cin >> n >> x;
 
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    vector<pair<num, num>> pairs;
    for(int i = 0 ; i < n; i++){
        for(int k = i+1 ; k < n; k++){
            pairs.push_back({{arr[i], i+1}, {arr[k], k+1}});
            vals[arr[i] + arr[k]] = {{arr[i], i+1}, {arr[k], k+1}};
        }
    }

    for(auto p1 : pairs){
        num n1, n2, n3, n4;
        tie(n1, n2) = p1;
        if(vals.count(x - n1.val - n2.val) == 0)
            continue;
        auto p2 = vals[x - n1.val - n2.val];
        tie(n3, n4) = p2;
        if(diff(n1.pos, n2.pos, n3.pos, n4.pos)){
            if(n1.val + n2.val + n3.val + n4.val == x){
                cout << n1.pos << " " << n2.pos << " " << n3.pos << " " << n4.pos;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}