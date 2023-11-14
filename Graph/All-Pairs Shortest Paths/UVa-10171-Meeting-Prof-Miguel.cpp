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
typedef long int ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

#define MAXX ('Z'- 'A' + 1)

vvct min_M, min_Y;
vct ans;

void FW() {
    for(ll i = 0; i < MAXX; i++)
        min_M[i][i] = min_Y[i][i] = 0;
    for(ll k = 0; k < MAXX; k++) {
        for(ll i = 0; i < MAXX; i++) {
            for(ll j = 0; j < MAXX; j++) {
                min_Y[i][j] = min(min_Y[i][j], min_Y[i][k] + min_Y[k][j]);
                min_M[i][j] = min(min_M[i][j], min_M[i][k] + min_M[k][j]);
            }
        }
    }
    return;
}

int main() {
    ll N, u, v, cost = -1;
    char age, dir, v1, v2;
    while(cin >> N, N != 0) {
        //Alloc
        min_Y.resize(MAXX), min_M.resize(MAXX), ans.clear();
        for(ll i = 0; i < MAXX; i++) {
            min_Y[i].assign(MAXX, 1e4);
            min_M[i].assign(MAXX, 1e4);
        }
        //Read
        for(ll i = 0; i < N; i++) {
            cin >> age >> dir >> v1 >> v2 >> cost;
            u = v1-'A', v = v2-'A';
            if(age == 'Y') {
                min_Y[u][v] = min(min_Y[u][v], cost);
                if(dir == 'B') min_Y[v][u] = min(min_Y[v][u], cost);
            }
            if(age == 'M') {
                min_M[u][v] = min(min_M[u][v], cost);
                if(dir == 'B') min_M[v][u] = min(min_M[v][u], cost);
            }
        }
        //Compute
        FW();
        //Answer queries
        cin >> v1 >> v2;
        u = v1-'A', v = v2-'A';
        ll best = 1e4;
        for(ll i = 0; i < MAXX; i++)
            best = min(best, min_Y[u][i] + min_M[v][i]);
        if(best != 1e4) {
            cout << best;
            for(ll i = 0; i < MAXX; i++)
                if(best == min_Y[u][i] + min_M[v][i])
                    ans.pb(i);
            sort(ans.begin(), ans.end());
            for(ll i = 0; i < ans.size(); i++)
                cout << ' ' << (char)(ans[i] + 'A');
        } else printf("You will never meet.");
        cout << endl;
    }
    return 0;
}

