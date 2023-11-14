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
priority_queue<ll> cycle_w;

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

void prim(ll source) {
    process(source);
    while(!pq.empty()) {
        ii current = pq.top(); pq.pop();
        ll weight = -current.first;
        ll vertex = -current.second;
        if(!taken[vertex]) {
            process(vertex);
        } else {
            cycle_w.push(-weight);
        }
    }
    return;
}

int main() {
    ll N, M;
    ll v1, v2, cost, source;

    while(cin >> N >> M, N != 0 || M != 0) {
        graph.clear();
        graph.resize(N + 1);
        taken.assign(N + 1, 0);

        for(ll i = 0; i < M; i++) {
            cin >> v1 >> v2 >> cost;
            graph[v1].pb(mp(v2, cost));
            graph[v2].pb(mp(v1, cost));
        }
        if(M) {
            for(ll i = 1; i <= N; i++) {
                if(!taken[i])
                    prim(i);
            }
            if(cycle_w.size()) {
                ll k = 0;
                while(cycle_w.size()) {
                    if(k) cout << " ";
                    ll weight = -cycle_w.top(); cycle_w.pop();
                    cout << weight;
                    k = 1;
                }
            } else {
                cout << "forest";
            }
        } else {
            cout << "forest";
        }
        cout << endl;
    }
    return 0;
}
