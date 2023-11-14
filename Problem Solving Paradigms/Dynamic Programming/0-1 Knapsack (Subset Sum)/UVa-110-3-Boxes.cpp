#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pop_back
#define bin_s binary_search
#define all(E) E.begin(), E.end();

typedef long long ll;
typedef vector<ll> vct;

ll N;
ll dp[1010][3010];
vct wgt, maxl;

ll solve(ll idx, ll cap, bool base) {
    if(idx == N)
        return 0;
    if(dp[idx][cap] == -1) {
        ll with = 0, without = 0;
        if(cap-wgt[idx]>=0)
            with = 1 + solve(idx+1, base?maxl[idx]:min(cap-wgt[idx], maxl[idx]), false);
        without = solve(idx+1, cap,base);
        dp[idx][cap] = max(with, without);
    }
    return dp[idx][cap];
}

int main() {
    while(cin>>N, N!=0) {
        wgt.resize(N);
        maxl.resize(N);
        for(ll i=0;i<N;i++)
            cin >> wgt[i] >> maxl[i];
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 3005, true) << endl;
    }
    return 0;
}
