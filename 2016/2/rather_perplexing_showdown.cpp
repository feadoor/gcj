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

template <typename T> using vec = vector<T>;
template <typename T, typename S> using umap = unordered_map<T, S>;
template <typename T> using uset = unordered_set<T>;

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

struct tournament {
    string lineup;
    int p; int r; int s;
};

vec<vec<tournament>> tournaments;

tournament combine(tournament &t1, tournament &t2) {
    return tournament {t1.lineup + t2.lineup, t1.p + t2.p, t1.r + t2.r, t1.s + t2.s};
}

void generate_tournaments(int rounds) {
    vec<tournament> curr;
    curr.PB(tournament {"P", 1, 0, 0});
    curr.PB(tournament {"R", 0, 1, 0});
    curr.PB(tournament {"S", 0, 0, 1});
    tournaments.PB(curr);

    REP(i, 0, rounds) {
        vec<tournament> next;
        next.PB(combine(curr[0], curr[1]));
        next.PB(combine(curr[0], curr[2]));
        next.PB(combine(curr[1], curr[2]));
        tournaments.PB(next); curr = next;
    }
}

void do_test_case() {
    int n, r, p, s; cin >> n >> r >> p >> s;
    AREP(t, tournaments[n]) {
        if (t.p == p && t.r == r && t.s == s) {
            cout << t.lineup << "\n";
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    int cases; cin >> cases;
    generate_tournaments(12);
    INREP(n_case, 1, cases) {
        printf("Case #%d: ", n_case);
        do_test_case();
    }
}
