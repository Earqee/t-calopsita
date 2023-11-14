#include <bits/std++.h>

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
typedef bitset<1 << 8> VL;

void run(ll N, ll M) {
    vector< vct > graph; vct quu;
    ll nod1, nod2, color[N]; 
    bool isBicolorable = true;
    graph.resize(N + 1);

    for(ll i = 0; i < M; i++) {
        cin >> nod1 >> nod2;
        graph[nod1].pb(nod2);
    }  
    for(ll i = 0; i < N; i++)
        color[i] = -1;

    ll v; quu.pb(0); color[0] = 0;
    while(!quu.empty() & isBicolorable) {
        v = quu.front();
        quu.erase(quu.begin());
        for(ll i = 0; i < graph[v].size(); i++) {
            if(color[graph[v][i]] == -1) {
                color[graph[v][i]] = 1 - color[v];
                quu.pb(graph[v][i]);
            }
            else if(color[graph[v][i]] == color[v]) 
                isBicolorable = false;
        }
    }
    if(isBicolorable) cout << "BICOLORABLE.";
    else cout << "NOT BICOLORABLE.";
    return;
}

int main() {
    ll N, M;
    while(cin >> N, N != 0) {
        cin >> M; 
        run(N, M); 
        cout << endl;
    }
    return 0;  
}
