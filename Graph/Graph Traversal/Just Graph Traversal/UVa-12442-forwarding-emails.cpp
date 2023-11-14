#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <list>
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
typedef long long ll;
typedef vector<ll> vct;
typedef pair<ll, ll> ii;
typedef vector<vct> vvct;
typedef vector<string> svct;
typedef vector<ii> vii;
typedef vector<vii> AdjList;
typedef bitset< 1<<20 > MarkedList;

vct connections_know;
AdjList adjlist;
MarkedList visited;
ll count_of_visited, best_amount, best_result;

ll count_connections(ll x){
    if(!visited[x]) {
        visited[x] = 1;
        connections_know[x] = 1 + count_connections(adjlist[x][0].first);
        visited[x] = 0;
        return connections_know[x];
    } return 0;
}

int main() {
    ll T, N, v1, v2, resp;  
    adjlist.resize(1 << 16);
    connections_know.resize(1 << 16);

    cin >> T;
    for(ll t = 0; t < T; t++) {
        cin >> N; 
    
        for(ll n = 0; n < N; n++) {
            cin >> v1 >> v2;
            adjlist[v1].clear();
            adjlist[v1].pb(mp(v2, 0));
            visited[v1] = 0;
            connections_know[v1] = -1;
        }

        best_amount = -1;
        for(ll n = 1; n <= N; n++) {     
            if(connections_know[n] == -1)
                connections_know[n] = count_connections(n);
            if(connections_know[n] > best_amount) {
                best_amount = connections_know[n];
                best_result = n;
            }
        }        
        printf("Case %lld: %lld\n", t + 1, best_result);
    }
    return 0;
}
