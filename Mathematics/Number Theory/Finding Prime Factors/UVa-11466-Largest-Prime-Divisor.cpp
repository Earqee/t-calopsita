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
typedef bitset<4*(ll)1e7> VL;

VL sieve_ls;
vct primes;
ll my_count;

void Sieve() {
    sieve_ls.set(); ll my_size = 4*(ll)1e7;
    sieve_ls[0] = sieve_ls[1] = 0;
    for(ll i = 2; i < my_size; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < my_size; j+=i)
                sieve_ls[j] = 0;
            primes.pb(i);
        }
    } return;
}

ll findLPD(ll N) {
    ll sqrtN = sqrt(N); ll last = 1, total = 0;
    //Go through prime representation
    for(ll i = 0; primes[i] <= sqrtN; i++) {
        while(N % primes[i] == 0) {
            N /= primes[i];
            last = primes[i];
            total = 1;
        }
        my_count += total, total = 0;
    }
    //Last factor is the prime > sqrtN?
    if(N > 1)
        last = N, my_count++;
    return last;
}

int main() {
    ll N; Sieve();
    while(cin >> N, N != 0) {
        my_count = 0;
        ll ans = findLPD(abs(N));
        if(my_count <= 1)
            printf("-1\n");
        else printf("%lld\n", ans);
    }
    return 0;
}
