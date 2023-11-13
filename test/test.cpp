#include <iostream>

using namespace std;

void a(char &arr){
    cout << arr << sizeof arr << " " << sizeof(arr) << endl;
}

int main(){
    char arr[] = "OK";
    cout << arr << sizeof arr << " " << sizeof(arr) << endl;
    a(&arr);
}