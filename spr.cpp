#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    string nazwa;
    cout << "name of exe: ";
    cin >> nazwa;
    if(nazwa.find(".") == string::npos)
        nazwa+=".exe";
    int ilosc;
    cout << "number of tests: ";
    cin >> ilosc;
    string nazwa_in, nazwa_out;
    cout << "name of in files: ";
    cin >> nazwa_in;
    cout << "name of out files: ";
    cin >> nazwa_out;
    for(int i = 1; i <= ilosc; i++){
        string command = "." + nazwa + " < /in/" + nazwa_in + to_string(i) + ".in > " + "out" + to_string(i) + ".out";
        system(command.c_str());
        ifstream in1, in2;
        string path = "/out/" + nazwa_out + to_string(i) + ".out";
        in1.open("out.out");
        in2.open(path.c_str());
        while(!in1.eof() || !in2.eof()){
            string a, b;
            in1 >> a;
            in2 >> b;
            if(a != b){
                cout << "test " << i << ": \t\tis: " << a << endl << "\t\tcorrect: " << b;
                return 0;
            }
        }
    }

    return 0;
}