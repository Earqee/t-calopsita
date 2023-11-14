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
typedef bitset<(ll)1e5+1> VL;

VL sieve_ls;
vct fact, primes;

void Sieve() {
    ll sieve_size = (ll)1e5+1;
    sieve_ls.set();
    sieve_ls[0] = sieve_ls[1] = 0;
    for(ll i = 2; i < sieve_size; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < sieve_size; j+=i)
                sieve_ls[j] = 0;
            primes.pb(i);
        }
    } return;
}

void findFact(ll N) {
    fact.clear();
    ll sqrtN = sqrt(N);
    for(ll i = 0; primes[i] <= sqrtN; i++) {
        while(N % primes[i] == 0) {
            N /= primes[i];
            if(N % primes[i] != 0)
                fact.pb(primes[i]);
        }
    }
    if(N > 1)
        fact.pb(N);
    return;
}

ll phiEuler(ll N) {
    if(N == 1)
        return 1;
    double ans = N;
    for(ll i = 0; i < fact.size(); i++)
        ans *= (1.0 - 1.0/fact[i]);
    return ans;
}

int main() {
    ll N; Sieve();
    while(cin >> N, N != 0) {
        findFact(N);
        printf("%lld\n", phiEuler(N));
    } return 0;
}
