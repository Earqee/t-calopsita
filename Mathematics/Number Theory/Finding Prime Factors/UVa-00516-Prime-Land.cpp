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
typedef bitset<1 << 16> VL;

VL sieve_ls;
vct primes;

void Sieve() {
    sieve_ls.set();
    ll sieve_size = 1 << 16;
    for(ll i = 2; i < sieve_size; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < sieve_size; j+=i)
                sieve_ls[i] = 0;
            primes.pb(i);
        }
    } return;
}

void findFact(ll N) {
    ll sqrtN = sqrt(N);
    vii ans;
    for(ll i = 0; primes[i] <= sqrtN; i++) {
        while(N % primes[i] == 0) {
            N /= primes[i];
            if(!ans.size() || ans[ans.size()-1].first != primes[i])
                ans.pb(mp(primes[i], 0));
            ans[ans.size()-1].second++;
        }
    }
    if(N > 1)
        ans.pb(mp(N, 1));
    for(ll i = ans.size()-1; i >= 0; i--) {
        printf("%ld %ld", ans[i].first, ans[i].second);
        if(i) cout << ' ';
    }
    return;
}

int main() {
    ll P, E, number; Sieve();
    string my_str;
    while(getline(cin, my_str)) {
        stringstream my_ss(my_str);
        my_ss >> P;
        if(P != 0) {
            my_ss >> E;
            number = (ll)pow(P, E);
            while(my_ss >> P >> E)
                number *= (ll)pow(P, E);
        } else return 0;
        findFact(number-1);
        cout << endl;
    } return 0;
}
