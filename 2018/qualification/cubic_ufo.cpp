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
    printf("Case #%d:\n", n_case);

    double area; cin >> area;

    double x = area / 3 - 1 * sqrt(1.0 / 6 - area * area / 18);
    double y = area / 3 + 2 * sqrt(1.0 / 6 - area * area / 18);

    double mat[3][3] = {
        {(1 + y - x * x) / (1 + y), -x, (-1 * x * x) / (1 + y)},
        {x, (1 + y - 2 * x * x) / (1 + y), x},
        {(-1 * x * x) / (1 + y), -x, (1 + y - x * x) / (1 + y)}
    };

    double faces[3][3] = {
        {mat[0][0] / 2, mat[1][0] / 2, mat[2][0] / 2},
        {mat[0][1] / 2, mat[1][1] / 2, mat[2][1] / 2},
        {mat[0][2] / 2, mat[1][2] / 2, mat[2][2] / 2},
    };

    cout << faces[0][0] << " " << faces[0][1] << " " << faces[0][2] << "\n";
    cout << faces[1][0] << " " << faces[1][1] << " " << faces[1][2] << "\n";
    cout << faces[2][0] << " " << faces[2][1] << " " << faces[2][2] << "\n";
}

int main() {
    SETP(20);
    int cases; cin >> cases;
    INREP(n_case, 1, cases) {
        do_test_case(n_case);
    }
}
