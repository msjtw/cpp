#include <iostream>

using namespace std;

int main(){
    int n = 146;
    string arr[150];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int res = 0;
    
    for(int i = 3; i < 145; i ++){
        for(int k = 3; k < 145; k++){
            if(arr[i][k] == 'A'){
                if(arr[i-1][k-1] == 'M' and arr[i-1][k+1] == 'M' and arr[i+1][k-1] == 'S' and arr[i+1][k+1] == 'S')
                    res++;
                if(arr[i-1][k-1] == 'S' and arr[i-1][k+1] == 'M' and arr[i+1][k-1] == 'S' and arr[i+1][k+1] == 'M')
                    res++;
                if(arr[i-1][k-1] == 'S' and arr[i-1][k+1] == 'S' and arr[i+1][k-1] == 'M' and arr[i+1][k+1] == 'M')
                    res++;
                if(arr[i-1][k-1] == 'M' and arr[i-1][k+1] == 'S' and arr[i+1][k-1] == 'M' and arr[i+1][k+1] == 'S')
                    res++;

            }
        }
    }

    cout << res;

    return 0;
}
