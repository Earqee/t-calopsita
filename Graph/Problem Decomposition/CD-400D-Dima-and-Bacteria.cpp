#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<ll> v1ct;
typedef vector<v1ct> v2ct;
typedef pair<ll,ll> ii;
typedef vector<ii> v1i;

class DSU {
private:
    v1ct parent, subt;
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
    //First line
    ll N, M, K, W, v1, v2;
    cin >> N >> M >> K;
    ll l = 0, r=0;
    //
    v1ct conj(N+1,0), mag(N+1, 0);
    //Macacada
    for(ll k=0;k<K;k++) {
        cin >> r;
        for(ll i=l+1; i<l+1+r;i++)
            conj[i]=k, mag[i]=l+r+1;
        l=l+r;
    }
    //Init
    ll min_dist[K][K];
    for(ll i=0;i<K;i++) {
        for(ll j=0;j<K;j++)
            min_dist[i][j]=INT_MAX;
        min_dist[i][i]=0;
    }
    //Ler
    DSU dsu(N+1);
    for(ll m=0; m<M; m++) {
        cin >> v1 >> v2 >> W;
        ll k1=conj[v1], k2=conj[v2];
        if(W==0) dsu.merge(v1, v2);
        min_dist[k1][k2] = min_dist[k2][k1] = min(
                min(min_dist[k1][k2], min_dist[k2][k1]), W);
    }
    //Sem solucao
    for(ll i=1; i<=N; i=mag[i])
        for(ll j=i+1; j<mag[i]; j++)
            if(!dsu.same(i,j)) {cout<<"No"<<endl; return 0;};
    //Solucao
    for(ll k=0;k<K; k++) for(ll i=0;i<K; i++) for(ll j=0;j<K;j++)
                min_dist[i][j]=min(min_dist[i][j], min_dist[i][k]+min_dist[k][j]);
    //Print
        cout<<"Yes"<<endl;
        for(ll i=0;i<K;i++) {
            for(ll j=0;j<K;j++) {
                if(j) cout<<' ';
                cout<<(min_dist[i][j]!=INT_MAX?min_dist[i][j]:-1);
            }
            cout<<endl;
        }
    return 0;
}
