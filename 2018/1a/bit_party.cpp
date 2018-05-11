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

struct cashier { ll m; ll s; ll p; };

ll capacity(cashier csh, ll time) {
    return max(0LL, min(csh.m, (time - csh.p) / csh.s));
}

bool can_do(ll robots, ll bits, vector<cashier> &cashiers, ll time) {
    vi caps;
    AREP(csh, cashiers) {
        caps.PB(capacity(csh, time));
    }
    RSORT(caps);
    return accumulate(caps.begin(), caps.begin() + min(robots, (ll)caps.SZ()), 0) >= bits;
}

void do_test_case(int n_case) {
    printf("Case #%d: ", n_case);

    ll robots, bits, n_cashiers;
    cin >> robots >> bits >> n_cashiers;
    vector<cashier> cashiers;
    REP(i, 0, n_cashiers) {
        cashier csh; cin >> csh.m >> csh.s >> csh.p;
        cashiers.PB(csh);
    }

    ll time = -1, fstep = 1;
    while (!can_do(robots, bits, cashiers, fstep)) fstep *= 2;
    for (ll step = fstep; step >= 1; step /= 2) {
        while (!can_do(robots, bits, cashiers, time + step)) time += step;
    }

    cout << time + 1 << "\n";
}

int main() {
    int cases; cin >> cases;
    INREP(n_case, 1, cases) {
        do_test_case(n_case);
    }
}
