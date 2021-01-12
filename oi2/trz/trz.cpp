#include <iostream>
#include <string>

using namespace std;

string st;

bool is_good(int a, int b, int c){
    if(a !=b && b != c && a != c)
        return true;
    else if(a != b && c == 0)
        return true;
    else if(a != c && b == 0)
        return true;
    else if(b != c && a == 0)
        return true;
    else if(a == 0 && b == 0)
        return true;
    else if(a == 0 && c == 0)
        return true;
    else if(b == 0 && c == 0)
        return true;
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);

    int len;
    cin >> len;
    cin >> st;

    int wyn = 0;

    int a = 0, b = 0, c = 0;

    for(int i = 0; i < 3; i++){
        for(int k = i; k < st.size(); k++){
            if(st[k] == 'C')
                a++;
            else if(st[k] == 'S')
                b++;
            else
                c++;
            if(is_good(a,b,c))
                wyn = max(wyn, k-i+1);
        }
        a= 0, b = 0, c = 0;
    }
    for(int k = st.size()-1; k >= st.size()-3; k--){
        for(int i = k; i >= 0; i--){
            if(st[i] == 'C')
                a++;
            else if(st[i] == 'S')
                b++;
            else
                c++;
            if(is_good(a,b,c))
                wyn = max(wyn, k-i+1);
        }
        a= 0, b = 0, c = 0;
    }
    cout << wyn;

    return 0;
}