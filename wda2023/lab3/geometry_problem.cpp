#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector <int> add(vector<int> a, vector<int>b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    a.push_back(0);

    if(a.size() < b.size()){
        swap(a,b);
    }
    for (int i = 0; i < b.size(); ++i) {
        a[i] += b[i];
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > 9) {
            a[i] -= 10;
            a[i + 1] += 1;
        }
    }
    reverse(a.begin(), a.end());

    for (int i = 0; i < a.size() && a[i] == 0; ++i) {
        a.erase(a.begin() + i);
        i--;
    }

    return a;
}

vector <int> sub(vector <int> a, vector <int> b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.size() < b.size()) {
        swap(a, b);
    }
    for (int i = 0; i < b.size(); ++i) {
        a[i] -= b[i];
    }

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < 0) {
            a[i] += 10;
            a[i + 1] -= 1;
        }
    }

    reverse(a.begin(), a.end());

    for (int i = 0; i < a.size() && a[i] == 0; ++i) {
        a.erase(a.begin() + i);
        i--;
    }

    return a;
}

int main(){
    int p;
    cin >> p;
    while(p-->0){
        string sb, sc, sd;
        cin >> sb >> sc >> sd;
        vector<int> a;
        vector<int> b;
        vector<int> c;
        vector<int> d;

        for(auto x : sb){
            b.push_back(x-'0');
        }
        for(auto x : sc){
            c.push_back(x-'0');
        }
        for(auto x : sd){
            d.push_back(x-'0');
        }

        a = add(c,c);
        a = sub(a, b);
        a = sub(a, d);

        for(auto x : a)
            cout << x;
        cout << endl;
    }
    return 0;
}