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
            if(arr[i][k] == 'X'){
                if(arr[i][k+1] == 'M' and arr[i][k+2] == 'A' and arr[i][k+3] == 'S')
                    res++;
                if(arr[i][k-1] == 'M' and arr[i][k-2] == 'A' and arr[i][k-3] == 'S')
                    res++;
                if(arr[i+1][k] == 'M' and arr[i+2][k] == 'A' and arr[i+3][k] == 'S')
                    res++;
                if(arr[i-1][k] == 'M' and arr[i-2][k] == 'A' and arr[i-3][k] == 'S')
                    res++;

                if(arr[i-1][k-1] == 'M' and arr[i-2][k-2] == 'A' and arr[i-3][k-3] == 'S')
                    res++;
                if(arr[i-1][k+1] == 'M' and arr[i-2][k+2] == 'A' and arr[i-3][k+3] == 'S')
                    res++;
                if(arr[i+1][k-1] == 'M' and arr[i+2][k-2] == 'A' and arr[i+3][k-3] == 'S')
                    res++;
                if(arr[i+1][k+1] == 'M' and arr[i+2][k+2] == 'A' and arr[i+3][k+3] == 'S')
                    res++;
            }
        }
    }

    cout << res;

    return 0;
}
