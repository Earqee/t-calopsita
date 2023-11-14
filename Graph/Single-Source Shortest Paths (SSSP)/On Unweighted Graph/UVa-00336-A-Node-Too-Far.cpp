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


int bfs(int S, int TTL, map<int, vector<int> > &network) {
    map <int, bool> visited;
    map <int, int> dist;
    queue<int> quu;

    int cur, v, num_conn;
    visited[S] = 1;
    dist[S] = num_conn = 0;
    quu.push(S);

    while(!quu.empty()) {
        cur = quu.front(); quu.pop();
        if(dist[cur] <= TTL)
            num_conn++;
        for(int i = 0; i < network[cur].size(); i++) {
            v = network[cur][i];
            if(!visited[v]) {
                visited[v] = 1;
                dist[v] = dist[cur] + 1;
                quu.push(v);
            }
        }
    }
    return num_conn;
}

int main() {
    map <int, vector<int> > network;

    int N, S, TTL, v1, v2, count, res;
    count = 0;
    while(cin >> N, N != 0) {
        network.clear();
        for(int i = 0; i < N; i++) {
            cin >> v1 >> v2;
            network[v1].pb(v2);
            network[v2].pb(v1);
        }
        while(cin >> S, S != 0) {
            cin >> TTL;
            if(network.find(S) == network.end())
                res = network.size();
            else
                res = network.size() - bfs(S,TTL, network);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
                    ++count, res, S, TTL);
        }
        cin >> N;
    }
}

