// Taxi https://codeforces.com/problemset/problem/158/B

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int res = 0;

    int n;
    cin >> n;
    int arr[100007];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    for(int i = 0, k = n-1; i <= k;){
        int cap = arr[k];
        k--;
        while(cap + arr[k] <= 4)
            cap += arr[k--];

        while(cap + arr[i] <= 4)
            cap += arr[i++];

        res++;
    }

    cout << res;

    return 0;
}