#include <iostream>
#include <algorithm>

using namespace std;

int tab[7];

int main()
{
    for(int i = 0; i < 7; i++){
        cin >> tab[i];
    }
    sort(tab,tab+7);
    cout << tab[0] << " " << tab[1] << " ";
    int top = 1;
    bool wyp = false;
    do{
        wyp = true;
        top++;
        for(int i = 0; i < top; i++){
            for(int j = i; j < top; j++){
                if(tab[i]+tab[j] == tab[top])
                wyp = false;
            }
        }
    }while(!wyp);

    cout << tab[top];
}