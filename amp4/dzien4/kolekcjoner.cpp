#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef long long LL;
typedef vector<LL> VI;
typedef vector<pair<LL, LL>> VPII;
typedef pair<LL, LL> PII;

#define FOR(x, b, e) for(LL x = b; x <= (e); ++x)
#define FORD(x, b, e) for(LL x = b; x >= (e); --x)
#define REP(x, n) for(LL x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((LL)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
#define INF 1000000001

LL summ(LL n) {
    return n * (n + 1) / 2;
}

LL bin_serach(LL last, LL a, LL sum, LL k) {
    LL c;
    LL lastMin{};
    while(last + 1 < a) {
        c = (last + a) / 2;
        LL sumAct = summ(c);
        if(sumAct - sum < k) {
            last = c;
            lastMin = c;
        }
        else if(sumAct - sum > k)
            a = c;
        else
            return c;
    }
    return lastMin;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    LL t;
    cin >> t;
    while(t--) {
        LL last{};
        LL n; cin >> n;
        LL k; cin >> k;
        LL a{}, sum{}, sumAll{}, take{};
        bool over = true;
        REP(x, n) {
            cin >> a;
            sum += a;
            sumAll = summ(a);
            if(sumAll - sum < k) 
                take = a - x - 1;
            else if(sumAll - sum == k) {
                over = false;
                take = a - x - 1;
                break;
            }
            else {
                take = bin_serach(last - 1, a, sum, k);
                over = false;
                break;
            }
            last = a;
        }
        if(over) {
            LL take2 = bin_serach(a, 3500000000, sum, k) - n;
            if(take2 > 0) take = take2;
        }

        cout << take << '\n';
    }

    return 0;
}