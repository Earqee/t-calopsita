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

ll NOD(ll x) {
    ll count = 0;
    for(ll i = 1; i <= sqrt(x); i++) {
        if(x % i == 0) {
            if(x / i == i) count++;
            else count += 2;
        }
    }    
    return count;
}

ll NNODN(ll x, vct & nod) {
    if(x == 0) {
        nod.pb(1); 
        return nod.back();
    }
    nod.pb(NNODN(x - 1, nod) + NOD(nod.back()));
    return nod.back();
}

int main() {
    vct nod; NNODN(1 << 16, nod); 
    ll min, max, A, B; 
    ll N; cin >> N;
    for(ll i = 0; i < N; i++) {
        cin >> A >> B;
        min = lwb(all(nod), A) - nod.begin();
        max = upb(all(nod), B) - nod.begin() - 1;
        printf("Case %ld: %ld\n", i + 1, max - min + 1);
    }
    return 0;
}