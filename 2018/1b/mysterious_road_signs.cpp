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

#define INF numeric_limits<int>::max()
#define INFL numeric_limits<ll>::max()

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

struct candidate { int curr; int other; int start; int eq; };

void update_candidate(candidate &c, candidate &opp, int idx, int val) {
    if (val == c.curr) ;
    else if (val == opp.other) {
        c.curr = opp.other; c.other = opp.curr; c.start = opp.start; c.eq = idx;
    } else {
        c.curr = val; c.other = opp.curr; c.start = opp.eq; c.eq = idx;
    }
}

void do_test_case() {
    int n; cin >> n;
    vpi sgns(n); AREP(&p, sgns) {
        int s1, s2, s3; cin >> s1 >> s2 >> s3;
        p.F = s1 + s2; p.S = s1 - s3;
    }

    int best = 0, best_c = 0;
    candidate east = {INF, INF, 0, 0}; candidate west = {INF, INF, 0, 0};
    REP(i, 0, n) {
        candidate eastc = east;
        update_candidate(east, west, i, sgns[i].F);
        update_candidate(west, eastc, i, sgns[i].S);
        int best_here = i - min(east.start, west.start) + 1;
        if (best_here > best) {
            best = best_here;
            best_c = 0;
        } if (best_here >= best) ++best_c;
    }

    cout << best << " " << best_c << "\n";
}

int main() {
    int cases; cin >> cases;
    INREP(n_case, 1, cases) {
        printf("Case #%d: ", n_case);
        do_test_case();
    }
}
