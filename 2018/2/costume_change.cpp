#include <iostream>
#include <vector>

using namespace std;

#define RESET_IS(is) (is).ignore(numeric_limits<streamsize>::max(), '\n')
#define SETP(p) cout << setprecision(p)

typedef unsigned int uint;
typedef long long ll; typedef unsigned long long ull;
typedef vector<int> vi; typedef vector<uint> vui;
typedef vector<ll> vll; typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<double> vd;

typedef pair<int, int> pi; typedef pair<uint, uint> pui;
typedef pair<ll, ll> pll; typedef pair<ull, ull> pull;
typedef pair<double, double> pd;
typedef vector<pi> vpi; typedef vector<pui> vpui;
typedef vector<pll> vpll; typedef vector<pull> vpull;
typedef vector<pd> vpd;

template <typename T> using vec = vector<T>;

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

bool find_match(vec<vi> &bgraph, int i, vb &seen, vi &match) {
    AREP(j, bgraph[i]) if (!seen[j]) {
        seen[j] = true;
        if (match[j] == -1 || find_match(bgraph, match[j], seen, match)) {
            match[j] = i;
            return true;
        }
    }
    return false;
}

int max_match(vec<vi> &bgraph) {
    int n = SZ(bgraph); int ms = 0; vi match(n, -1);
    REP(i, 0, n) {
        vb seen(n, false);
        if (find_match(bgraph, i, seen, match)) ++ms;
    }
    return ms;
}

void do_test_case() {
    int n; cin >> n;
    vec<vi> grid(n, vi(n, 0));
    REP(i, 0, n) REP(j, 0, n) cin >> grid[i][j];

    int ans = n * n;
    INREP(k, -n, n) {
        vec<vi> bgraph(n);
        REP(i, 0, n) REP(j, 0, n) if (grid[i][j] == k) bgraph[i].PB(j);
        ans -= max_match(bgraph);
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
