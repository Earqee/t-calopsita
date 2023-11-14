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
typedef pair<ll, ii> lii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

vvct graph;
priority_queue<lii> quu;
vector<lii> ans;
vct visited;

void Process(ll vertex) {
    visited[vertex] = 1;
    for(ll i = 0; i < graph.size(); i++) {
        ll weight = graph[vertex][i];
        if(weight != 0 && !visited[i]) {
            quu.push(mp(-weight, mp(-vertex, -i)));
        }
    }
    return;
}

void Prim() {
    Process(0);
    while(!quu.empty()) {
        lii current = quu.top(); quu.pop();
        ll weight = -current.first;
        ll u = -current.second.first;
        ll v = -current.second.second;
        if(!visited[v]) {
            if(u < v)
                ans.pb(mp(weight, mp(u, v)));
            else ans.pb(mp(weight, mp(v, u)));
            Process(v);
        }
    }
    return;
}

bool Lambda(lii frt, lii scd) {
    if(frt.first < scd.first)
        return true;
    else if(frt.first == scd.first) {
        if(frt.second.first < scd.second.first)
            return true;
        else if(frt.second.first == scd.second.first)
            return frt.second.second < scd.second.second;
    }
    return false;
}

int main() {
    ll T, N;
    cin >> T;
    for(ll t = 0; t < T; t++) {
        cin >> N;
        ans.clear(), visited.assign(N, 0);
        graph.resize(N);
        for(ll i = 0; i < N; i++)
            graph[i].resize(N);
        for(ll i = 0; i < N; i++) {
            for(ll j = 0; j < N; j++) {
                cin >> graph[i][j];
                if(j + 1 < N) getchar();
            }
        }
        Prim();
        sort(ans.begin(), ans.end(), Lambda);
        printf("Case %ld:\n", t + 1);
        for(ll i = 0; i < ans.size(); i++) {
            ll weight = ans[i].first;
            ll u = ans[i].second.first;
            ll v = ans[i].second.second;
            printf("%c-%c %ld\n", u + 'A', v + 'A', weight);
        }
    }
    return 0;
}
