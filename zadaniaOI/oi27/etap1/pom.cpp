#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int p;
    cin >> p;
    while(p--){
        int k;
        string a, b, c;
        cin >> a >> b >> k;
        int n = a.size();
        c = a;
        int koszt[100007] {};
        int diff = -1;
        for(int i = 0; i < n; i++){
            if(i > 0)
                koszt[i] = koszt[i-1];
            if(a[i] != b[i])
                koszt[i]++;
        }
        for(int i = n-1; i >= 0 && diff == -1; i--){
            for(int l = b[i]-1; l > '0' && b[i] != '0'; l--){
                koszt[i] = (i > 0 ? koszt[i-1] : 0) + (a[i] != l ? 1 : 0);
                if(koszt[i] > k)
                    continue;
                if(koszt[i] + (n-i-1) < k)
                    continue;
                else{
                    diff = i;
                    break;
                }
            }
        }

        if(diff == -1){
            cout << -1 << endl;
        }
        else{
            k -= koszt[diff];
            for(int i = 0; i < diff; i++){
                c[i] = b[i];
            }

            // if(a[diff] >= b[diff])
            //     c[diff] = b[diff]-1;
            // else if(k > 0 && a[diff] != b[diff]-1){
            //     c[diff] = b[diff]-1;
            //     k--;
            // }
            c[diff] = b[diff]-1;

            for(int i = diff+1; i < n && k > 0; i++){
                if(a[i] != '9'){
                    k--;
                    c[i] = '9';
                }
            }
            for(int i = n-1; i > diff && k > 0; i--){
                if(a[i] == '9'){
                    k--;
                    c[i] = '8';
                }
            }
            cout << c << '\n';
        }
    }

    return 0;
}