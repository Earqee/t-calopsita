#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vct;

#define CREDIT 200
ll M, N;
vct price, favour;

ll tabu_dp() {
    M += CREDIT;
    ll dp[N+1][M+1], keep[N+1][M+1], budget=0;

    for(ll i=0;i<=M;i++)
        dp[0][i] = 0;

    for(ll i=1; i<=N;i++) {
        for(ll j=0;j<=M;j++) {
            if(j-price[i]>=0 && favour[i]+dp[i-1][j-price[i]] >= dp[i-1][j]) {
                keep[i][j] = 1;
                dp[i][j] = favour[i] + dp[i-1][j-price[i]];
            }
            else {
                keep[i][j] = 0;
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(ll i=N, j=M; i>=1;i--) {
        if(keep[i][j]) {
            budget += price[i];
            j -= price[i];
        }
    }
    if(budget>2000)
        return dp[N][M];
    else
        return dp[N][M-200];
}

int main() {
    while(cin>>M>>N) {
        price.resize(N+1);
        favour.resize(N+1);
        for(ll i=1;i<=N;i++)
            cin >> price[i] >> favour[i];
        cout << tabu_dp() << endl;
    }
    return 0;
}
