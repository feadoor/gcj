#include <bits/stdc++.h>

using namespace std;

#define RESET_IS(is) is.ignore(numeric_limits<streamsize>::max(), '\n')
#define SETP(p) cout << setprecision(p)

typedef unsigned int uint;
typedef long long ll; typedef unsigned long long ull;
typedef vector<int> vi; typedef vector<uint> vui;
typedef vector<ll> vll; typedef vector<ull> vull;
typedef vector<double> vd;

typedef pair<int, int> pi; typedef pair<uint, uint> pui;
typedef pair<ll, ll> pll; typedef pair<ull, ull> pull;
typedef pair<double, double> pd;
typedef vector<pll> vpll; typedef vector<pui> vpui;
typedef vector<pll> vpll; typedef vector<pull> vpull;
typedef vector<pd> vpd;

typedef vector<string> vs;

#define MMOD(x, m) ((x) < 0 ? (x) % m + m : (x) % m)

#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define REPL(i, a, b) for (ll i = (a); i < (b); ++i)
#define RREP(i, a, b) for (int i = (b); --i >= (a);)
#define RREPL(i, a, b) for (ll i = (b); --i >= (a);)

#define INREP(i, a, b) for (int i = (a); i <= (b); ++i)
#define INREPL(i, a, b) for (ll i = (a); i <= (b); ++i)
#define INRREP(i, a, b) for (int i = (b); i >= (a); --i)
#define INRREPL(i, a, b) for (ll i = (b); i >= (a); --i)

#define AREP(v, con) for (auto v : con)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound

#define MAXE(v) max_element(v.begin(), v.end())
#define MINE(v) min_element(v.begin(), v.end())

void do_test_case(int n_case) {
    printf("Case #%d: ", n_case);
    int dest, n_horses;
    cin >> dest >> n_horses;

    vd times_taken;
    REP(i, 0, n_horses) {
        double pos, speed;
        cin >> pos >> speed;
        times_taken.PB((dest - pos) / speed);
    }

    double ans = dest / *MAXE(times_taken);
    cout << ans << "\n";
}

int main() {
    SETP(10);
    int cases; cin >> cases;
    INREP(n_case, 1, cases) {
        do_test_case(n_case);
    }
}
