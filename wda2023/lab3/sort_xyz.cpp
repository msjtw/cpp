#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point{
    int a, b, c;
};

bool por(point l, point r){
    if(l.a == r.a){
        if(l.b == r.b){
            return l.c < r.c;
        }
        else{
            return l.b < r.b;
        }
    }
    else{
        return l.a < r.a;
    }
}

int main(){
    int a;
    vector<point> arr;
    cin >> a;
    while(a --> 0){
        point b;
        cin >> b.a >> b.b >> b.c;
        arr.push_back(b);
    }
    sort(arr.begin(), arr.end(), por);
    for(auto b : arr)
        cout << b.a << " " << b.b << " " << b.c << endl;
}