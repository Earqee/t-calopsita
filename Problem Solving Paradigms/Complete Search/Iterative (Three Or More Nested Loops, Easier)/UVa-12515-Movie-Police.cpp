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
    ll M, Q;
    vector<string> clip;
    vector<string> data;

    cin >> M >> Q;
    data.resize(M);
    clip.resize(Q);
    for(ll i = 0; i < M; i++)
        cin >> data[i];
    for(ll i = 0; i < Q; i++)
        cin >> clip[i];
    for(ll i = 0; i < Q; i++) {
        ll best_sim = INT_MAX, similar = INT_MAX, idx;
        for(ll j = 0; j < M; j++) {
            for(ll k = 0; k+clip[i].size()-1 < data[j].size(); k++) {
                ll ham_dist = clip[i].size();
                for(ll r = 0; r < clip[i].size(); r++)
                    ham_dist -= (clip[i][r] == data[j][k+r]);
                similar = min(similar, ham_dist);
            }
            if(similar < best_sim) {
                best_sim = similar;
                idx = j+1;
            }
        }
        cout << idx << endl;
    }
    return 0;
}
