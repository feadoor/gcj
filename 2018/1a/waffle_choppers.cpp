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

    int w, h, ch, cv; cin >> w >> h >> ch >> cv;
    vector<vb> chips(w, vb(h, false)); int tot_chips = 0;
    REP(i, 0, w) {
        string row; cin >> row;
        REP(j, 0, h) {
            chips[i][j] = row[j] == '@';
            if (chips[i][j]) ++tot_chips;
        }
    }

    vi hcuts(1, 0); int hsum = 0; int currh = 1;
    REP(i, 0, w) {
        REP(j, 0, h) {
            if (chips[i][j]) ++hsum;
        }
        if (hsum * (ch + 1) == tot_chips * currh) {
            hcuts.PB(i + 1);
            ++currh;
        }
        if (currh > ch + 1) break;
    }

    vi vcuts(1, 0); int vsum = 0; int currv = 1;
    REP(j, 0, h) {
        REP(i, 0, w) {
            if (chips[i][j]) ++vsum;
        }
        if (vsum * (cv + 1) == tot_chips * currv) {
            vcuts.PB(j + 1);
            ++currv;
        }
        if (currv > cv + 1) break;
    }

    if (hcuts.SZ() != (ch + 2) || vcuts.SZ() != (cv + 2)) {
        cout << "IMPOSSIBLE" << "\n";
        return;
    }

    REP(i, 0, ch + 1) {
        REP(j, 0, cv + 1) {
            int cnt = 0;
            REP(x, hcuts[i], hcuts[i + 1]) {
                REP(y, vcuts[j], vcuts[j + 1]) {
                    if (chips[x][y]) ++cnt;
                }
            }
            if (cnt * (ch + 1) * (cv + 1) != tot_chips) {
                cout << "IMPOSSIBLE" << "\n";
                return;
            }
        }
    }

    cout << "POSSIBLE" << "\n";
}

int main() {
    int cases; cin >> cases;
    INREP(n_case, 1, cases) {
        do_test_case(n_case);
    }
}
