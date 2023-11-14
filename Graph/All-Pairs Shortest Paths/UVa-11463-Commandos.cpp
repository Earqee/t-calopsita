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
typedef bitset<1 << 8> VL;

vvct min_dist;

void FloydWarshall() {
    for(ll k = 0; k < min_dist.size(); k++)
        for(ll i = 0; i < min_dist.size(); i++)
            for(ll j = 0; j < min_dist.size(); j++)
                    min_dist[i][j] = min(min_dist[i][j], min_dist[i][k] + min_dist[k][j]);
    return;
}

int main() {
    ll T, N, R, v1, v2;
    ll source, dest, max_dist;
    cin >> T;
    for(ll i = 0; i < T; i++) {
        cin >> N;
        min_dist.resize(N);
        for(ll j = 0; j < N; j++)
            min_dist[j].assign(N, INT_MAX);
        cin >> R;
        for(ll j = 0; j < R; j++) {
            cin >> v1 >> v2;
            min_dist[v1][v2] = min_dist[v2][v1] = 1;
        }
       for(ll j = 0; j < N; j++)
            min_dist[j][j] = 0;
        FloydWarshall();
        cin >> source >> dest;
        max_dist = INT_MIN;
        for(ll j = 0; j < N; j++) {
            max_dist = max(max_dist, min_dist[source][j] + min_dist[j][dest]);
        }
        printf("Case %ld: %ld", i+1, max_dist);
        cout << endl;
    }
    return 0;
}

