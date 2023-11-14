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
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

vct first, second;
ll dp[21][21];
ll dp2[21][21];

ll recursive_count, iterative_count;

ll topdown(ll frt_limit, ll scd_limit) {
    recursive_count++;
    if(!frt_limit || !scd_limit)
        return dp[frt_limit][scd_limit] = 0;

    if(dp[frt_limit][scd_limit] != -1)
        return dp[frt_limit][scd_limit];

    if(first[frt_limit-1] == second[scd_limit-1])
        return dp[frt_limit][scd_limit]
            = 1 + topdown(frt_limit-1, scd_limit-1);
    else
        return dp[frt_limit][scd_limit] =
            max(topdown(frt_limit-1, scd_limit), topdown(frt_limit, scd_limit-1));
}

//Needleman-Wunsch algorithm
ll botup(ll N) {
    for(ll i=1;i<=N;i++) {
        for(ll j=1;j<=N;j++) {
            iterative_count++;
            if(first[i-1] == second[j-1])
                dp2[i][j] = 1 + dp2[i-1][j-1];
            else
                dp2[i][j] = max(dp2[i-1][j], dp2[i][j-1]);
        }
    }
    return dp2[N][N];
}


int main() {
    ll N, num; string str;
    cin >> N;
    first.resize(N);
    second.resize(N);
    for(ll i=1;i<=N;i++) {
        cin >> num;
        first[num-1] = i;
    }
    getchar();
    while(getline(cin, str)) {
        recursive_count = iterative_count = 0;
        istringstream ss(str);
        memset(dp, -1, sizeof(dp));
        memset(dp2, 0, sizeof(dp));
        for(ll i=1;i<=N; i++) {
            ss >> num;
            second[num-1] = i;
        }
        cout << botup(N) << endl;
    }
    return 0;
}

