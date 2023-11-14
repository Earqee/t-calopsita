#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>

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

ADL adjlist;
VL visited;
vct queue;

void dfs(ll x) {
    visited[x] = 1;
    for(ll i = 0; i < adjlist[x].size(); i++) {
        if(!visited[adjlist[x][i].first]) 
            dfs(adjlist[x][i].first);
    }
    queue.pb(x);
}

int main() {
    ll N, M, v1, v2;
    adjlist.resize(1 << 8);

    while(cin >> N >> M, N != 0) {        
        for(ll i = 0; i < 1 << 8; i++)
            adjlist[i].clear();
        queue.clear(), visited.set(), visited.flip();        
        for(ll i = 1; i <= M; i++) 
            cin >> v1 >> v2, adjlist[v1].pb(mp(v2, 0));     
        for(ll i = 1; i <= N; i++) 
            if(!visited[i]) 
                dfs(i);
        reverse(all(queue));
        for(ll j = 0; j < queue.size(); j++) {
            if(j) cout << ' ';
            cout << queue[j];
        }                   
        cout << endl;
    }
}