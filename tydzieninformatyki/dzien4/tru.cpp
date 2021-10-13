#include <iostream>
#include <vector>

using namespace std;

int koszt = 0;
const int ROZ = 1000007;


void scalanie(int p, int q, int k, int tab[]){
    int wynik[ROZ];
    int skip = 0;
    for(int i = p, pi = p, qi = q; i < k; i++){
        if(tab[pi] > tab[qi]){
            wynik[i] = tab[qi];
            //cout << p << " " << k << " || " << pi << " " << tab[pi] << " :: " << qi << " " << tab[qi] << " " << qi-pi <<endl;
            skip++;
            qi++;
            koszt += qi-pi - skip;
        }
        else{
            wynik[i] = tab[pi++];
        }
        qi = qi >= k || qi < pi ? pi : qi;
        pi = pi >= q ? qi : pi;
    }
    for(int i = p ;i < k; i++)
        tab[i] = wynik[i];
}

void mergesort(int l, int p, int tab[]){
    if(l < p){
        int s = (l+p)/2;
        mergesort(l, s, tab);
        mergesort(s+1, p, tab);
        scalanie(l, s+1, p+1, tab);
    }
}

int main(){
    int len;
    cin >> len;
    string a, b;
    cin >> a >> b;
    vector <int> va[255], vb;

    int poz = 0;
    va[a[0]].push_back(poz);
    for(int i = 1; i < a.length(); i++){
        if(a[i] != a[i-1])
            poz++;
        va[a[i]].push_back(poz);
    }
    for(int i = 0; i < b.size(); i++){
        vb.push_back(va[b[i]][0]);
        va[b[i]].erase(va[b[i]].begin());
    }
    int tab[1000007];
    for(int i = 0;i < len; i++){
        tab[i] = vb[i];
    }

    mergesort(0, len-1, tab);

    cout << koszt;

    return 0;
}
