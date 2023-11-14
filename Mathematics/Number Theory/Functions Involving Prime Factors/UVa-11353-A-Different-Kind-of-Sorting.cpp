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
typedef bitset<(ll)2e6+1> VL;

VL sieve_ls;
vct primes, fact;
vii my_arr;

void Sieve() {
    ll sieve_size = (ll)2e6+1;
    sieve_ls.set(); fact.assign(sieve_size, 0);
    fact[1] = 1;
    for(ll i = 2; i < sieve_size; i++) {
        if(sieve_ls[i]) {
            for(ll j = i; j < sieve_size; j+=i)
                sieve_ls[j] = 0;
            primes.pb(i);
        }
    } return;
}

bool findFact(ll backup) {
    ll N = backup;
    if(N == 1 || sieve_ls[N])
        return fact[N] = 1;
    ll sqrtN = sqrt(N);
    for(ll i = 0; primes[i] <= sqrtN; i++) {
        while(N % primes[i] == 0) {
            N /= primes[i];
            fact[backup]++;
        }
    }
    if(N > 1)
        fact[backup]++;
    return true;
}

bool Lambda(ii frt, ii scd) {
    if(frt.first == scd.first)
        return frt.second < scd.second;
    else
        return frt.first < scd.first;
    return false;
}

void createArray() {
    for(ll i = 1; i <= (ll)2e6; i++) {
        findFact(i);
        my_arr.pb(mp(fact[i], i));
    }
    sort(all(my_arr), Lambda);
    return;
}

int main() {
    ll N, count = 1;
    Sieve(), createArray();
    while(cin >> N, N != 0)
        printf("Case %lld: %lld\n", count++, my_arr[N-1].second);
    return 0;
}
