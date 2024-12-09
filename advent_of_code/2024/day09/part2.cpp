#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct file {
    int lenght;
    int id;
};

bool operator==(const file& lhs, const file& rhs){
    return lhs.id == rhs.id;
}

vector<file> disk;
vector<file> files;

int main(){
    string s;
    cin >> s;
    int id = 0;
    for(int i = 0; i < s.length(); i++){
        if(i&1){
            //gap
            disk.push_back({s[i]-'0', -1});
        }
        else{
            //file
            disk.push_back({s[i]-'0', id});
            files.push_back({s[i]-'0', id});
            id++;
        }
    }

    for(file f : disk){
        if(f.id == -1){
            for(int i = 0; i < f.lenght; i++)
                cout << '.';
        }
        else{
            for(int i = 0; i < f.lenght; i++)
                cout << f.id;

        }
    }
    cout << endl;


    for(int k = files.size()-1; k >=0; k--){
        file f = files[k];
        // cout << f.id << " " << f.lenght << ": " << endl;
        int p = 0;
        while(disk[p].id != f.id and (disk[p].id != -1 or disk[p].lenght < f.lenght)){
            // cout << "\t" << p << " " <<  disk[p].id << " " << disk[p].lenght << endl;
            p++;
        }
        // cout << "--> " << p << endl;
        if(disk[p].lenght >= f.lenght and disk[p].id == -1){
            // cout << p;
            disk[p].lenght -= f.lenght;
            find(disk.begin(), disk.end(), f)->id = -1;
            disk.insert(disk.begin()+p,f);
        }
    }

    for(file f : disk){
        if(f.id == -1){
            for(int i = 0; i < f.lenght; i++)
                cout << '.';
        }
        else{
            for(int i = 0; i < f.lenght; i++)
                cout << f.id;

        }
    }
    cout << endl;

    int idx = 0;
    long long int res = 0;
    for(file f : disk){
        if(f.id != -1){
            for(int i = 0; i < f.lenght; i++){
                res += f.id*idx;
                idx++;
            }
        }
        else{
            idx += f.lenght;
        }
    }

    cout << res;

    return 0;
}
