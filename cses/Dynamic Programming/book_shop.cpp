#include <iostream>

using namespace std;

struct book{
    int pages;
    int price;
};

int num_books, max_price;
book books[1007];

int DP[1007][100007];

int main(){
    cin >> num_books >> max_price;
    for(int i = 0; i < num_books; i++){
        cin >> books[i+1].price;
    }
    for(int i = 0; i < num_books; i++){
        cin >> books[i+1].pages;
    }
    for(int i = 1; i <= num_books; i++){
        for(int k = 1; k <= max_price; k++){
            if(k - books[i].price >= 0){
                if(DP[i-1][k] > DP[i-1][k-books[i].price] + books[i].pages ){
                    DP[i][k] = DP[i-1][k];
                }
                else{
                    DP[i][k] = DP[i-1][k-books[i].price] + books[i].pages;
                }
            }
            else{
                DP[i][k] = DP[i-1][k];
            }
        }
    }

    // for(int i = 0; i <= num_books; i++){
    //     for(int k = 0; k <= max_price; k++){
    //         cout << DP[i][k] << " ";
    //     }
    //     cout << endl;
    // }

    cout << DP[num_books][max_price];

    return 0;
}