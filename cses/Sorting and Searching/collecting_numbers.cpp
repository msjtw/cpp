#include<iostream>
#include<set>

using namespace std;

const int SIZE = 1e6+7;

int arr[SIZE];
int res = 1;

int main(){
    int n;W
    cin >> n;
    while(n --> 0){
        int a;
        cin >> a;
        if(arr[a-1] > 0){
            arr[a] = arr[a-1];
        }
        else{
            arr[a] = res;
            res++;
        }
    }

    cout << res-1;

    return 0;
}