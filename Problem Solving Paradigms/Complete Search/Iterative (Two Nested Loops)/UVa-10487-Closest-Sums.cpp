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
    ll N, Q, query, cases = 1;
    vct arr(1010);
    while(cin >> N, N != 0) {
        for(ll i = 0; i < N; i++)
            cin >> arr[i];
        ll sum;
        vct comb;
        for(ll i = 0; i < N; i++) {
            for(ll j = 0; j < N; j++) {
                if(i != j) {
                    sum = arr[i] + arr[j];
                    comb.pb(sum);
                }
            }
        }
        sort(all(comb));
        cin >> Q;
        printf("Case %lld:\n", cases++);
        while(Q--) {
            cin >> query;
            ll lwbo = lwb(all(comb), query) - comb.begin();
            if(lwbo > 0) {
                if(lwbo == comb.size())
                    printf("Closest sum to %lld is %lld.", query,
                            comb[lwbo-1]);
                else
                    printf("Closest sum to %lld is %lld.", query,
                        abs(comb[lwbo] - query) < abs(comb[lwbo-1] - query) ?
                        comb[lwbo] : comb[lwbo-1]);
            } else {
                printf("Closest sum to %lld is %lld.", query, comb[lwbo]);
            }
            cout << endl;
        }
    }
    return 0;
}
