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
    vii one, three;
    ll N; char input;

    while(scanf("%lld ", &N) != EOF) {
        ll max_dist = INT_MIN;
        one.clear(), three.clear();
        for(ll i = 0; i < N; i++) {
            for(ll j = 0; j < N; j++) {
                cin >> input;
                if(input == '1')
                    one.pb(mp(i, j));
                if(input == '3')
                    three.pb(mp(i, j));
            }
        }
        for(ll i = 0; i < one.size(); i++) {
            ll min_dist = INT_MAX;
            for(ll j = 0; j < three.size(); j++) {
                min_dist = min(min_dist, abs(one[i].first-three[j].first)  +
                        abs(one[i].second-three[j].second));
            }
            max_dist = max(max_dist, min_dist);
        }
        cout << max_dist << endl;
    }
    return 0;
}

