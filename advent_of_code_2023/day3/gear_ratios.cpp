#include <iostream>

using namespace std;

int res = 0;

string arr[150];

int main(){
    int n = 142;

    for(int i = 0; cin >> arr[i]; i++);

    for(int i = 1; i < 141; i++){
        for(int k = 1; k < arr[i].length()-1; k++){
            if(isdigit(arr[i][k])){
                int val = 0;
                bool part = false;
                for(; k < arr[i].length()-1 and isdigit(arr[i][k]); k++){
                    val *= 10;
                    val += (arr[i][k] - '0');
                    if(arr[i-1][k] != '.' and !isdigit(arr[i-1][k]))
                        part = true;
                    if(arr[i-1][k+1] != '.' and !isdigit(arr[i-1][k+1]))
                        part = true;
                    if(arr[i][k+1] != '.' and !isdigit(arr[i][k+1]))
                        part = true;
                    if(arr[i+1][k+1] != '.' and !isdigit(arr[i+1][k+1]))
                        part = true;
                    if(arr[i+1][k] != '.' and !isdigit(arr[i+1][k]))
                        part = true;
                    if(arr[i+1][k-1] != '.' and !isdigit(arr[i+1][k-1]))
                        part = true;
                    if(arr[i][k-1] != '.' and !isdigit(arr[i][k-1]))
                        part = true;
                    if(arr[i-1][k-1] != '.' and !isdigit(arr[i-1][k-1]))
                        part = true;
                }
                if(part){
                    res += val;

                }
            }
        }
    }

    cout << res;

    return 0;
}