//Number of times a prime coems in prime factorization of factorial
//See this: https://www.youtube.com/watch?v=DIYijfFxBaU
//Polignac's formula :)

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
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

VL sieve_ls;
vct primes;
vii m_fact;

void Sieve() {
    ll sieve_size = 1 << 20;
    sieve_ls.set();
    sieve_ls[0] = sieve_ls[1] = 0;
    for(ll i = 2; i < sieve_size; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < sieve_size; j+=i)
                sieve_ls[j] = 0;
            primes.pb(i);
        }
    }
}

void findFact(ll N, vii &my_vct) {
    ll sqrtN = sqrt(N);
    for(ll i = 0; primes[i] <= sqrtN; i++) {
        while(N % primes[i] == 0) {
            N /= primes[i];
            if(my_vct.size()) {
                if(my_vct[my_vct.size()-1].first == primes[i])
                    my_vct[my_vct.size()-1].second++;
                else my_vct.pb(mp(primes[i], 1));
            } else my_vct.pb(mp(primes[i],1));
        }
    }
    if(N > 1)
        my_vct.pb(mp(N,1));
    return;
}

//Polignac's formula to find the occurency of a prime in N!
ll countPrimesOcc(ll N, ll prm) {
    ll count = 0;
    while(N >= prm) {
        count += N/prm;
        N /= prm;
    }
    return count;
}

int main() {
    ll n, m; Sieve();
    while(cin >> n >> m) {
        m_fact.clear();
        findFact(m, m_fact);
        ll itDivides = false;
        for(ll i = 0; i < m_fact.size(); i++) {
            ll my_cnt = countPrimesOcc(n, m_fact[i].first);
            if(my_cnt < m_fact[i].second)
                i = m_fact.size();
            if(i+1 == m_fact.size())
                itDivides = true;
        }
        if(itDivides || m == 1)
            printf("%ld divides %ld!\n", m, n);
        else printf("%ld does not divide %ld!\n", m, n);
    } return 0;
}
