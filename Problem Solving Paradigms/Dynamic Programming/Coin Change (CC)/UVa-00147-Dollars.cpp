#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vct;

#define max_c 10
#define max_v 30050

ll coins[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[31000];

/*
ll top_down(ll idx, ll sum) {
    if(sum == 0)
        return 1;
    if(sum < 0)
        return 0;
    ll &ref = dp[idx][sum];
    if(ref==-1) {
        ll res = 0;
        for(ll i=idx; i<11; i++)
            res += top_down(i, sum-coins[i]);
        ref = res;
    }
    return ref;
} */

void bot_up() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(ll i=0;i<=max_c;i++)
        for(ll j=coins[i];j<=max_v;j+=5)
            dp[j] = dp[j] + dp[j-coins[i]];
}

int main() {
    double K;
    bot_up();
    while(cin>>K, K > 0.03) {
        ll ans = roundf(K*100);
        printf("%6.2f%17lld\n", K, dp[ans]);
    }
    return 0;
}

