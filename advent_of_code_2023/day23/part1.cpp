#include<iostream>
#include<queue>

using namespace std;

 pair<int,int> BEGIN = {1,1};
 pair<int,int> END = {139,139};

string map[400];

int dfs(pair<int,int > curr, pair<int, int> last, int len){
    if(curr == END){
        return len;
    }

    if(map[curr.first][curr.second] == 'v')
        return dfs({curr.first+1,curr.second}, curr, len+1);
    if(map[curr.first][curr.second] == '>')
        return dfs({curr.first,curr.second+1}, curr, len+1);
    if(map[curr.first][curr.second] == '^')
        return dfs({curr.first-1,curr.second}, curr, len+1);
    if(map[curr.first][curr.second] == '<')
        return dfs({curr.first,curr.second-1}, curr, len+1);

    int res = 0;
    pair<int,int> next;
    next = {curr.first-1, curr.second};
    if(next != last and map[next.first][next.second] != '#' and map[next.first][next.second] != 'v'){
        res = max(res, dfs(next, curr, len+1));
    }
    next = {curr.first+1, curr.second};
    if(next != last and map[next.first][next.second] != '#' and map[next.first][next.second] != '^'){
        res = max(res, dfs(next, curr, len+1));
    }
    next = {curr.first, curr.second-1};
    if(next != last and map[next.first][next.second] != '#' and map[next.first][next.second] != '>'){
        res = max(res, dfs(next, curr, len+1));
    }
    next = {curr.first, curr.second+1};
    if(next != last and map[next.first][next.second] != '#' and map[next.first][next.second] != '<'){
        res = max(res, dfs(next, curr, len+1));
    }

    return res;
}

int main(){
    int n;
    cin >> n;
    BEGIN = {1,1};
    END = {n-2,n-2};
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }

    cout << dfs(BEGIN, BEGIN, 0) + 2;
    return 0;
}