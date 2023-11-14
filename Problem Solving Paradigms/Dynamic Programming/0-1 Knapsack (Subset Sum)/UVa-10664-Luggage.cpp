#include <bits/stdc++.h>
#include <sstream>

using namespace std;

#define pb push_back
#define pp pop_back
#define bin_s binary_search
#define all(E) E.begin(), E.end()


typedef long long ll;
typedef vector<ll> vct;

vct bag;
ll dp[20][200];
ll N;

ll solve(ll idx, ll frt, ll scd) {
    ll diff = abs(frt-scd);
    if(idx == N)
        return diff;
    if(dp[idx][diff] == -1) {
        ll with = solve(idx+1, frt+bag[idx], scd);
        ll without = solve(idx+1, frt, scd+bag[idx]);
        dp[idx][diff] = min(with, without);
    }
    return dp[idx][diff];
}

int main() {
    ll T;
    cin >> T; getchar();
    for(ll t=0; t<T; t++) {
        string array;
        getline(cin, array);
        istringstream ss(array);
        ll num;
        while(ss >> num)
            bag.pb(num);
        N = bag.size();
        memset(dp, -1, sizeof(dp));
        cout << (solve(0, 0, 0) ? "NO": "YES") << endl;
        bag.clear();
    }
    return 0;
}
