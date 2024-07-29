#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> nums;

int main (int argc, char *argv[]) {
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++){

        if(nums[i] != i+1 or i == nums.size()){
            cout << i+1;
            break;
        }
    }

    return 0;
}
