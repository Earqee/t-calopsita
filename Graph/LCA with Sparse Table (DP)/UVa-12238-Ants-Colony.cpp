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

#define MAX (1<<17)

ADL colony(MAX);
vct path, appear(MAX);
vii parent(MAX);

class SparseTable {
private:
public:
    vvct SpT;
    vct Arr;
    SparseTable(ll N, vct &arr) {
        SpT.resize(N), Arr.resize(N);
        for(ll i = 0; i < N; i++) {
            Arr[i] = arr[i];
            SpT[i].resize(log2(N)+1);
            SpT[i][0] = i;
        }
        for(ll j = 1; (1<<j) <= N; j++) {
            for(ll i = 0; i + (1<<j) - 1 < N; i++) {
                if(Arr[SpT[i][j-1]] < Arr[SpT[i+(1<<(j-1))][j-1]])
                    SpT[i][j] = SpT[i][j-1];
                else
                    SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
            }
        }
    }
    ll LCA(ll i, ll j) {
        ll k = log2(j-i+1);
        if(Arr[SpT[i][k]] < Arr[SpT[j-(1<<k)+1][k]])
            return SpT[i][k];
        else
            return SpT[j-(1<<k)+1][k];
    }
};

void eulerTour(ll idx) {
    path.pb(idx);
    appear[idx] = path.size();
    for(ll i=0; i<colony[idx].size(); i++) {
        ii nxt = colony[idx][i];
        parent[nxt.first] = mp(idx, nxt.second);
        if(!appear[nxt.first])
            eulerTour(nxt.first);
        path.pb(idx);
    }
}

ll minDist(ll v1, ll v2, ll stop) {
    ll dist = 0, left = v1, right = v2;
    while(left != stop || right != stop) {
        if(left != stop) {
            dist += parent[left].second;
            left = parent[left].first;
        }
        if(right != stop) {
            dist += parent[right].second;
            right = parent[right].first;
        }
    }
    return dist;
}

int main() {
    ll N, Q, v1, v2, wei;
    while(cin >> N, N != 0) {
        for(ll i = 0; i < N; i++) {
            colony[i].clear();
            appear[i] = 0;
        }
        parent[0] = mp(0, 0);
        path.clear();

        for(ll i=1; i<N;i++) {
            cin >> v2 >> wei;
            colony[v2].pb(mp(i, wei));
        }
        eulerTour(0);
        SparseTable lca(path.size(), path);

        cin >> Q;
        for(ll i=0;i<Q;i++) {
            cin >> v1 >> v2;
            ll r1 = appear[v1]-1, r2 = appear[v2]-1;
            ll stop = lca.LCA(min(r1,r2), max(r1,r2));
            if(i) cout << " ";
            cout << minDist(v1, v2, path[stop]);
        }
        cout << endl;
    }
    return 0;
}
