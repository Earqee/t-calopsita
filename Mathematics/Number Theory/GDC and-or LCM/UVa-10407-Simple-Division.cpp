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

ll gdc(ll a, ll b) {return b==0? a:gdc(b, a%b);}
ll lcm(ll a, ll b) {return a*(b/gdc(a, b));}

vct diff, gdci;

int main() {
    ll N;
    while(cin >> N, N != 0) {
        diff.clear(), gdci.clear();
        ll last = N;
        while(cin >> N, N != 0) {
            diff.pb(abs(N - last));
            last = N;
        }
        gdci.resize(diff.size());
        gdci[0] = diff[0];
        for(ll i = 0; i < diff.size()-1; i++)
            gdci[i+1] = gdc(gdci[i], diff[i+1]);
        cout << gdci[diff.size()-1] << endl;
    }
    return 0;
}
