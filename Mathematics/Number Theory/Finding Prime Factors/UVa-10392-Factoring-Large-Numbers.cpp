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
typedef bitset<(ll)1e7+1> VL;

VL sieve_ls;
vct primes;

void Sieve() {
    ll sieve_size = (ll)1e7+1;
    sieve_ls.set();
    for(ll i = 2; i < sieve_size; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < sieve_size; j+=i)
                sieve_ls[j];
            primes.pb(i);
        }
    } return;
}

void primeFact(ll N) {
    ll sqrtN = sqrt(N), primes_size = primes.size();
    for(ll i = 0; i < primes_size && primes[i] <= sqrtN; i++) {
        while(N % primes[i] == 0) {
            N /= primes[i];
            cout << "    " << primes[i] << endl;
        }
    }
    if(N > 1)
        cout << "    " << N << endl;
    return;
}

int main() {
    ll N; Sieve();
    while(cin >> N, N >= 0) {
        primeFact(N);
        cout << endl;
    }
}
