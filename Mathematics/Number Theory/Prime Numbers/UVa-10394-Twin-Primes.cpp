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
typedef bitset<(ll)2e7> VL;

VL sieve_ls;
vii twins;

void Sieve() {
    ll N = (ll)2e7;
    sieve_ls.set();
    sieve_ls[0] = sieve_ls[1] = 0;
    for(ll i = 2; i < N; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < N; j+=i)
                sieve_ls[j] = 0;
            if(sieve_ls[i-2])
                twins.pb(mp(i-2, i));
        }
    } return;
}

int main() {
    ll N; Sieve();
    while(cin >> N) {
        printf("(%ld, %ld)\n", twins[N-1].first, twins[N-1].second);
    } return 0;
}

