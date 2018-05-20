#include <iostream>

using namespace std;

#define RESET_IS(is) (is).ignore(numeric_limits<streamsize>::max(), '\n')
#define SETP(p) cout << setprecision(p)

typedef unsigned int uint;
typedef long long ll; typedef unsigned long long ull;

#define INF numeric_limits<int>::max()
#define INFL numeric_limits<ll>::max()

#define MMOD(x, m) ((x) < 0 ? (x) % (m) + (m) : (x) % (m))
#define ABS(x) ((x) < 0 ? -(x) : (x))

#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define REPL(i, a, b) for (ll i = (a); i < (b); ++i)
#define REPA(i, a, b) for (auto i = (a); i < (b); ++i)
#define RREP(i, a, b) for (int i = (b); --i >= (a);)
#define RREPL(i, a, b) for (ll i = (b); --i >= (a);)
#define RREPA(i, a, b) for (auto i = (b); --i >= (a);)

#define INREP(i, a, b) for (int i = (a); i <= (b); ++i)
#define INREPL(i, a, b) for (ll i = (a); i <= (b); ++i)
#define INREPA(i, a, b) for (auto i = (a); i <= (b); ++i)
#define INRREP(i, a, b) for (int i = (b); i >= (a); --i)
#define INRREPL(i, a, b) for (ll i = (b); i >= (a); --i)
#define INRREPA(i, a, b) for (auto i = (b); i >= (a); --i)

#define AREP(v, con) for (auto v : (con))

#define PB push_back
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound

#define SZ(v) ((int) (v).size())
#define ALL(v) (v).begin(), (v).end()

#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())

#define MAXE(v) max_element((v).begin(), (v).end())
#define MINE(v) min_element((v).begin(), (v).end())

bool can_do(int rt, int bt, int k, int m) {
    if (rt < 0 || bt < 0) return false;
    if (k <= 0) return true;
    INREP(i, 1, m) {
        if (can_do(rt - ((i * (i - 1)) / 2), bt - (k - i), k - i, i)) return true;
    }
    return false;
}

bool can_do(int rt, int bt, int k) {
    int m = 1;
    while ((m * (m + 1) / 2) <= rt) ++m;
    return can_do(rt, bt, k + 1, m);
}

void do_test_case() {
    int r, b; cin >> r >> b;
    int ans = 0, fstep = 1;
    while (can_do(r, b, fstep)) fstep *= 2;
    for (int step = fstep; step >= 1; step /= 2) {
        while (can_do(r, b, ans + step)) ans += step;
    }
    cout << ans << "\n";
}

int main() {
    int cases; cin >> cases;
    INREP(n_case, 1, cases) {
        printf("Case #%d: ", n_case);
        do_test_case();
    }
}
