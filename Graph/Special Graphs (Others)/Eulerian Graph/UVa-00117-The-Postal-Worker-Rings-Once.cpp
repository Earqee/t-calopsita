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
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

#define MAXX ('z'-'a'+1)
#define INF (1e6)

ADL graph;
ll stringSum;

ll SPFA(ll source, ll dest) {
    vct dist(MAXX, INF);
    vct in_queue(MAXX, 0);
    queue<ll> quu;

    quu.push(source);
    dist[source] = 0;

    while(!quu.empty()) {
        ll vertex = quu.front(); quu.pop();
        in_queue[vertex] = false;
        for(ll i = 0; i < graph[vertex].size(); i++) {
            ii next = graph[vertex][i];
            ll adj_vertex = next.first;
            ll weight = next.second;
            if(dist[adj_vertex] > dist[vertex] + weight) {
                dist[adj_vertex] = dist[vertex] + weight;
                if(!in_queue[adj_vertex]) {
                    in_queue[adj_vertex] = true;
                    quu.push(adj_vertex);
                }
            }

        }
    }
    return dist[dest];
}

void insertGraph(string &input) {
        ll u = input[0] - 'a';
        ll v = input[input.size() - 1] - 'a';
        graph[u].pb(mp(v, input.size()));
        graph[v].pb(mp(u, input.size()));
        stringSum += input.size();
}

int main() {
    string input;
    while(cin >> input, input != "deadend") {
        graph.clear();
        graph.resize(MAXX);
        stringSum = 0;
        insertGraph(input);
        while(cin >> input, input != "deadend")
            insertGraph(input);
        ll frt_odd = -1, scd_odd = -1;
        for(ll i = 0; i < graph.size(); i++) {
            if(graph[i].size() % 2) {
                if(frt_odd == -1) frt_odd = i;
                else if(scd_odd == -1) scd_odd = i;
            }
        }
        if(frt_odd == -1 && scd_odd == -1)
            cout << stringSum;
        else cout << stringSum + SPFA(frt_odd, scd_odd);
        cout << endl;
    }
    return 0;
}


