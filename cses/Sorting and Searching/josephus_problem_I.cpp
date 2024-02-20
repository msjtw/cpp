#include<iostream>
#include<vector>

using namespace std;


int main(){
    int n, k;
    cin >> n;
    k = 2;

    vector <int> arr_a, arr_b;
    for(int i = 1; i <= n; i++){
        arr_a.push_back(i);
    }

    vector<int> * a = &arr_a;
    vector<int> * b = &arr_b;


    int mod = 1;
    while(!a->empty()){
        for(int i = 0; i < a->size(); i ++){
            if((i+mod)%2 == 0){
                cout << a->at(i) << " ";
            }
            else{
                b->push_back(a->at(i));
            }
        }
        if((a->size()+mod)%2 == 0)
            mod = 0;
        else
            mod = 1;
        a->clear();
        swap(a, b);
    }
    

    return 0;
}