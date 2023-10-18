#include<iostream>
#include<set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    set<int> s;
    while(n --> 0){
        int a;
        cin >> a;
        s.insert(a);
    }
    cout << s.size();
}
