#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <bitset>

#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> AdjList;
typedef bitset< 1<<8 > MarkedList;

vi learn;
bool stop_recursion;
ll value, soma;
AdjList life;    

void reset() {
    for(ll i = 0; i < 1 << 8; i++) {
        life[i].clear();
    }
    life.clear(); learn.clear();
    soma = 0; value = 0 ; stop_recursion = false;        
}

void flow(ll i) {
    bool found = false;
    ll k, bigger;
    for(ll j = 0, bigger = -1; j < life[i].size(); j++) {

        if(life[i][j].second >= bigger) {
            k = j;
            bigger = life[i][j].second;
            found = true;
        }
        if(j + 1 == life[i].size()) {
            if(found) {
                value = life[i][k].first;
                soma += life[i][k].second;
                flow(life[i][k].first);
            }
        }
    }
    return;
}

int main() {
    ll N, M, T, v1, v2, num;  
    life.resize(1 << 8);  
    cin >> T;
    for(ll t = 0; t < T; t++) {
        cin >> N >> M;
        reset();
        for(ll n = 0; n < N; n++){
            cin >> num;
            learn.pb(num);
        }
        for(ll m = 0; m < M; m++) {
            cin >> v1 >> v2;
            life[v1].pb(make_pair(v2, learn[v2]));
        }
        flow(0);
        printf("Case %lld: %lld %lld\n", t + 1, soma, value);
    }
}
