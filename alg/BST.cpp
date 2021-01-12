#include <iostream>
#include <vector>

using namespace std;

struct node{
    int key;
    int id;
    int p;
    int l;
    int r;
};

void insert(vector <node> &bst_tab ,int a){
    if(bst_tab.size() == 0)
        bst_tab.push_back({0,0,0,0,0});
    if(bst_tab.size() == 1)
        bst_tab.push_back({a,1,0,0,0});
    else{
        node x = bst_tab[1];
        node y;
        while(x.id != 0){
            y = x;
            if(a < x.key)
                x = bst_tab[x.l];
            else
                x = bst_tab[x.r];
        }
        if(a < y.key)
            bst_tab[y.id].l = bst_tab.size();
        else
            bst_tab[y.id].r = bst_tab.size();
        int id = bst_tab.size();
        bst_tab.push_back({a,id,y.id,0,0});
    }   
}

void left_rotate(vector <node> &bst_tab, int a){
    if(bst_tab[a].r != 0){
        int k = bst_tab[a].r;
        bst_tab[a].r = bst_tab[k].l;
        if(bst_tab[k].l != 0)
            bst_tab[bst_tab[k].l].p = bst_tab[a].id;
        bst_tab[k].p = bst_tab[a].p;
        if(bst_tab[a].p == 0)
            swap(bst_tab[a], bst_tab[k]);// jeśli korzeń ->  ale nie do końca
        else if(bst_tab[a].id == bst_tab[bst_tab[a].p].l)
            bst_tab[bst_tab[a].p].l = k;
        else
            bst_tab[bst_tab[a].p].r = k;
        bst_tab[k].l = bst_tab[a].id;
        bst_tab[a].p = bst_tab[k].id;
    }
}

int search(vector <node> &bst_tab, int a){
    node x = bst_tab[1];
    while(x.key != a){
        if(x.id == 0)
            return -1;
        if(a < x.key)
            x = bst_tab[x.l];
        else
            x = bst_tab[x.r];
    }
    return x.id;
}

int bst_min(vector <node> &bst_tab){
    node x = bst_tab[1];
    while(x.l != 0)
        x = bst_tab[x.l];

    return x.key;
}

int main(){
    vector <node> bst;
    int z = 9;
    
    while(true){
        int a;
        cin >> a;
        if(a == 0)
            break;
        insert(bst, a);
    }

    left_rotate(bst, 3);

    for(int i = 0; i < bst.size(); i++){
        cout << bst[i].key << " " << bst[bst[i].p].key << " " << bst[bst[i].l].key << " " << bst[bst[i].r].key << endl;
    }

    return 0;
}