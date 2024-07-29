#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

vector<int> arr;
stack<pair<int, int>> vals;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        while(!vals.empty() and vals.top().first >= a)
            vals.pop();
        if(vals.empty()){
            cout << 0 << " ";
        }
        else{
            cout << vals.top().second << " ";
        }
        vals.push({a, i+1});
    }
    return 0;
}