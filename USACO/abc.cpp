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
    int pop = tab[top];
    int ilosc = 1;

    cout << tab[6]-tab[0]-tab[1];
    return 0;
}