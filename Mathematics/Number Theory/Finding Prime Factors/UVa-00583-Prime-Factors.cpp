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
typedef bitset<1 << 22> VL;

VL sieve_ls;
vct primes;

void Sieve() {
    sieve_ls.set(); ll my_size = 1<<22;
    sieve_ls[0] = sieve_ls[1] = 0;
    for(ll i = 2; i < my_size; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < my_size; j+=i)
                sieve_ls[j] = 0;
            primes.pb(i);
        }
    } return;
}

void findFact(ll N, ll my_neg) {
    ll sqrtN = sqrt(N), my_frst = !my_neg;
    if(my_neg) printf("-1");
    //Print sequence of prime factors
    for(ll i = 0; primes[i] <= sqrtN; i++) {
        while(N%primes[i] == 0) {
            N /= primes[i];
            if(!my_frst)
                printf(" x %lld", primes[i]);
            else {
                printf("%lld", primes[i]);
                my_frst = 0;
            }
        }
    }
    //Someone is left
    if(N > 1) {
        if(my_frst)
            printf("%lld", N);
        else printf(" x %lld", N);
    }
    return;
}

int main() {
    ll N, my_neg;
    Sieve();
    while(cin >> N, N != 0) {
        printf("%lld = ",N);
        if(N < 0) my_neg = 1;
        else my_neg = 0;
        findFact(abs(N), my_neg);
        cout << endl;
    }
    return 0;
}
