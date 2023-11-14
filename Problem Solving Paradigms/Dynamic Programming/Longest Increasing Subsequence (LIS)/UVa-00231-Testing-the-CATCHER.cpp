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

using namespace std;
typedef long long ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

ll LIS(const vct &arr) {
    vct lis;
    for(ll i=0;i<arr.size();i++) {
        auto idx = upb(all(lis), arr[i]);
        if(idx == lis.end())
            lis.pb(arr[i]);
        else
            *idx = arr[i];
    }
    return lis.size();
}

int main() {
    ll N, M, counter = 0; vct arr;
    while(cin >> N, N != -1) {
        if(counter) cout << endl;
        arr.pb(N);
        while(cin >> M, M != -1)
            arr.pb(M);
        reverse(all(arr));
        printf("Test #%lld:\n  maximum possible interceptions: %lld\n",
            ++counter, LIS(arr));
        arr.clear();
    }
    return 0;
}
