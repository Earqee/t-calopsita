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

vct arr;
ll N;

void LIS(vct &ans){
    vct lis;
    ans.assign(arr.size(), 0);
    for(ll i=0;i<arr.size();i++) {
        auto ref = lwb(all(lis), arr[i]);
        if(ref == lis.end())
            lis.pb(arr[i]);
        else
            *ref = arr[i];
        ans[i] = max(ans[i], (ll)lis.size());
    }
}

int main() {
    while(cin >> N) {
        vct left(N), right(N);
        arr.resize(N);
        for(ll i=0;i<N;i++)
            cin>>arr[i];
        LIS(left);
        reverse(all(arr));
        LIS(right);
        ll resp = 0;
        for(ll i=0;i<N;i++)
            resp = max(resp, min(left[i], right[N-i-1]));
        cout << 2*resp-1 << endl;
        arr.clear();
    }
    return 0;
}
