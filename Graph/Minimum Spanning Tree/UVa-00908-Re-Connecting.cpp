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
vct taken;
priority_queue<ii> pq;

void process(ll vertex) {
    taken[vertex] = 1;
    for(ll i = 0; i < graph[vertex].size(); i++) {
        ii current = graph[vertex][i];
        ll weight = current.second;
        ll adj_vertex = current.first;
        if(!taken[adj_vertex]) {
            pq.push(mp(-weight, -adj_vertex));
        }
    }
}

void prim(ll source, ll N) {
    taken.assign(N + 1, 0);
    process(source);

    ll mst_cost = 0;
    while(!pq.empty()) {
        ii current = pq.top(); pq.pop();
        ll weight = -current.first;
        ll vertex = -current.second;
        if(!taken[vertex]) {
            mst_cost += weight;
            process(vertex);
        }
    }
    cout << mst_cost << endl;
}

int main() {
    ll N , K, M;
    ll v1, v2, cost;
    ll source = -1;

    while(cin >> N) {
        if(source != -1)
            cout << endl;
        graph.clear();
        graph.resize(N + 1);
        for(ll i = 0; i < N - 1; i++) {
            cin >> v1 >> v2 >> cost;
            graph[v1].pb(mp(v2, cost));
            graph[v2].pb(mp(v1, cost));
            if(i == 0) source = v1;
        }
        prim(source, N);

        graph.clear();
        graph.resize(N + 1);
        cin >> K;
        for(ll i = 0; i < K; i++) {
            cin >> v1 >> v2 >> cost;
            graph[v1].pb(mp(v2, cost));
            graph[v2].pb(mp(v1, cost));
        }
        cin >> M;
        for(ll i = 0; i < M; i++) {
            cin >> v1 >> v2 >> cost;
            graph[v1].pb(mp(v2, cost));
            graph[v2].pb(mp(v1, cost));
        }
        prim(source, N);
    }
    return 0;
}
