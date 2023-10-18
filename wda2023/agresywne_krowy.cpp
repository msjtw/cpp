#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int stalls, cows;
vector<int> miejsca;
vector<int> odl;

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
        if(mozna){
            b = s-1;
        }
        else{
            a = s;
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

        for(int i = 0; i < stalls; i++){
            int a;
            cin >> a;
            miejsca.push_back(a);
        }

        sort(miejsca.begin(), miejsca.end());

        for(int i = 0; i < stalls; i++){
            odl.push_back(miejsca[i+1]-miejsca[i]);
        }

        sort(odl.begin(), odl.end());

        cout << bin_search(0, odl.size()-1);
    }
}
