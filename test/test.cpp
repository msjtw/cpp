#include <iostream>

using namespace std;

int binsearch(int p, int q, int arr[], int val) {

    int m;

    while(p < q){
        m = (p+q)/2;
        if(val < arr[m])
            q = m;
        else
            p = m+1;
    }

    if(arr[m] <= val)
        return p;
    else
        return -1;



//    if( p == q )
//       return arr[p] <= val ? p : -1;

//    int m = (p+q)/ 2;

//    if( val < arr[m] )
//       return binsearch(p, m, arr, val );

//    int ret = binsearch(m+1, q, arr, val );
//    return ret == -1 ? m : ret;
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
