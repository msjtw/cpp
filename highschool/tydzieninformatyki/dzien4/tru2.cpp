#include <iostream>
#include <vector>

using namespace std;

const int ROZ = 10;

void scalanie(int p, int q, int k, vector <int> tab){
    int wynik[ROZ];
    for(int i = p, pi = p, qi = q; i < k; i++){
        wynik[i] = tab[pi] > tab[qi] ? tab[qi++] : tab[pi++];
        qi = qi >= k || qi < pi ? pi : qi;
        pi = pi >= q ? qi : pi;
    }
    for(int i = p ;i < k; i++)
        tab[i] = wynik[i];
}

void mergesort(int l, int p, vector <int> tab){
    if(l < p){
        int s = (l+p)/2;
        mergesort(l, s, tab);
        mergesort(s+1, p, tab);
        scalanie(l, s+1, p+1, tab);
    }
}

int main(){
    vector <int> tab(10);
    for(int i = 0; i < 10; i++)
        cin >> tab[i];

    mergesort(0, ROZ-1, tab);

    for(int i = 0; i < 10; i++)
        cout << tab[i] << " ";

    return 0;
}