#include <iostream>
#include <vector>

using namespace std;

struct zab{
    int ilosc, war;
    int prev, next;
};

int ilosc[1000007];
vector <zab> graf;

int main(){
    int zabytkow;
    cin >> zabytkow;
    for(int i = 0; i < zabytkow; i++){
        int a;
        cin >> a;
        ilosc[a]++;
    }

    for(int i = 0; i < 1000007;i++){
        if(ilosc[i] > 0)
            graf.push_back({ilosc[i], i, (int)graf.size()-1, (int)graf.size()+1});
    }
    graf[0].prev = graf.size()-1;
    graf[graf.size()-1].next = 0;
    int zach = 0;
    int first = 0;
    int last = graf.size()-1;
    while(zabytkow && first != last){
        for(int i = first; ; i = graf[i].next){
            zabytkow--;
            zach++;
            graf[i].ilosc--;
            if(graf[i].ilosc == 0){
                graf[graf[i].prev].next = graf[i].next;
                graf[graf[i].next].prev = graf[i].prev;
                if(i == first)
                    first = graf[i].next;
                if(i == last){
                    last = graf[i].prev;
                    break;
                }    
            }
        }
        zach--;
    }

    cout << zach;

    return 0;
}