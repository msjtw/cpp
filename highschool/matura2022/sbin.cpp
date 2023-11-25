#include <iostream>
#include <vector>

using namespace std;

int main(){
    int p;
    cin >> p;

    int maxi = 0;
    vector <string> slo;

    while(p --> 0){
        string a;
        cin >> a;
        int len =  0;
        int loc_max = 0;
        int i = 0;
        while(i < a.size()){
            len = 0;
            while(i < a.size() && a[i] == '1')
                i++;
            while(i < a.size() && a[i] == '0'){
                i++;
                len++;
            }
            loc_max = max(loc_max, len);
        }
        if(loc_max > maxi){
            maxi = loc_max;
            slo.clear();
            slo.push_back(a);
        }
        else if(loc_max == maxi)
            slo.push_back(a);
    }
    cout << maxi << endl;
    for(auto a : slo)
        cout << a << endl;

    return 0;
}