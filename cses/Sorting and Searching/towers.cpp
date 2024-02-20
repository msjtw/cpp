#include <iostream>
#include <set>

using namespace std;

multiset<int> towers;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        auto pt = towers.upper_bound(a);
        if(pt == towers.end()){
            towers.insert(a);
        }
        else{
            towers.erase(pt);
            towers.insert(a);
        }
    }

    cout << towers.size();

    return 0;
}