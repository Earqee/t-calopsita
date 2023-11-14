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
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

int main() {
    ll T, R, C;
    vector<string> shop;
    cin >> T;
    for(ll i = 1; i <= T; i++) {
        cin >> R >> C;
        shop.resize(R);
        for(ll j = 0; j < R; j++)
            cin >> shop[j];
        ll best = 1<<20;
        for(ll k = 0; k < C; k++) {
            ll total_mov = 0;
            for(ll j = 0; j < R; j++) {
                if(shop[j][k] == '1') {
                    ll min_mov = 1<<20;
                    for(ll r = k+1; r < C; r++) {
                        if(shop[j][r] == '0') {
                            min_mov = min(min_mov, r - k);
                            break;
                        }
                    }
                    for(ll r = k-1; r >= 0; r--) {
                        if(shop[j][r] == '0') {
                            min_mov = min(min_mov, k - r);
                            break;
                        }
                    }
                    total_mov += min_mov;
                }
            }
            best = min(best, total_mov);
        }
        printf("Case %lld: %lld\n", i, best >= 1<<20 ? -1 : best);
    }

}
