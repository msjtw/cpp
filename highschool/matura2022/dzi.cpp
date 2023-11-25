#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool mozna(int s, string dzialka[30]){
    for(int i = 0; i < s; i++){
        for(int k = 0; k < s; k++){
            if(dzialka[i][k] == 'X')
                return false;
        }
    }
    return true;
}

int main(){
    int p;
    cin >> p;
    int max_size = 0;
    vector <int> poz;

    for(int z = 1; z <= p; z++){
        string dzialka[30];
        for(int i = 0; i < 30; i++){
            cin >> dzialka[i];
        }
        int size = 0;
        while(size < 30 && mozna(size, dzialka))
            size++;
        if(size == max_size)
            poz.push_back(z);
        else if(size > max_size){
            max_size = size;
            poz.clear();
            poz.push_back(z);
        }
    }

    cout << max_size-1 << endl;
    for(auto a : poz)
        cout << a << endl;

    return 0;
}