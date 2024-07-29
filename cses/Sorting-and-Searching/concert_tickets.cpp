#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main(){
    int tickets, customers;
    cin >> tickets >> customers;

    multiset<int> p;

    for(int i = 0; i < tickets; i++){
        int a;
        cin >> a;
        p.insert(a);
    }
    
    for(int i = 0 ; i < customers; i++){
        int a;
        cin >> a;
        auto res = p.upper_bound(a);
        if(res == p.begin()){
            cout << -1 << "\n";
            continue;
        }
        else{
            res--;
            cout << *res << "\n";
            p.erase(res);
        }
    }

    return 0;
}