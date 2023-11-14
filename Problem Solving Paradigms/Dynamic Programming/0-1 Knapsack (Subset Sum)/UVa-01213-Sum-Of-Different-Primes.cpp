#include <bits/stdc++.h>

#define pb push_back
#define pp pop_back
#define bin_s binary_search
#define all(E) E.begin(), E.end()

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vct;

#define max_c 10
#define max_v 30000

ll coins[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[30001];

int main() {
    double K;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(ll i=0;i<=max_c;i++)
        for(ll j=coins[i];j<=max_v;j+=5)
            dp[j] = dp[j] + dp[j-coins[i]];
    while(cin>>K, K!=0.0) {
        ll ans = round(K*100);
        printf("%6.2f%17lld\n", K, dp[ans]);
    }
    return 0;
}


using namespace std;
typedef long long ll;
typedef vector<ll> vct;
typedef bitset<1125> mask;

vct primes;
ll N, K;
ll dp[1125][1125][20];

void sieve(ll sieve_size) {
    mask is_prime;
    is_prime.set();
    for(ll i=2;i<sieve_size;i++) {
        if(is_prime[i]) {
            for(ll j=i*i; j<sieve_size; j+=i)
                is_prime[j] = 0;
            primes.pb(i);
        }
    }
}

ll solve(ll idx, ll sum, ll ch) {
    if(idx == primes.size())
        return 0;
    if(ch == 0 && sum == 0)
        return 1;
    if(ch == 0 && sum != 0)
        return 0;
    if(sum < 0)
        return 0;
    if(dp[idx][sum][ch] == -1) {
        ll with = solve(idx+1, sum-primes[idx], ch-1);
        ll without = solve(idx+1, sum, ch);
        dp[idx][sum][ch] = with + without;
    }
    return dp[idx][sum][ch];
}

int main() {
    memset(dp, -1, sizeof(dp));
    sieve(1125);
    while(cin >> N >> K, N!=0 || K!=0)
        cout << solve(0, N, K) << endl;
    return 0;
}
