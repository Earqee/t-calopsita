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

ll N;
vct arr;
stack<ll>sol;

void LIS() {
    ll S= arr.size();
    vct lis, parent(S), pos(S);
    for(ll i=0;i<S; i++) {
        auto ref = lwb(all(lis), arr[i]);
        ll idx = ref - lis.begin();
        if(ref == lis.end())
            lis.pb(arr[i]);
        else
            *ref = arr[i];
        pos[idx] = i;
        if(idx == 0)
            parent[i] = -1;
        else
            parent[i] = pos[idx-1];
    }
    for(ll i=pos[lis.size()-1]; i>=0; i=parent[i])
        sol.push(arr[i]);
}

int main() {
    while(cin >> N)
        arr.pb(N);
    LIS();
    printf("%lld\n-\n", (ll)sol.size());
    while(!sol.empty()) {
        cout<<sol.top()<<endl;
        sol.pop();
    }
}
