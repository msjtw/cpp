#include <iostream>

using namespace std;

typedef long long int ll;

const int BASE = 1<<19;
const int MX = 2e5+7;
ll INF = __INT64_MAX__;

ll max_tree[2*BASE][2];
ll sum_tree[2*BASE][2];
int val[MX];

void max_add(int a, int b, int val, int k=1, int x=0, int y=BASE-1){
    if(a <= x and y <= b){
        max_tree[k][1] += val;
        return;
    }
    max_tree[2*k][1] += max_tree[k][1];
    max_tree[2*k+1][1] += max_tree[k][1];
    max_tree[k][0] += max_tree[k][1];
    max_tree[k][1] = 0;

    int d = (x+y)/2;
    if(a <= d){
        max_add(a, b, val, 2*k, x, d);
        }
    if(b > d){
        max_add(a, b, val, 2*k+1, d+1, y);
    }
    max_tree[k][0] = max(max_tree[2*k+1][0] + max_tree[2*k+1][1], max_tree[2*k][0] + max_tree[2*k][1]);

}

ll max_query(int a, int b, int k=1, int x=0, int y=BASE-1){
    if(a <= x and y <= b){
        return max_tree[k][0] + max_tree[k][1];
    }
    max_tree[2*k][1] += max_tree[k][1];
    max_tree[2*k+1][1] += max_tree[k][1];
    max_tree[k][0] += max_tree[k][1];
    max_tree[k][1] = 0;

    int d = (x+y)/2;
    ll ret = -INF;
    if(a <= d){
        ret = max(ret, max_query(a, b, 2*k, x, d));
    }
    if(b > d){
        ret = max(ret, max_query(a, b, 2*k+1, d+1, y));
    }
    return ret;
}

void sum_add(int a, int b, int val, int k=1, int x=0, int y=BASE-1){
    if(a <= x and y <= b){
        sum_tree[k][1] += val;
        return;
    }
    sum_tree[2*k][1] += sum_tree[k][1];
    sum_tree[2*k+1][1] += sum_tree[k][1];
    sum_tree[k][0] += sum_tree[k][1]*(y-x+1);
    sum_tree[k][1] = 0;

    int d = (x+y)/2;
    if(a <= d){
        int w = (d <= b ? d : b)+1;
        w -= (x <= a ? a : x);
        sum_tree[k][0] += val*(w);
        sum_add(a, b, val, 2*k, x, d);
    }
    if(b > d){
        int w = (y <= b ? y : b)+1;
        w -= (d+1 <= a ? a : d+1);
        sum_tree[k][0] += val*(w);
        sum_add(a, b, val, 2*k+1, d+1, y);
    }
}

ll sum_query(int a, int b, int k=1, int x=0, int y=BASE-1){
    if(a <= x and y <= b){
        return sum_tree[k][0] + sum_tree[k][1]*(y-x+1);
    }
    sum_tree[2*k][1] += sum_tree[k][1];
    sum_tree[2*k+1][1] += sum_tree[k][1];
    sum_tree[k][0] += sum_tree[k][1]*(y-x+1);
    sum_tree[k][1] = 0;

    int d = (x+y)/2;
    ll ret = 0;
    if(a <= d){
        ret += sum_query(a, b, 2*k, x, d);
    }
    if(b > d){
        ret += sum_query(a, b, 2*k+1, d+1, y);
    }
    return ret;
}


int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> val[i];
        max_add(i,n,val[i]);
        sum_add(i,n,val[i]);
    }

    while(q-->0){
        ll op, a, b;
        cin >> op >> a >> b;
        if(op == 1){
            ll diff = b - val[a];
            val[a] = b;
            max_add(a,n,diff);
            sum_add(a,n,diff);
        }
        else{
            ll r1 = max_query(a, b);
            ll r2 = sum_query(a-1,a-1);
            cout << max(r1-r2, 0LL) << endl;
        }
    }

    return 0;
}
