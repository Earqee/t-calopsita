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
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

#define DEBUG 1
#define MAXX 101

vvct min_cost;
map<ll, ll> hashm;

double SumFW() {
    for(ll i = 0; i < hashm.size()+1; i++)
        min_cost[i][i] = 0;
    for(ll k = 0; k < hashm.size()+1; k++) {
        for(ll i = 0; i < hashm.size()+1; i++){
            for(ll j = 0; j < hashm.size()+1; j++) {
                min_cost[i][j] = min(min_cost[i][j], min_cost[i][k] + min_cost[k][j]);
            }
        }
    }
    ll sum = 0;
    for(ll i = 0; i < hashm.size()+1; i++)
        for(ll j = 0; j < hashm.size()+1; j++)
            if(min_cost[i][j] != INT_MAX)
                sum += min_cost[i][j];
    ll n = hashm.size();
    return sum/((double)(n*(n-1)));
}


void adjustMap(ll v1, ll v2) {
        if(hashm.find(v1) == hashm.end())
            hashm[v1] = hashm.size();
        if(hashm.find(v2) == hashm.end())
            hashm[v2] = hashm.size();
}
int main() {
    ll v1, v2, count = 0;
    min_cost.resize(MAXX);
    while(cin >> v1 >> v2) {
        if(v1 == 0 && v2 == 0) break;
        count++;
        hashm.clear();
        for(ll i = 0; i < MAXX; i++)
            min_cost[i].assign(MAXX, INT_MAX);
        adjustMap(v1, v2);
        min_cost[hashm[v1]][hashm[v2]] = 1;
        while(cin >> v1 >> v2) {
            if(v1 == 0 && v2 == 0) break;
            adjustMap(v1, v2);
            min_cost[hashm[v1]][hashm[v2]] = 1;
        }
        printf("Case %lld: average length between pages = %.3lf clicks\n", count, SumFW());
    }
    return 0;
}

