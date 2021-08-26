#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<pair<int, int>> VPII;
typedef pair<int, int> PII;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
#define INF 1000000001

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        VPII vec(n);
        REP(x, n) {
            cin >> vec[x].ST;
            vec[x].ND = x + 1;
        }
        sort(ALL(vec));
        int i = 0, j = 0;
        int sum = vec[i].ST;
        while(true) {
            if(sum < 0) sum += vec[++j].ST;
            else if(sum > 0) sum -= vec[i++].ST;
            else break;
        }
        FOR(x, i, j) {
            cout << vec[x].ND << " ";
        }
        cout << '\n';
    }

    return 0;
}