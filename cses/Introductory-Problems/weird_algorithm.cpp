#include<iostream>

using namespace std;

int main (int argc, char *argv[]) {
  long long int n;
  cin >> n;
  while( n != 1){
    cout << n << " ";
    if( n & 1 ){
      n = n*3 + 1;
    }
    else{
      n /= 2;
    }
  }
  cout << n << " ";
  return 0;
}
