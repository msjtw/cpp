#include <iostream>
#include <vector>

using namespace std;
iint main(){
    int p ;
    cin >> p;
    while(p-->0){
        int n;
        cin >> n;
        vector<int> arr;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            arr.push_back(a);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int k = i+1; k < n; k++){
                if(arr[i] > arr[k])
                    res++;
            }
        }
        cout << res << endl;

    }
    return 0;
}
