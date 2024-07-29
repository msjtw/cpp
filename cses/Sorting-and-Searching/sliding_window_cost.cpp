#include<iostream>
#include<set>
#include<vector>

using namespace std;

vector<int> arr;
multiset<int> low;
multiset<int> upp;

long long int suml;
long long int sumu;

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
        suml += arr[i];
    }
    while(low.size()-1 > upp.size()){
        suml -= *low.rbegin();
        sumu += *low.rbegin();
        upp.insert(*low.rbegin());
        low.erase(low.find(*low.rbegin()));
    }

    int m = *low.rbegin();
    cout << ((m*low.size())-suml) + (sumu-(m*upp.size())) << " ";

    for(int i = k; i < n; i++){
        int b = arr[i-k];
        int a = arr[i];
        if(b > *low.rbegin()){
            sumu -= b;
            sumu += a;
            upp.erase(upp.find(b));
            upp.insert(a);
        }
        else{
            suml -= b;
            suml += a;
            low.erase(low.find(b));
            low.insert(a);
        }
        if(upp.size() > 0 and *upp.begin() < *low.rbegin()){
            int c = *upp.begin();
            int d = *low.rbegin();
            sumu -= c;
            suml -= d;
            suml += c;
            sumu += d;
            upp.erase(upp.find(c));
            low.erase(low.find(d));
            low.insert(c);
            upp.insert(d);
        }
        m = *low.rbegin();
        cout << ((m*low.size())-suml) + (sumu-(m*upp.size())) << " ";
    }

    return 0;
}