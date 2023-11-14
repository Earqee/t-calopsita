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

ADL graph;
list<ii> tour;

void EulerPath(list<ii>::iterator i, ll u) {
    for(ll j = 0; j < graph[u].size(); j++) {
        ii v = graph[u][j];
        if(v.second) {
            graph[u][j].second = 0;
            for(ll k = 0; k < graph[v.first].size(); k++) {
                ii ret = graph[v.first][k];
                if(ret.first == u && ret.second) {
                    graph[v.first][k].second = 0;
                    break;
                }
            }
            EulerPath(tour.insert(i, mp(v.first+1,u+1)), v.first);
        }
    } return;
}

int main() {
    ll T, N, v1, v2;
    cin >> T;
    for(ll t = 0; t < T; t++) {
        cin >> N;
        graph.clear(); graph.resize(51);
        for(ll i = 0; i < N; i++) {
            cin >> v1 >> v2;
            graph[v1-1].pb(mp(v2-1, 1)); graph[v2-1].pb(mp(v1-1, 1));
        }
        ll odd_count = 0;
        for(ll i = 0; i < 50; i++) {
            if(graph[i].size() % 2)
                odd_count = 1;
        }
        if(t) cout << endl;
        printf("Case #%ld\n", t+1);
        if(odd_count % 2) {
            cout << "some beads may be lost" << endl;
        } else {
            ll source = -1;
            for(ll i = 0; i < 50; i++)
                if(graph[i].size() != 0 && source == -1)
                    source = i;
            tour.clear();
            EulerPath(tour.begin(), source);
            for(list<ii>::iterator it = tour.begin(); it != tour.end(); it++)
                printf("%ld %ld\n", (*it).first, (*it).second);
        }
    }
    return 0;
}

