#include <bits/stdc++.h>

using namespace std;

bool if_power3(int temp){
    int r=temp%3;
    if(temp==1) return true;
    while(r==0){
        if(temp==2) return false;
        temp/=3;
        r=temp%3;
        if(temp==1) return true;
    }
    return false;
}

int factorial(int a){
    int f=1;
    for(int i=2;i<a+1;i++) f*=i;
    return f;
}

int foson(int a){
    int sumof=0, temp;
    while(a>0){
        temp=a%10;
        a/=10;
        sumof+=factorial(temp);
    }
    return sumof;
}

int NWD(int a, int b){

    while(!b)
        swap(a%=b,b);

    return a;
}

int main(){


    int temp, count_power3=0, nwdd, zad3_1, zad3_2=0, zad3_3, j=1;
    int tab[501];
    tab[500]=1;

        for(int i=0;i<500;i++){
            cin>>temp;
            if(if_power3(temp)) count_power3++;
            tab[i]=temp;
        }
        cout<<"zad1: "<<count_power3<<endl;

        cout<<"zad2: "<<endl;
        for(int i=0;i<500;i++){
            temp=tab[i];
            if(foson(temp)==temp){
                cout<<temp<<endl;
            }
        }
        cout<<"test"<<endl;
        for(int i=0;i<500;i++){
            nwdd=tab[i];
            while(nwdd>1){
                if(NWD(tab[i+j],nwdd)==1) break;
                nwdd=NWD(tab[i+j],nwdd);
                j++;
            }
            if(j>zad3_2){
                zad3_1=tab[i];
                zad3_2=j;
                zad3_3=nwdd;
            }
            j=1;
        }
        cout<<"zad3:"<<endl<<zad3_1<<endl<<zad3_2<<endl<<zad3_3<<endl;
    return 0;
}