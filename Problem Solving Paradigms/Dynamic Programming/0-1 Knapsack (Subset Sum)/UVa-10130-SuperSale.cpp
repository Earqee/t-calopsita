#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
#define MAX 1000

ll v[MAX], w[MAX];
vvct dp;
ll T,N,P,M;

ll sol(ll i, ll cap) {
    if(i == N)
        return 0;
    if(dp[i][cap]==-1) {
        dp[i][cap] = max(sol(i+1,cap),
                (cap-w[i]>=0? v[i] + sol(i+1, cap-w[i]):0));
    }
    return dp[i][cap];
}

int main() {
    cin >> T;
    for(ll t=0;t<T;t++) {
        cin >> N;
        dp.resize(N);
        for(ll n=0;n<N;n++) {
            cin>>v[n]>>w[n];
            dp[n].assign(31, -1);
        }
        cin >> P;
        ll sum = 0;
        for(ll p=0;p<P;p++) {
            cin>>M;
            sum += sol(0, M);
        }
        cout << sum << endl;
    }
    return 0;
}
