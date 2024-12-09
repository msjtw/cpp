#include <iostream>
using namespace std;

const int MX = 1e5;

int arr[MX];

int main(){
    string s;
    cin >> s;
    int idx = 0;
    int id = 1;
    for(int i = 0; i < s.length(); i++){
        if(i&1){
            //gap
            idx += s[i]-'0';
        }
        else{
            //file
            for(int k = 0; k < s[i]-'0'; k++, idx++){
                arr[idx] = id;
            }
            id++;
        }
    }  

    int p = 0, q = idx-1;
    while(p < q){
        if(arr[p] == 0){
            if(arr[q] == 0){
                q--;
            }
            else{
                swap(arr[p], arr[q]);
                p++;
                q--;
            }
        }
        else{
            p++;
        }
    }

    long long int res = 0;
    for(int i = 0; i < idx; i++){
        if(arr[i] > 0)
            res += (arr[i]-1)*i;
    }
    cout << res;
}
