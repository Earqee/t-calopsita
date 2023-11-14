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
typedef bitset<1 << 8> VL;

VL sieve_ls;
vii primes;

void Sieve() {
    ll sieve_size = 1 << 7;
    sieve_ls.set();
    for(ll i = 2; i < sieve_size; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < sieve_size; j+=i)
                sieve_ls[j] = 0;
            primes.pb(mp(i, 0));
        }
    } return;
}

void findFact(ll N) {
    ll sqrtN = sqrt(N);
    for(ll i = 0; N > 1 && primes[i].first <= N; i++) {
        while(N % primes[i].first == 0) {
            N /= primes[i].first;
            primes[i].second++;
        }
    } return;
}

int main() {
    ll N; Sieve();
    while(cin >> N, N != 0) {
        //Get answer
        for(ll i = 2; i <= N; i++)
            findFact(i);
        //Print N! =
        if(N < 10) printf("  ");
        else if(N < 100) printf(" ");
        printf("%ld! =", N);
        //Print others
        ll count = 1, my_frst = 1;
        for(ll i = 0; i < primes.size(); i++) {
            if(primes[i].second) {
                if(count == 1 && !my_frst) {
                        printf("\n      ");
                }
                //Identation
                if(primes[i].second < 10)
                    printf("  ");
                else
                    printf(" ");
                //Print answer
                printf("%ld", primes[i].second);
                count++;
                //Solve endl
                if(count == 16)
                    count = 1, my_frst = 0;
            }
        }
        //Clear ans
        for(ll i = 0; i < primes.size(); i++)
            primes[i].second = 0;
        cout << endl;
    }
}
