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
typedef bitset<(ll)1e6> VL;

VL sieve_ls;
vct primes;
vii fact;

void Sieve() {
    ll sieve_size = (ll)1e6;
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

void primeFact(ll N) {
    fact.clear();
    if(N == 1)
        fact.pb(mp(N, 1));
    ll sqrtN = sqrt(N);
    for(ll i = 0; primes[i] <= sqrtN; i++) {
        while(N % primes[i] == 0) {
            N /= primes[i];
            if(fact.size()) {
                if(fact[fact.size()-1].first == primes[i])
                    fact[fact.size()-1].second++;
                else fact.pb(mp(primes[i], 1));
            } else fact.pb(mp(primes[i], 1));
        }
    }
    if(N > 1)
        fact.pb(mp(N, 1));
    return;
}

ll numDiv() {
    ll ans = 1;
    for(ll i = 0; i < fact.size(); i++)
        ans *= (fact[i].second + 1);
    return ans;
}

int main() {
    Sieve();
    ll T, L, H;
    cin >> T;
    while(T--) {
        cin >> L >> H;
        ll ans = 1, index = L;
        for(ll i = L; i <= H; i++) {
            primeFact(i);
            ll cur = numDiv();
            if(cur > ans) {
                ans = cur;
                index = i;
            }
        }
        if(index == 1)
            ans = 1;
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",
                L, H, index, ans);
    } return 0;
}
