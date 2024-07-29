#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int childern, max_weigth;
    cin >> childern >> max_weigth;
    vector<int>c;
    for(int i = 0 ; i < childern; i++){
        int a;
        cin >> a;
        c.push_back(a);
    }
    sort(c.begin(), c.end());

    int res = 0;

    int p = 0;
    int q = c.size()-1;

    while(p <= q){
        if(p == q){
            res++;
            p++;
            q--;
        }
        else if(c[p] + c[q] <= max_weigth){
            p++;
            q--;
            res++;
        }
        else{
            q--;
            res++;
        }
    }

    cout << res;

    return 0;
}