#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    set<string> all;
    do{
        all.insert(s);
    }while(next_permutation(s.begin(),s.end()));

    cout << all.size() << endl;
    for(string s : all){
        cout << s << endl;
    }

    return 0;
}
