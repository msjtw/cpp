#include<iostream>
using namespace std;
int main(){
    long long a,b,c,k; cin>>a>>b>>c>>k;
    long long sum = a+b+c;
    if(sum%3!=0)cout<<-1;
    else{
        sum/=3;
        if((a-sum)%k!=0 || (b-sum)%k!=0 || (c-sum)%k!=0){
            cout<<-1;
        }
        else{
            long long odp=0;
            if(a>sum)odp+=(a-sum)/k;
            if(b>sum)odp+=(b-sum)/k;
            if(c>sum)odp+=(c-sum)/k;
            cout<<odp;
        }
    }
}