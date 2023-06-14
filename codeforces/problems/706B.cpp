// Interesting drink https://codeforces.com/problemset/problem/706/B

#include <iostream>
#include <algorithm>

using namespace std;

int binsearch(int p, int q, int arr[], int val){
    int r;
    while(p <= q){
        r = (p+q)/2;
        if(arr[r] == val)
            return r;
        if(val < arr[r])
            q = r-1;
        if(val > arr[r])
            p = r+1;
    }
    return r;
}

int main(){
    int shops;
    int prices[100007];
    int days;
    cin >> shops;
    for(int i = 0; i < shops; i++)
        cin >> prices[i];
    cin >> days;
    
    sort(prices, prices+shops);

    while(days --> 0){
        int budg;
        cin >> budg;
        cout << binsearch(0, shops-1, prices, budg)+1 << endl;
    }
}