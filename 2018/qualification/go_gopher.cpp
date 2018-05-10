#include <bits/stdc++.h>

using namespace std;

#define RESET_IS(is) (is).ignore(numeric_limits<streamsize>::max(), '\n')
#define SETP(p) cout << setprecision(p)

typedef unsigned int uint;
typedef long long ll; typedef unsigned long long ull;
typedef vector<int> vi; typedef vector<uint> vui;
typedef vector<ll> vll; typedef vector<ull> vull;
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
#define SZ size
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound

#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())

#define MAXE(v) max_element((v).begin(), (v).end())
#define MINE(v) min_element((v).begin(), (v).end())

pi dimensions(int area) {
    REP(w, 3, 15) {
        if (w * w <= area && area < (w + 1) * (w + 1)) {
            if (w * (w + 1) < area) return MP(w, w + 2);
            else if (w * w < area) return MP(w, w + 1);
            else return MP(w, w);
        }
    }
}

pi best_sq(vector<vector<bool>> &orchard) {
    int bestc = -1;
    pi best = {0, 0};
    REP(i, 1, orchard.SZ() - 1) {
        REP(j, 1, orchard[i].SZ() - 1) {
            int cnt = 0;
            vpi nbrs = {{i, j}, {i - 1, j}, {i - 1, j - 1}, {i, j - 1}, {i + 1, j - 1}, {i + 1, j}, {i + 1, j + 1}, {i, j + 1}, {i - 1, j + 1}};
            AREP(n, nbrs) {
                if (!orchard[n.F][n.S]) ++cnt;
            }
            if (cnt > bestc) {
                bestc = cnt; best = MP(i, j);
            }
        }
    }
    return best;
}

void do_test_case(int n_case) {
    int area; cin >> area;
    int w, h; pi dims = dimensions(area); w = dims.F; h = dims.S;
    vector<vector<bool>> orchard(w, vector<bool>(h, false));

    while (true) {
        pi sq = best_sq(orchard);
        cout << sq.F + 1 << " " << sq.S + 1 << endl;
        int inx, iny; cin >> inx >> iny;
        if (inx == -1 && iny == -1) exit(1);
        else if (inx == 0 && iny == 0) return;
        else orchard[inx - 1][iny - 1] = true;
    }
}

int main() {
    int cases; cin >> cases;
    INREP(n_case, 1, cases) {
        do_test_case(n_case);
    }
}
