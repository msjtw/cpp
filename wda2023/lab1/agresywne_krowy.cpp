#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int stalls, cows;
vector<int> miejsca;
// vector<int> odl;

bool mozna(int odl){
    int set_cows = 1;
    int  i = 1;
    int last_set = 0;
    while(set_cows < cows and i < miejsca.size()){
        if(miejsca[i] - miejsca[last_set] >= odl){
            set_cows++;
            last_set = i;
        }
        i++;
    }
    if(set_cows >= cows)
        return true;
    else
        return false;
}

int bin_search(int a, int b){
    while(a <= b){
        int s = (a+b)/2;
        if(mozna(s)){
            a = s+1;
        }
        else{
            b = s-1;
        }
    }
    return b;
}

int main(){
    ios_base::sync_with_stdio(false);

    int p;
    cin >> p;
    while(p --> 0){

        cin >> stalls >> cows;

        miejsca.clear();
        // odl.clear();

        for(int i = 0; i < stalls; i++){
            int a;
            cin >> a;
            miejsca.push_back(a);
        }

        sort(miejsca.begin(), miejsca.end());

        //odl.push_back(miejsca[0]);
        // for(int i = 1; i < stalls; i++){
        //     odl.push_back(miejsca[i]-miejsca[0]);
        // }

        // sort(odl.begin(), odl.end());

        cout << bin_search(0, miejsca[miejsca.size()-1]) << endl;
    }
}
