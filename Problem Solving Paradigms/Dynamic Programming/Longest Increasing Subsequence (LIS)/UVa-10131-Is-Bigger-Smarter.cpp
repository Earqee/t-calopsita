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

vii arr;
map<ii, ll> ind;

void LIS() {
    vct lis, parent(arr.size()), pos(arr.size());
    for(ll i=0;i<arr.size();i++) {
        ll cur = arr[i].second;
        auto ref = lwb(all(lis), cur);
        ll idx = ref - lis.begin();
        if(ref == lis.end())
            lis.pb(cur);
        else
            *ref = cur;
        pos[idx] = i;
        if(idx == 0)
            parent[i] = -1;
        else
            parent[i] = pos[idx-1];
    }
    stack<ll> ans;
    cout << lis.size() << endl;
    for(ll i=pos[lis.size()-1]; i>=0;i=parent[i])
       ans.push(i);
    while(!ans.empty()) {
        cout<< ind[arr[ans.top()]]+1 << endl;
        ans.pop();
    }
}

int main() {
    ll N, M;
    while(cin >> N >> M) {
        if(!ind.count({M,N}))
            ind[{M,N}] = arr.size();
        arr.pb({M, N});
    }
    sort(all(arr));
    reverse(all(arr));
    LIS();
}
