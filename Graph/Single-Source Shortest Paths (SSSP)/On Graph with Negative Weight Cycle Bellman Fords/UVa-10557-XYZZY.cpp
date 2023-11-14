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

vvct graph;
vct energy, max_energy;
VL visited;

bool isReachable(ll source, ll dest) {
    visited[source] = 1;
    queue<ll> quu; quu.push(source);
    while(!quu.empty()) {
        ll current = quu.front(); quu.pop();
        if(current == dest) {
            while(!quu.empty()) quu.pop();
            return true;
        }
        for(ll i = 0; i < graph[current].size(); i++) {
            ll next = graph[current][i];
            if(!visited[next]) {
                visited[next] = 1;
                quu.push(next);
            }
        }
    }
    return false;
}

bool isPossible() {
    visited.reset();
    if(!isReachable(0, graph.size() - 1))
        return false;
    //Bellman Ford
    for(ll k = 0; k < graph.size() - 1; k++) {
        for(ll i = 0; i < graph.size(); i++) {
            for(ll j = 0; j < graph[i].size(); j++) {
                ll adj_vertex = graph[i][j];
                ll weight = max_energy[i] + energy[adj_vertex];
                if(weight < 0)
                    max_energy[adj_vertex] = min(max_energy[adj_vertex], weight);
            }
        }
    }
    visited.reset();
    //Check positive cycle
    for(ll i = 0; i < graph.size(); i++) {
        for(ll j = 0; j < graph[i].size(); j++) {
            ll adj_vertex = graph[i][j];
            ll weight = max_energy[i] + energy[adj_vertex];
            if(weight < 0 && max_energy[adj_vertex] > weight &&
                    !visited[adj_vertex] && isReachable(adj_vertex, graph.size() - 1)) {
                return true;
            }
        }
    }
    //If not
    if(max_energy[graph.size() - 1] < 0)
        return true;
    return false;
}

int main() {
    ll N, edges, next;
    while(cin >> N, N != -1) {
        graph.clear();
        graph.resize(N);
        energy.resize(N);
        max_energy.assign(N, INT_MAX);

        for(ll i = 0; i < N; i++) {
            cin >> energy[i] >> edges;
            energy[i] = (-1)*energy[i];
            if(!i) max_energy[i] = -100;
            for(ll j = 0; j < edges; j++) {
                cin >> next;
                graph[i].pb(--next);
            }
        }
        if(isPossible())
            cout << "winnable";
        else cout << "hopeless";
        cout << endl;
    }
    return 0;
}
