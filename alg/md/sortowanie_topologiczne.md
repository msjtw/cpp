## sortowanie topologiczne

```c++
// zrodlo: https://www.youtube.com/watch?v=U0m-i9vu1TY&t=2115s

vector <int> graf[100];
int punktow;
vector <int> kolejonsc;

void top(){
    int stopnie[100] = {};
    for(int i = 0; i < punktow; i++){
        for(int k = 0; k < graf[i].size(); k++)
            stopnie[graf[i][k]]++;
    }
    queue <int> q;
    for(int i = 0; i < punktow; i++){
        cout << stopnie[i] << " ";
        if(stopnie[i] == 0)
            q.push(i);
    }
    while(q.size() > 0){
        kolejonsc.push_back(q.front());
        for(int i = 0; i < graf[q.front()].size(); i++){
            stopnie[graf[q.front()][i]]--;
            if(stopnie[graf[q.front()][i]] == 0)
                q.push(graf[q.front()][i]);
        }
        q.pop();
    }
}
```