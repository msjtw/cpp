#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

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
        int n, k, al, ar, bl, br;
        cin >> n >> k >> al >> ar >> bl >> br;
        LL res;
        if(bl - ar > 0) {
            int dif = ar - bl;
            int difPlus = dif + ar - al + br - bl;
            int mod = k % difPlus;
            res += (k / difPlus) * 2 * dif + difPlus - dif;
            if(mod >= dif) {
                res += dif * 2 + (mod - dif);
            }
            else {
                res += 2 * dif;
            }
        }
        else {
            k -= (ar - bl) * n;
            if(k <= 0) {
                res = 0;
            }
            else {
                int dif = br - ar + bl - al;
                int mod = k % dif;
                res += dif * (k / dif);
                
            }
        }

    }

    return 0;
}