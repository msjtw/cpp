#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

vector <int> merge(vector <int> &a, vector <int> &b){
    vector <int> c;
    int i = 0, k = 0;
    while(i < a.size() && k < b.size()){
        if(a[i] < b[k])
            c.push_back(a[i++]);
        else
            c.push_back(b[k++]);
    }
    while(i < a.size())
        c.push_back(a[i++]);
    while(k < b.size())
        c.push_back(b[k++]);

    return c;
}

int main(){
    ios_base::sync_with_stdio(0);

    int dlugosc;
    cin >> dlugosc;
    string line;
    cin >> line;

    vector <int> poz[300];

    for(int i = 0; i < line.length(); i++)
        poz[line[i]].push_back(i);

    int odp = 0;

    for(int c1 = 'a'; c1 <= 'z'; c1++){
        for(int c2 = 'a'; c2 <= 'z'; c2++){
            int wynik = 0, suma = 0, pop_mini = 0;
            int mini =  INT_MAX;
            vector <int> temp = merge(poz[c1], poz[c2]);
            for(int i = 0; i < temp.size(); i++){
                suma += (line[temp[i]] == c1 ? 1 : 0);
                suma += (line[temp[i]] == c2 ? -1 : 0);
                if(line[temp[i]] == c2){
                    mini = min(mini, pop_mini);
                    pop_mini = suma;
                }
                wynik = max(wynik, suma - mini);
            }
            odp = max(odp, wynik);
        }
    }

    cout << odp;

    return 0;
}