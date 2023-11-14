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

void run(ll V) {
    vct quu; vector< vct > graph;
    ll v1, v2, *color;
    color = new ll[V + 1](); graph.resize(V + 1);
    bool decomposable = true;
    do {
        cin >> v1 >> v2;
        if(v1 != 0) {
            graph[v1].pb(v2);
            graph[v2].pb(v1);
        }
    } while(v1 != 0);
    for(ll i = 1; i <= V; i++)
        color[i] = -1;
    quu.pb(1); color[1] = 0;
    ll v;
    while(!quu.empty() & decomposable) {
        v = quu.front();
        quu.erase(quu.begin());
        for(ll i = 0; i < graph[v].size(); i++) {
            if(color[graph[v][i]] == -1) {
                color[graph[v][i]] = 1 - color[v];
                quu.pb(graph[v][i]);    
            } else if(color[graph[v][i]] == color[v]) {
                decomposable = false;
            }
        }
    }
    if(decomposable) cout << "YES";
    else cout << "NO";
    cout << endl;
    return;
}


int main() { 
    ll V;
    while(cin >> V, V != 0) run(V);
    return 0;
}