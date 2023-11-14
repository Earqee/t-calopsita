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

VL sieve_ls;
vct primes, ans;

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
    if(N < sieve_ls.size()) return sieve_ls[N];
    ll sqrtN = sqrt(N);
    for(ll i = 0; primes[i] <= sqrtN; i++)
        if(N % primes[i] == 0)
            return false;
    return true;
}

bool Goldbach(ll N) {
    //From i = N/2-1 because the diff p2-p1 needs be POSITIVE
    for(ll i = N/2 - 1; i >= 2; i--) {
        if(isPrime(i) && isPrime(N-i)) {
            ans.pb(i), ans.pb(N-i);
            return true;
        }
    }
    return false;
}

int main() {
    ll N; Sieve(1<<20);
    while(cin >> N) {
        //If the number is odd and there's no Goldbach division for it
        //U will pass through a theta(N) loop! Check this first!
        ans.clear();
        if(N%2) {
            if(N-2 > 1 && isPrime(N-2))
                printf("%ld is the sum of 2 and %ld.", N, N-2);
            else printf("%ld is not the sum of two primes!", N);
        } else {
            if(Goldbach(N))
                printf("%ld is the sum of %ld and %ld.", N, ans[0], ans[1]);
            else printf("%ld is not the sum of two primes!", N);
        }
        cout << endl;
    }
    return 0;
}

