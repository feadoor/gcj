#include <bits/stdc++.h>

using namespace std;

#define RESET_IS(is) (is).ignore(numeric_limits<streamsize>::max(), '\n')
#define SETP(p) cout << setprecision(p)

typedef unsigned int uint;
typedef long long ll; typedef unsigned long long ull;
typedef vector<int> vi; typedef vector<uint> vui;
typedef vector<ll> vll; typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;

typedef pair<int, int> pi; typedef pair<uint, uint> pui;
typedef pair<ll, ll> pll; typedef pair<ull, ull> pull;
typedef pair<double, double> pd;
typedef vector<pi> vpi; typedef vector<pui> vpui;
typedef vector<pll> vpll; typedef vector<pull> vpull;
typedef vector<pd> vpd;

typedef vector<string> vs;

#define MMOD(x, m) ((x) < 0 ? (x) % (m) + (m) : (x) % (m))

#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define REPL(i, a, b) for (ll i = (a); i < (b); ++i)
#define RREP(i, a, b) for (int i = (b); --i >= (a);)
#define RREPL(i, a, b) for (ll i = (b); --i >= (a);)

#define INREP(i, a, b) for (int i = (a); i <= (b); ++i)
#define INREPL(i, a, b) for (ll i = (a); i <= (b); ++i)
#define INRREP(i, a, b) for (int i = (b); i >= (a); --i)
#define INRREPL(i, a, b) for (ll i = (b); i >= (a); --i)

#define AREP(v, con) for (auto v : (con))

#define PB push_back
#define MP make_pair
#define MT make_tuple
#define SZ size
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound

#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())

#define MAXE(v) max_element((v).begin(), (v).end())
#define MINE(v) min_element((v).begin(), (v).end())

void do_test_case(int n_case) {
    printf("Case #%d: ", n_case);

    int ncookies, p; cin >> ncookies >> p;
    vpi cookies; REP(i, 0, ncookies) {
        int w, h; cin >> w >> h;
        cookies.PB(MP(w, h));
    }

    double base_p = 0, max_excess = 0; AREP(c, cookies) {
        base_p += 2 * (c.F + c.S);
        max_excess += sqrt(c.F * c.F + c.S * c.S);
    }
    double excess = (p - base_p) / 2;

    double best_excess = 0;
    if (max_excess <= excess) {
        best_excess = max_excess;
    } else {
        vd ranges((int)floor(excess) + 1, 0);
        AREP(c, cookies) {
            int min_cut = min(c.F, c.S); double max_cut = sqrt(c.F * c.F + c.S * c.S);
            RREP(i, min_cut, ranges.SZ()) {
                ranges[i] = max(ranges[i], ranges[i  - min_cut] + max_cut);
            }
        }
        AREP(e, ranges) {
            best_excess = max(best_excess, min(excess, e));
        }
    }

    double best_p = base_p + 2 * best_excess;
    cout << best_p << "\n";
}

int main() {
    SETP(15);
    int cases; cin >> cases;
    INREP(n_case, 1, cases) {
        do_test_case(n_case);
    }
}
