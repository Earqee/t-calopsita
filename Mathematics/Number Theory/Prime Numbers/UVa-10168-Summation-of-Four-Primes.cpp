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
typedef bitset<(ll)1e7+1> VL;

VL sieve_ls;
vct ans, primes;

void Sieve(ll N) {
    sieve_ls.set();
    sieve_ls[0] = sieve_ls[1] = 0;
    for(ll i = 2; i < N; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < N; j+=i)
                sieve_ls[j] = 0;
            primes.pb(i);
        }
    } return;
}

bool isPrime(ll N) {
    return sieve_ls[N];
}

void Goldbach(ll N) {
    for(ll i = 2; i <= N/2; i++) {
        if(isPrime(i) && isPrime(N-i)) {
            ans.pb(i), ans.pb(N-i);
            return;
        }
    } return;
}

int main() {
    ll N; Sieve(sieve_ls.size());
    while(cin >> N) {
        ans.clear();
        if(N < 8) {
            cout << "Impossible." << endl;
            continue;
        }
        if(N % 2) {
            printf("2 3");
            Goldbach(N - 5);
        } else {
            printf("2 2");
            Goldbach(N - 4);
        }
        for(ll i = 0; i < 2; i++)
            cout << ' ' << ans[i];
        cout << endl;
    }
    return 0;
}

