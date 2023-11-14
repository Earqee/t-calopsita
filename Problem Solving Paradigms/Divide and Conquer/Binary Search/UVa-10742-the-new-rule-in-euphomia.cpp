#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>

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
typedef bitset<1 << 8> VL;

void sieve(ll max, vct &primes) {
    bitset< 1<<20 + 1 > bs; 
    bs.set();
    for(ll i = 2; i <= max; i++) {
        if(bs[i]) {
            for(ll j = i * i; j <= max; j += i)
                bs.set(j, 0);
            primes.pb(i);
        }
    } return;
}

int main() {
    ll count, high, low;
    ll x, j, N; j = 0;
    vct primes; sieve(1 << 20, primes);

    while(cin >> N) {        
        if(!N) return 0;
        count = 0;    
        high = lwb(all(primes), N) - primes.begin();
        while(--high > 0) {
            x = N - primes.at(0) - primes.at(high);
            if(x >= 0) {
                low = lwb(all(primes), primes.at(0) + x) - primes.begin();
                if(primes.at(low) > x + primes.at(0)) low--;
                if(primes.at(0) + x >= primes.at(high))
                    count += high;
                else
                    count += low + 1;
            }
        }
        printf("Case %ld: %ld\n", ++j, count);   
    } 
    return 0;
}