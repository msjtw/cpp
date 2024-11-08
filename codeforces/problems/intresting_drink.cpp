#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> arr;
vector <int> arr1;

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    int q;
    cin >> q;
    for(int i = 0;i < q; i++){
        int a;
        cin >> a;
        int b = -1;
        for(int k = arr.size()/2; k > 0; k/=2){
            while(b+k < arr.size() and arr[b+k] <= a){
                b += k;
            }
        }
        cout << b+1 << endl;
    }

    return 0;
}

