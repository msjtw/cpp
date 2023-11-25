#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> pierwsze;

void pierw(int a){
    pierwsze.push_back(2);
    for(int j = 2; pierwsze.size()<a ; j++){
        bool nie = false;
        for(int i = 2; i*i <= j; i++){
            if( j%i == 0){
                nie = true;
            }
        }
        if(!nie)
            pierwsze.push_back(j);
    }
}

bool noda(int a){
    for(int x = 0; pierwsze[x] < a; x++){
        for(int y = 0; pierwsze[x]+pierwsze[y] < a; y++){
            for(int z = 0; pierwsze[x]+pierwsze[y]+pierwsze[z] <= a; z++){
                if(pierwsze[x]+pierwsze[y]+pierwsze[z] == a)
                    return 1;
            }
        }
    }
    return 0;
}

int main(){
    pierw(2000);
    int wynik = 0;
    for(int i = 5; i <= 20202021; i+=2){
        if(noda(i)){
            //cout << i << " ";
            wynik++;
        }
    }
    cout << wynik;
    return 0;
}
