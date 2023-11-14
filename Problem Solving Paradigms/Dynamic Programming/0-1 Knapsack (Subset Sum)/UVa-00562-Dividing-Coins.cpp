#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;

vct arr;
vvct dp;
ll M,T;

ll sol(ll i, ll m1, ll m2) {
    ll cur = abs(m1-m2);
    if(i==M)
        return cur;
    if(dp[i][cur]==-1)
        dp[i][cur] = min(sol(i+1,m1+arr[i],m2),sol(i+1,m1,m2+arr[i]));
    return dp[i][cur];
}

int main() {
    cin >> T;
    for(ll t=0;t<T;t++) {
        cin >> M;
        arr.resize(M), dp.resize(M);
        for(ll m=0;m<M;m++) {
            cin>>arr[m];
            dp[m].assign(50001, -1);
        }
       cout << sol(0,0,0) << endl;
    }
    return 0;
}
