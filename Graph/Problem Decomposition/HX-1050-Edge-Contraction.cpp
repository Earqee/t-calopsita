#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ll;
typedef vector<ll> vct;
typedef vector<vct> vvct;
typedef pair<ll,ll> ii;
#define pb push_back

class DSU {
private:
    vct parent, subt;
public:
    DSU(ll N) {
		parent.resize(N), subt.resize(N,1);
        for(ll u=0; u<N; u++)
            parent[u]=u;
    }
    ll find(ll u) {
		return parent[u]==u?u:(parent[u]=find(parent[u]));
    }
	ll same(ll u, ll v) {return find(u)==find(v); }
    ll merge(ll u, ll v) {
        	ll h = find(u), k = find(v);
			if(subt[h]<subt[k]) {
				parent[h]=k;
				subt[k]+=subt[h];
			} else {
				parent[k]=h;
				subt[h]+=subt[k];
			}
    }
};

int main() {
    //Read entry
    ll N, M, O, R, v1, v2;
    while(cin >> N >> M){ R=N;
    //Read graph
    vvct graph(N);
    for(ll m=0; m<M; m++) {
        cin >> v1 >> v2;
        graph[v1].pb(v2);
		graph[v2].pb(v1);
    }
    //Set forest
	DSU con(N);
	vct vis(N,0);
	for(ll i=0;i<N;i++) {
		if(!vis[i]) {
			vis[i]=1;
			queue<ll> quu;
			quu.push(i);
			while(!quu.empty()) {
				ll u = quu.front(); quu.pop();
				for(ll k=0;k<graph[u].size();k++) {
					ll v=graph[u][k];
					if(!vis[v]) {
						vis[v]=1;
						con.merge(i,v);
						quu.push(v);
					}
				}
			}
		}
	}
	//Now answer queries
    DSU dsu(N);
    vct dist(N);
	cin >> O;
    string op;
    while(O--) {
		cin >> op >> v1 >> v2;
        if(op == "c") {
			//Merge edges
			if(!dsu.same(v1, v2)) {
				dsu.merge(v1, v2);
				R--;
			}
			cout << R << endl;
        } else {
			//0-1 BFS
			if(!con.same(v1, v2)) {
				cout << -1 << endl;
				continue;
			}
			for(ll i=0;i<N;i++) dist[i]=INT_MAX;
			deque<ll> deq;
    		vct dist(N, INT_MAX);
            dist[v1] = 0;
			deq.push_front(v1);
            while(!deq.empty()) {
				ll u = deq.front(); deq.pop_front();
				if(u == v2) break;
				for(ll i=0;i<graph[u].size();i++) {
					ll v=graph[u][i];
					ll w=(ll)!dsu.same(u,v);
					if(dist[u]+w<dist[v]) {
						dist[v]=dist[u]+w;
						if(w)
							deq.push_back(v);
						else
							deq.push_front(v);
					}
				}
            }
			cout << dist[v2] << endl;
        }
    } }return 0;
}
