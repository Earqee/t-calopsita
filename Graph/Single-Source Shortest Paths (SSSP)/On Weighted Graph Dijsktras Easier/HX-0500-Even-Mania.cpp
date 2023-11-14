#include <bits/stdc++.h>

#define pb push_back
#define mt make_tuple

using namespace std;
typedef long long ll;
typedef vector<ll> vct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef tuple<ll,ll,ll> tu;

int main() {
    ll C, V, v1, v2, G;
    cin >> C >> V;
    vvii graph(C+1);
    for(ll v=0;v<V;v++) {
        cin >> v1 >> v2 >> G;
        graph[v1].pb({v2, G});
        graph[v2].pb({v1, G});
    }
    queue<tu> quu;
    vct visit(C+1, 0);
    ll dist[C+1][2];
    for(ll i=0;i<C+1;i++)
        dist[i][0] = dist[i][1] = INT_MAX;
#define even 0
#define odd 1
    dist[1][even] = 0;
    quu.push(mt(-0,-1,-even));
    while(!quu.empty()) {
        tu data = quu.front(); quu.pop();
        ll s = -get<0>(data), u = -get<1>(data), b = -get<2>(data);
        for(ll i=0;i<graph[u].size();i++) {
            ll v = graph[u][i].first;
            ll w = graph[u][i].second;
            if(b==even) {
                dist[v][odd] = min(dist[v][odd], dist[u][even]+w);
                if(!visit[v])
                    quu.push(mt(-dist[v][odd],-v,-!b));
            } else {
                dist[v][even] = min(dist[v][even], dist[u][odd]+w);
                if(!visit[v])
                    quu.push(mt(-dist[v][even],-v,-!b));
            }
        }
        visit[u]=1;
    }
    if(dist[C][0]!=INT_MAX)
        cout << dist[C][0] << endl;
    else
        cout << -1 << endl;
    return 0;
}
