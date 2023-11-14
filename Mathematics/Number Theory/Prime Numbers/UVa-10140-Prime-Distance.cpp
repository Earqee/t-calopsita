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
typedef pair<ll, ii> lii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 23> VL;

VL sieve_ls;
vct primes;

void Sieve(ll N) {
    sieve_ls.set();
    sieve_ls[0] = sieve_ls[1] = 0;
    for(ll i = 2; i < N; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < N; j+=i) {
                sieve_ls[j] = 0;
            }
            primes.pb(i);
        }
    } return;
}

bool isPrime(ll N) {
    if(N < 1<<23) return sieve_ls[N];
    ll sqrtN = sqrt(N);
    for(ll i = 0; primes[i] <= sqrtN; i++)
        if(N % primes[i] == 0)
            return false;
    return true;
}


int main() {
    ll L, U;
    Sieve(1<<23);
    while(cin >> L >> U) {
        ll max_l, max_u, min_l, min_u, last_prime = 0;
        ll min_diff = 1<<30;
        ll max_diff = -(1<<30);
        bool found = false;
        for(ll i = L; i <= U; i++) {
            if(isPrime(i)) {
                if(!last_prime)
                    last_prime = i;
                else {
                    found = true;
                    ll diff = i - last_prime;
                    if(diff > max_diff) {
                        max_diff = diff;
                        max_l = last_prime;
                        max_u = i;
                    }
                    if(diff < min_diff) {
                        min_diff = diff;
                        min_l = last_prime;
                        min_u = i;
                    }
                }
                last_prime = i;
            }
        }
        if(found)
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",
                min_l, min_u, max_l, max_u);
        else cout << "There are no adjacent primes." << endl;
    }
    return 0;
}

