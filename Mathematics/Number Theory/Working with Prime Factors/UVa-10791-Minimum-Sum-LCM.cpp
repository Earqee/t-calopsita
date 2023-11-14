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
typedef unsigned long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 16> VL;

ll gcd(ll a, ll b) {return b==0?a:gcd(b, a%b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a, b));}

VL sieve_ls;
vct fact, primes;

void Sieve() {
    ll sieve_size = 1 << 16;
    sieve_ls.set();
    sieve_ls[0] = sieve_ls[1] = 0;
    for(ll i = 2; i < sieve_size; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < sieve_size; j+=i)
                sieve_ls[j] = 0;
            primes.pb(i);
        }
    }
    return;
}

bool isPrime(ll N) {
    if(N < sieve_ls.size()) return sieve_ls[N];
    ll sqrtN = sqrt(N);
    for(ll i = 0; primes[i] <= sqrtN; i++)
        if(N % primes[i] == 0)
            return false;
    return true;
}

ll findFact(ll backup) {
    ll N = backup;
    if(!isPrime(N)) {
        ll sqrtN = sqrt(N);
        for(ll i = 0; primes[i] <= sqrtN; i++) {
            while(N % primes[i] == 0) {
                N /= primes[i];
                if(fact.size()) {
                    if(fact[fact.size()-1] % primes[i] == 0)
                        fact[fact.size()-1] *= primes[i];
                    else fact.pb(primes[i]);
                }
                else fact.pb(primes[i]);
            }
        }
    }
    if(N > 1 || backup == 1)
            fact.pb(N);
    if(fact.size() == 1)
        return backup + 1;
    ll ans = 0;
    for(ll i = 0; i < fact.size(); i++)
        ans += fact[i];
    return ans;
}

int main() {
    ll N, count = 1; Sieve();
    while(cin >> N, N != 0) {
        printf("Case %lld: ", count++);
        fact.clear();
        printf("%lld\n", findFact(N));
    } return 0;
}

