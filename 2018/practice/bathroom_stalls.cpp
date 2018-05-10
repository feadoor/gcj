#include <bits/stdc++.h>

using namespace std;

#define RESET_IS(is) is.ignore(numeric_limits<streamsize>::max(), '\n')

typedef unsigned int uint;
typedef long long ll; typedef unsigned long long ull;
typedef vector<int> vi; typedef vector<uint> vui;
typedef vector<ll> vll; typedef vector<ull> vull;

typedef pair<int, int> pi; typedef pair<uint, uint> pui;
typedef pair<ll, ll> pll; typedef pair<ull, ull> pull;
typedef vector<pll> vpll; typedef vector<pui> vpui;
typedef vector<pll> vpll; typedef vector<pull> vpull;

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

ll last_gap_size(ll stalls, ll people) {
    map<ll, ll> gaps;
    gaps[stalls] = 1;

    ll so_far = 0;
    while (true) {
        auto lgap = *--gaps.end();
        so_far += lgap.S;
        if (so_far >= people) return lgap.F;

        gaps.erase(--gaps.end());
        gaps[lgap.F / 2] += lgap.S;
        gaps[(lgap.F - 1) / 2] += lgap.S;
    }
}

void do_test_case(int n_case) {
    printf("Case #%d: ", n_case);
    ll stalls, people;
    cin >> stalls >> people;
    ll gap = last_gap_size(stalls, people);
    cout << gap / 2 << " " << (gap - 1) / 2 << "\n";
}

int main() {
    int cases; cin >> cases;
    INREP(n_case, 1, cases) {
        do_test_case(n_case);
    }
}
