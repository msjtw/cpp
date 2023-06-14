#include <iostream>

using namespace std;

int binsearch(int l, int r, int arr[], int val){
    int m;
    while(l < r){
        m = (l+r) >> 1;

        if(arr[m] < val+1)
            l = m+1;
        else
            r = m;
    }
    return l-1;
}

int main(){
    int arr[] = {2,6,8,11,15};
    for(int i = 1; i < 17; i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i = 1; i < 17; i++){
        cout << binsearch(0, 4, arr, i) << " ";
        if(i > 9)
            cout << " ";
    }
}
