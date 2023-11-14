#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vct;
typedef vector<vct> vvct;
ll T, N, M;
vvct dp, mark;

ll solve(ll idx, ll hours) {
    if(idx==N+1)
        return 0;
    ll &ref = dp[idx][hours];
    if(ref==-1) {
        ll res = INT_MIN;
        for(ll j=1;j<=M;j++) {
            if(hours-j>=0 && mark[idx][j]>=5)
                res = max(mark[idx][j] + solve(idx+1, hours-j),res);
        }
        ref = res;
    }
    return ref;
}

int main() {
    cin>>T;
    for(ll t=0;t<T;t++){
        cin>>N>>M;
        dp.resize(N+1);
        mark.resize(N+1);
        for(ll i=1;i<=N;i++) {
            dp[i].assign(M+1, -1);
            mark[i].resize(M+1);
        }
        for(ll i=1;i<=N;i++)
            for(ll j=1;j<=M;j++)
                cin >> mark[i][j];
        double res = (roundf((solve(1,M)/(double)N)*100))/(double)100;
        if(round(res)>=5)
            printf("Maximal possible average mark - %.2lf.\n", res);
        else
            printf("Peter, you shouldn't have played billiard that much.\n");
    }
    return 0;
}
