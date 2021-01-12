#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

struct node
{
    int wartosc;
    int suma;
};

int base = 8;

void insert(vector<node>& tree, int p, int q, int w, int base){
    int len = 1;
    tree[p].wartosc += w;
    tree[p].suma += w;

    if(q != p){
        tree[q].wartosc += w;
        tree[q].suma += w;
    }

    while(p > 0){
        if(p < q - 1){
            if(p%2 == 0){
                tree[p + 1].wartosc += w;
                tree[p + 1].suma += w * len;
            }
            if(q%2 == 1){
                tree[q - 1].wartosc += w;
                tree[q - 1].suma += w * len;
            }
        }

        if(p < base){
            tree[p].suma = tree[p * 2].suma + tree[p * 2 + 1].suma + tree[p].wartosc * len;
            tree[q].suma = tree[q * 2].suma + tree[q * 2 + 1].suma + tree[q].wartosc * len;
        }

        p /= 2;
        q /= 2;
        len *= 2;
    }

}

int query(vector<node>& tree, int p, int q)
{
    int len = 1;

    int dlugoscZLewej, dlugoscZPrawej;
    dlugoscZLewej = 1;
    dlugoscZPrawej = (p != q ? 1 : 0);

    int suma = 0;

    while(p > 0){
        suma += dlugoscZLewej * tree[p].wartosc + dlugoscZPrawej * tree[q].wartosc;

        if(p < q - 1){
            if(!(p % 2)){
                suma += tree[p + 1].suma;
                dlugoscZLewej += len;
            }
            if(q % 2){
                suma += tree[q - 1].suma;
                dlugoscZPrawej += len;
            }
        }

        p /= 2;
        q /= 2;
        len *= 2;
    }

    return suma;
}

int main()
{

    vector<node> tree(2*base);

    insert(tree, 1 + base, 5 + base, 5, base);
    cout << endl;
    for(int i = 1; i < base*2; i++){
        cout << tree[i].wartosc << " ";
    }
    cout << endl;
    for(int i = 1; i < base*2; i++){
        cout << tree[i].suma << " ";
    }
    cout << endl;

    insert(tree, 3 + base, 4 + base, 2, base);
        cout << endl;
    for(int i = 1; i < base*2; i++){
        cout << tree[i].wartosc << " ";
    }
    cout << endl;
    for(int i = 1; i < base*2; i++){
        cout << tree[i].suma << " ";
    }
    cout << endl;

    insert(tree, 5 + base, 7 + base, 5, base);
        cout << endl;
    for(int i = 1; i < base*2; i++){
        cout << tree[i].wartosc << " ";
    }
    cout << endl;
    for(int i = 1; i < base*2; i++){
        cout << tree[i].suma << " ";
    }
    cout << endl;

    // cout << query(tree, base, 7 + base) << endl;
    // cout << query(tree, 4 + base, 7 + base) << endl;
    // cout << query(tree, 5 + base, 6 + base) << endl;
    // cout << query(tree, 3 + base, 6 + base) << endl;
    
    return 0;
}