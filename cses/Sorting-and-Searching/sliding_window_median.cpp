#include<iostream>
#include<set>
#include<vector>

using namespace std;

vector<int> arr;
multiset<int> low;
multiset<int> upp;

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    for(int i = 0 ; i < k; i++){
        low.insert(arr[i]);
    }
    while(low.size()-1 > upp.size()){
        upp.insert(*low.rbegin());
        low.erase(low.find(*low.rbegin()));
    }

    cout << *low.rbegin() << " ";

    for(int i = k; i < n; i++){
        int b = arr[i-k];
        int a = arr[i];
        if(b > *low.rbegin()){
            upp.erase(upp.find(b));
            upp.insert(a);
        }
        else{
            low.erase(low.find(b));
            low.insert(a);
        }
        if(upp.size() > 0 and *upp.begin() < *low.rbegin()){
            int c = *upp.begin();
            int d = *low.rbegin();
            upp.erase(upp.find(*upp.begin()));
            low.erase(low.find(*low.rbegin()));
            low.insert(c);
            upp.insert(d);
        }
        cout << *low.rbegin() << " ";
    }

    return 0;
}