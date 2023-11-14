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

ll find(string str, vector< string > &hasht) {
    for(ll i = 0; i < hasht.size(); i++)
        if(hasht[i] == str)
            return i;
}

ll run(ll N, ll j) {
    vector< string > hasht;
    vector< vct >  bev;
    string str, bev1, bev2;
    ll M, i_bev1, i_bev2;
    vct quu, sol; ll *degree;

    bev.resize(N + 1), degree = new ll[N]();  

    for(ll i = 0; i < N; i++) {
        cin >> str;
        hasht.pb(str);
    }
    cin >> M;
    for(ll i = 0; i < M; i++) {
        cin >> bev1 >> bev2;
        i_bev1 = find(bev1, hasht);
        i_bev2 = find(bev2, hasht);
        bev[i_bev1].pb(i_bev2);
        degree[i_bev2]++;
    }    
    for(ll i = 0; i < N; i++)
        if(degree[i] == 0) {
            quu.pb(i);
            degree[i] = -1;            
        }
    ll v;
    while(!quu.empty()) {
        v = quu.front();
        quu.erase(quu.begin());
        sol.pb(v);
        for(ll i = 0; i < bev[v].size(); i++) {
            degree[bev[v][i]]--;
            if(degree[bev[v][i]] == 0) {
                quu.pb(bev[v][i]);
                degree[bev[v][i]] = -1;
            }
        } 
        sort(all(quu));        
    }
    printf("Case #%ld: Dilbert should drink beverages in this order: ", j);
    for(ll i = 0; i < sol.size(); i++) {
        if(i) cout << ' ';
        cout << hasht[sol[i]];
    }
    cout << '.' << endl << endl;

}
int main() {
    ll N, j; j = 0;
    while(cin >> N) run(N, ++j);       
    return 0;
}

