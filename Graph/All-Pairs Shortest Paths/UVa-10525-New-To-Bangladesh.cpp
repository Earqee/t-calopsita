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
typedef vector<vct> vvct;
typedef vector <vvct> vvvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

vvct min_d, path;

void FW() {
    for(ll i = 0; i < min_d.size(); i++)
        min_d[i][i] = path[i][i] = 0;
    for(ll k = 0; k < min_d.size(); k++) {
        for(ll i = 0; i < min_d.size(); i++) {
            for(ll j = 0; j < min_d.size(); j++) {
                if(min_d[i][j] > min_d[i][k] + min_d[k][j] ||
                        (min_d[i][j] == min_d[i][k] + min_d[k][j] &&
                        path[i][j] > path[i][k] + path[k][j])) {
                    min_d[i][j] = min_d[i][k] + min_d[k][j];
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }
}

int main() {
    ll T, Q, X, Y, v1, v2, time, length;
    cin >> T;
    while(T--) {
        cin >> X >> Y;
        min_d.resize(X);
        path.resize(X);
        for(ll i = 0; i < X; i++) {
            min_d[i].assign(X, 1e6);
            path[i].assign(X, 1e6);
        }
        for(ll i = 0; i < Y; i++) {
            cin >> v1 >> v2 >> time >> length;
            ll u = v1-1, v = v2-1;
            if(time < min_d[u][v] || (time == min_d[u][v] && length < path[u][v])) {
                min_d[u][v] = min_d[v][u] = time;
                path[u][v] = length; path[v][u] = length;
            }
        }
        FW();
        cin >> Q;
        for(ll i = 0; i < Q; i++) {
            cin >> v1 >> v2;
            ll u = v1-1, v = v2-1;
            if(min_d[u][v] != 1e6)
                printf("Distance and time to reach destination is %ld & %ld.",
                        path[u][v], min_d[u][v]);
            else cout << "No Path.";
            cout << endl;
        }
        if(T) cout << endl;
    }
    return 0;
}

