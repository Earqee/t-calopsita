#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<ll> v1ct;
typedef vector<v1ct> v2ct;
typedef pair<ll,double> ii;

int main() {
    ll N, v1, v2;
    cin >> N;
    v2ct graph(N+1);
    for(ll n=0;n<N-1;n++) {
        cin >> v1 >> v2;
        graph[v1].pb(v2);
        graph[v2].pb(v1);
    }
    queue<ii> quu;
    v1ct dsu(N+1,0);
    double ans = 0;
    dsu[1]=1;
    quu.push({1, 0});
#define E 1e-6
    while(!quu.empty()) {
        ll u = get<0>(quu.front());
        double p = get<1>(quu.front());
        ans += p;
        quu.pop();
        double q=0;
        for(ll i=0;i<graph[u].size();i++)
            if(!dsu[graph[u][i]])
                q+=1;
        for(ll i=0;i<graph[u].size();i++) {
            ll v = graph[u][i];
            if(!dsu[v]) {
                dsu[v]=1;
                double np = 1.0/q;
                quu.push({v, (u!=1?p:1.0)*np});
            }
        }
    }
    printf("%lf", ans);
    return 0;
}
