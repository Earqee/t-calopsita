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
    ll T, N;
    vct arr(500);
    cin >> T;
    while(T--) {
        cin >> N;
        for(ll i = 0; i < N; i++)
            cin >> arr[i];
        ll dist, min_sum = INT_MAX;
        for(ll i = 0; i < N; i++) {
            ll sum = 0;
            for(ll j = 0; j < N; j++) {
                dist = abs(arr[i] - arr[j]);
                sum += dist;
            }
            min_sum = min(min_sum, sum);
        }
        cout << min_sum << endl;
    }
    return 0;
}

