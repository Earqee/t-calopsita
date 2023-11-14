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
typedef unsigned long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

int main() {
    ll li, hi, ri, max_x = 0;
    vct skyline(10010, 0);
    while(cin >> li >> hi >> ri) {
        max_x = max(max_x, ri);
        for(ll i = li; i < ri; i++)
            skyline[i] = max(skyline[i], hi);
    }
    for(ll i = 1; i <= max_x + 1; i++) {
        if(skyline[i] != skyline[i-1]) {
            if(i != 1) cout << " ";
            printf("%lld %lld", i, skyline[i]);
        }
    }
    cout << endl;
    return 0;
}
