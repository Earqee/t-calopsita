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

void run(ll N, ll M) {
    vector< vct > order; order.resize(N + 1);
    ll *degree; degree = new ll[N + 1]();
    ll stk1, stk2;
    vct quu;

    for(ll i = 1; i <= M; i++) {
        cin >> stk1 >> stk2;
        order[stk1].pb(stk2);
        degree[stk2]++;
    }
    for(ll i = 1; i <= N; i++) 
        if(degree[i] == 0) { 
            quu.pb(i);
            degree[i] = -1;
        }

    if(!quu.empty()) {
        ll v;
        while(!quu.empty()) {
            v = quu.front();
            quu.erase(quu.begin());
            cout << v << endl;
            for(ll i = 0; i < order[v].size(); i++) {
                degree[order[v][i]]--;
                if(degree[order[v][i]] == 0) {
                    quu.pb(order[v][i]);
                    degree[order[v][i]] = -1;
                }
            }
        }
    } else cout << "IMPOSSIBLE" << endl;
    return;
}

int main() {
    ll N, M;
    while(cin >> N >> M, N != 0) run(N, M);
}