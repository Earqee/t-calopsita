#include <bits/stdc++.h>

#define frt first
#define scd second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vct;

ll T,W, N;
vct cost, gold;

void solve() {
    ll dp[N+1][T+1], keep[N+1][T+1];
    for(ll i=0;i<=T;i++)
        dp[0][i] = 0;
    for(ll i=1;i<=N;i++) {
        for(ll j=0; j<=T; j++) {
            if(j-cost[i]>=0 && gold[i]+dp[i-1][j-cost[i]] > dp[i-1][j]) {
                dp[i][j] = gold[i]+dp[i-1][j-cost[i]];
                keep[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j];
                keep[i][j] = 0;
            }
        }
    }
    stack<ii> ans;
    for(ll i=N, j=T; i>=0; i--) {
        if(keep[i][j]) {
            ans.push({cost[i]/(3*W), gold[i]});
            j -= cost[i];
        }
    }
    printf("%lld\n%lld\n", dp[N][T], (ll)ans.size());
    while(!ans.empty()) {
        ii cur = ans.top(); ans.pop();
        printf("%lld %lld\n", cur.frt, cur.scd);
    }
}

int main() {
    bool prt_l = false;
    while(cin>>T>>W) {
        if(prt_l) cout << endl; else prt_l = true;
        cin >> N;
        cost.resize(N+1), gold.resize(N+1);
        for(ll i=1;i<=N;i++) {
            cin >> cost[i] >> gold[i];
            cost[i] *= 3*W;
        }
        solve();
    }
    return 0;
}
