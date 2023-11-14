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
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

#define INV -1

ADL graph;
map<string, ll> hashm;
vvct min_cost;
vvct visited;

void dpSPFA() {
    min_cost[0][0] = 0;

    queue<ii> quu;
    quu.push(mp(0, 0));
    while(!quu.empty()) {
        ii current = quu.front(); quu.pop();
        ll vertex = current.second;
        ll depth = current.first;
        visited[vertex][depth] = 0;
        for(ll i = 0; i < graph[vertex].size(); i++) {
            ii next = graph[vertex][i];
            ll weight = next.second;
            ll adj_vertex = next.first;
            min_cost[adj_vertex][depth + 1] = min(min_cost[adj_vertex][depth + 1],
                    min_cost[vertex][depth] + weight);
            if(depth + 1 < graph.size() && !visited[adj_vertex][depth + 1]) {
                visited[adj_vertex][depth + 1] = 1;
                quu.push(mp(depth + 1, adj_vertex));
            }
        }
    }

    return;
}

int main() {
    ll C, N, M, Q, cost, query;
    string dep, dest;

    cin >> C;
    for(ll i = 0; i < C; i++) {
        if(i) cout << endl;
        cin >> N;
        graph.clear();
        graph.resize(N);
        for(ll j = 0; j < N; j++) {
            cin >> dep;
            hashm[dep] = j;
        }
        cin >> M;
        for(ll j = 0; j < M; j++) {
            cin >> dep >> dest >> cost;
            graph[hashm[dep]].pb(mp(hashm[dest], cost));
        }

        min_cost.resize(N);
        visited.resize(N);
        for(ll j = 0; j < N; j++) {
            min_cost[j].assign(N, INT_MAX);
            visited[j].assign(N, 0);
        }

        dpSPFA();
        cin >> Q;
        cout << "Scenario #" << i + 1 << endl;
        while(Q--) {
            cin >> query;
            ll ans = INT_MAX;
            if(query >= graph.size() - 1)
                query = graph.size() - 2;
            for(ll i = 0; i <= query + 1; i++)
                ans = min(ans, min_cost[N-1][i]);
            if(ans != INT_MAX)
                cout << "Total cost of flight(s) is $" << ans;
            else cout << "No satisfactory flights";
            cout << endl;
        }
    }
    return 0;

}

