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

ADL graph;
vct travel;

bool bellman_ford(ll source) {
    travel[source] = 0;
    for(ll k = 0; k < graph.size() - 1; k++) {
        for(ll i = 0; i < graph.size(); i++) {
            for(ll j = 0; j < graph[i].size(); j++) {
                ii current = graph[i][j];
                ll weight = current.second;
                ll adj_vertex = current.first;
                travel[adj_vertex] = min(travel[adj_vertex], travel[i] + weight);
            }
        }
    }

    for(ll i = 0; i < graph.size(); i++) {
        for(ll j = 0; j < graph[i].size(); j++) {
            ii current = graph[i][j];
            ll weight = current.second;
            ll adj_vertex = current.first;
            if(travel[adj_vertex] > travel[i] + weight)
                return true;
        }
    }
    return false;
}

int main() {
    ll C, N, M;
    ll v1, v2, time;
    cin >> C;
    for(ll i = 0; i < C; i++) {
        cin >> N >> M;

        graph.clear();
        graph.resize(N);
        travel.assign(N, INT_MAX);

        for(ll j = 0; j < M; j++) {
            cin >> v1 >> v2 >> time;
            graph[v1].pb(mp(v2, time));
        }
        if(!bellman_ford(0)) cout << "not ";
            cout << "possible" << endl;
    }
    return 0;
}

