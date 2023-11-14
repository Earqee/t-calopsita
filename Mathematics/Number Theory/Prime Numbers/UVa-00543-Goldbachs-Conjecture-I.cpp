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
typedef bitset<1 << 20> VL;

VL sieve_num;
vct primes;

void Sieve(ll N) {
    sieve_num.set();
    sieve_num[0] = 0;
    for(ll i = 2; i <= N; i++) {
        if(sieve_num[i]) {
            for(ll j = i*i; j <= N; j+=i) {
                sieve_num[j] = 0;
            }
            primes.pb(i);
        }
    } return;
}

bool isPrime(ll N) {
    if(N < sieve_num.size()) return sieve_num[N];
    ll sqrtN = sqrt(N);
    for(ll i = 0; primes[i] <= sqrtN; i++) {
        if(N % primes[i] == 0)
            return false;
    } return true;
}

int main() {
    ll N, first, second, max_diff, diff;
    Sieve(1 << 20);
    while(cin >> N, N != 0) {
        for(ll i = 3; i <= N/2; i++) {
            if(isPrime(i)) {
                ll j = N - i;
                if(isPrime(j)) {
                    printf("%ld = %ld + %ld\n", N, i, j);
                    break;
                }
            }
        }
    }
    return 0;
}
