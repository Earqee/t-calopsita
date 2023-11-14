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

ll T, N, arr[30];
map<vct, bool> vis;

void mount(vct &res, ll sum, ll pos) {
    if(sum == T) {
        if(vis[res])
            return;
        vis[res] = 1;
        for(ll i=0; i<res.size();i++) {
            if(i) cout << "+";
            cout << res[i];
        }
        cout << endl;
        return;
    }
    if(sum > T || pos == N)
        return;
    res.pb(arr[pos]);
    mount(res, sum+arr[pos], pos+1);
    res.pp();
    mount(res, sum, pos+1);
}

int main() {
    ll num;
    while(cin >> T >> N, N != 0) {
        for(ll i=0; i<N; i++) {
            cin >> num;
            arr[i]= num;
        }
        vct res;
        printf("Sums of %lld:\n", T);
        mount(res, 0, 0);
        if(!vis.size())
            cout << "NONE" << endl;
        vis.clear();
    }
    return 0;
}

