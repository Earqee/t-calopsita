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

ll gdc(ll a, ll b) {return b==0?a:gdc(b, a%b);}
ll lcm(ll a, ll b) {return a*(b/gdc(a, b));}

VL sieve_ls;
vct primes;
vii n_fact, m_fct;

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
    } return;
}


void primFact(ll N, vii &my_fct) {
    ll sqrtN = sqrt(N);
    for(ll i = 0; primes[i] <= sqrtN; i++) {
        while(N % primes[i] == 0) {
            N /= primes[i];
            if(!my_fct.size())
                my_fct.pb(mp(primes[i], 1));
            else {
                if(my_fct[my_fct.size()-1].first != primes[i])
                    my_fct.pb(mp(primes[i], 1));
                else my_fct[my_fct.size()-1].second++;
            }
        }
    }
    if(N > 1)
        my_fct.pb(mp(N, 1));
    return;
}

ll ansQuery(vii fact, ll sign) {
    ll  ans = fact[0].second;
    for(ll i = 1; i < fact.size(); i++)
        ans = gdc(ans, fact[i].second);
    if(!sign) while(!(ans%2) && ans != 0) ans /= 2;
    if(ans != 0)
        printf("%ld\n", ans);
    else printf("1\n");

}

int main() {
    ll N; Sieve();
    while(cin >> N, N != 0) {
        ll sign = N > 0; N = abs(N);
        n_fact.clear();
        primFact(N, n_fact);
        ansQuery(n_fact, sign);
    } return 0;
}
