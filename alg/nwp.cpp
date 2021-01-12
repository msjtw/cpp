#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a = "1223111";
string b = "242312411";
string wynik = "";

int t[100][100];

int main(){
    for(int i = 1; i <= b.size(); i++){
        for(int j = 1; j <= a.size(); j++){
            if(a[j-1] == b[i-1]){
                t[i][j] = t[i-1][j-1]+1;
                
            }    
            else if(t[i-1][j] > t[i][j-1])
                t[i][j] = t[i-1][j];
            else
                t[i][j] = t[i][j-1];
        }
    }

    for(int i = 0; i <= b.size(); i++){
        for(int j = 0; j <= a.size(); j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    int col = a.size();
    int row = b.size();

    while(col > 0 && row > 0){
        if(t[row-1][col] == t[row][col]){
            row--;
        }
        else if(t[row][col-1] == t[row][col]){
            col--;
        }
        else{
            wynik += a[col-1];
            row--;
            col--;
        }
    }
    reverse(wynik.begin(), wynik.end());

    for(int i = 0; i <= wynik.size(); i+=2){
        if(wynik[i] != wynik[i+1]){
            wynik.erase(wynik.begin()+i);
            i--;
        }    
    }

    cout << wynik << endl;

    return 0;
}