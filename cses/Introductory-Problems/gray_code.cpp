#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> all;
    for(int i=0; i < 1<<(n); i++){
        bitset<16> num(i);
        all.push_back(num.to_string().substr(16-n, n));
    }
    sort(all.begin(), all.end());
    for(auto a : all){
        cout << a << endl;
    }
    return 0;
}
