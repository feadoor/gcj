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

int find_debt(vll &supplies) {
    REP(i, 0, SZ(supplies)) {
        if (supplies[i] < 0) return i;
    }
    return -1;
}

bool do_payoff(vector<vll> &recipes, vll &supplies, int idx) {
    if (recipes[idx][idx] > 0) return false;

    int sz = SZ(supplies);

    REP(i, 0, sz) {
        supplies[i] += recipes[idx][i] * supplies[idx];
    }

    AREP(&r, recipes) {
        if (r[idx] > 0) {
            REP(i, 0, sz) {
                r[i] += recipes[idx][i] * r[idx];
            }
            r[idx] = 0;
        }
    }

    supplies[idx] = 0; return true;
}

bool can_do(ll amt, vll supplies, vector<vll> recipes) {
    supplies[0] -= amt; int idx;
    while ((idx = find_debt(supplies)) != -1) {
        if (!do_payoff(recipes, supplies, idx)) return false;
    }
    return true;
}

ll maximum_lead(vll &supplies, vector<vll> &recipes) {
    ll amt = -1, fstep = 1;
    while (can_do(fstep, supplies, recipes)) fstep *= 2;
    for (ll step = fstep; step >= 1; step /= 2) {
        while (can_do(amt + step, supplies, recipes)) amt += step;
    }
    return amt;
}

void do_test_case() {
    int sz; cin >> sz;
    vll supplies(sz); vector<vll> recipes(sz, vector<ll>(sz));
    REP(i, 0, sz) {
        int a, b; cin >> a >> b;
        recipes[i][a - 1] = recipes[i][b - 1] = 1;
    }
    AREP(&s, supplies) cin >> s;
    cout << maximum_lead(supplies, recipes) << "\n";
}

int main() {
    int cases; cin >> cases;
    INREP(n_case, 1, cases) {
        printf("Case #%d: ", n_case);
        do_test_case();
    }
}
