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
typedef bitset<1 << 10> VL;

VL sieve_ls;
vct primes;

void Sieve(ll N) {
    sieve_ls.set();
    sieve_ls[0] = sieve_ls[1] = 0;
    primes.pb(1);
    for(ll i = 2; i < N; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < N; j+=i)
                sieve_ls[j] = 0;
            primes.pb(i);
        }
    } return;
}

int main() {
    ll N, C;
    Sieve(1<<10);
    while(cin >> N >> C) {
        ll it = upb(all(primes), N) - primes.begin();
        ll centre = it/2;
        printf("%ld %ld:", N, C);
        if(centre-C < 0 || centre+C > N) {
            for(ll i = 0; primes[i] <= N; i++) {
                cout << ' ' << primes[i];
            }
        }
        else if(it % 2 == 0) {
            for(ll i = centre-C; i < centre+C; i++) {
                cout << ' ' << primes[i];
            }
        } else {
            for(ll i = centre-C+1; i < centre+C; i++) {
                cout << ' ' << primes[i];
            }
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}

