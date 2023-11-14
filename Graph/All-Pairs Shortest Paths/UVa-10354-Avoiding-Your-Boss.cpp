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

vvct min_d, backup;
vct can_visit;

void FW(ll S, vvct &req) {
    for(ll k = 1; k <= S; k++) {
        if(can_visit[k])
        for(ll i = 1; i <= S; i++) {
            if(can_visit[i])
            for(ll j = 1; j <= S; j++) {
                if(can_visit[j])
                req[i][j] = min(req[i][j], req[i][k] + req[k][j]);
            }
        }
    }
    return;
}

int main() {
    ll P, R, BH, OF, YH, M;
    ll v1, v2, cost;
    while(cin >> P >> R >> BH >> OF >> YH >> M) {
        min_d.resize(P+1);
        backup.resize(P+1);
        can_visit.assign(P+1, 1);
        for(ll i = 0; i < P+1; i++) {
            min_d[i].assign(P+1, 1e6);
            backup[i].assign(P+1, 1e6);
            min_d[i][i] = backup[i][i] = 0;
        }
        for(ll i = 1; i <= R; i++) {
            cin >> v1 >> v2 >> cost;
            min_d[v1][v2] = min_d[v2][v1] = backup[v1][v2] = backup[v2][v1] = cost;
        }
        FW(P, min_d);
        for(ll i = 1; i <= P; i++)
            if(min_d[BH][OF] == min_d[BH][i] + min_d[i][OF])
                can_visit[i] = 0, backup[i][i] = 1e6;
        FW(P, backup);
        if(backup[YH][M] == 1e6 || !can_visit[YH] || !can_visit[M])
            cout << "MISSION IMPOSSIBLE.";
        else cout << backup[YH][M];
        cout << endl;
    }
    return 0;
}

