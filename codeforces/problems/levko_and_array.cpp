#include <iostream>
#include <vector>

using namespace std;

vector <int> arr;

bool possible(int changes, int k){
    int next;
    for(int i = 0; i < arr.size()-1; i++){
        if(abs(arr[i+1]-arr[i]) > k)
    }
}

int main (int argc, char *argv[]) {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    return 0;
}
