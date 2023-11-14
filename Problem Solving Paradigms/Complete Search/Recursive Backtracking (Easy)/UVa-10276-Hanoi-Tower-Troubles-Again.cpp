#include <bits/stdc++.h>

#define pb push_back
#define pp pop_back
#define mp make_pair
#define lwb lower_bound
#define upb upper_bound
#define all(E) E.begin(), E.end()
#define e_min min_element
#define e_max max_element
#define bin_s binary_search
#define ff find

using namespace std;
typedef int ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

vvct stk;

bool square(ll N) {
    double sqrtN = sqrt(N);
    if(abs((ll)sqrtN - sqrtN) < 1e-5)
        return true;
    return false;
}

ll solve(ll k, ll cur) {
    for(ll i=0; i<k; i++) {
        if(stk[i].size()) {
            if(square(stk[i].back() + cur)) {
                stk[i].pb(cur);
                return solve(k, cur+1);
            }
        } else {
            stk[i].pb(cur);
            return solve(k, cur+1);
        }
    }
    return cur-1;
}

int main() {
    ll T, N;
    cin >> T;
    while(T--) {
        cin >> N;
        stk.resize(N);
        for(ll i=0; i<N; i++)
            stk[i].clear();
        cout << solve(N, 1) << endl;
    }
    return 0;
}
