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
stack<ll> sol;
ll T;
string str;

void LIS() {
    ll N = arr.size();
    vct lis, parent(N), pos(N);
    for(ll i=0;i<N;i++) {
        auto ref = lwb(all(lis),arr[i]);
        ll idx = ref - lis.begin();
        if(ref == lis.end())
            lis.pb(arr[i]);
        else
            *ref = arr[i];
        pos[idx] = i;
        if(idx==0)
            parent[i] = -1;
        else
            parent[i] = pos[idx-1];
    }
    for(ll i=pos[lis.size()-1]; i>=0; i=parent[i])
        sol.push(arr[i]);
}

int main() {
    scanf("%lld  ", &T);
    for(ll i=0;i<T; i++) {
        if(i) cout << endl;
        while(getline(cin, str), str.size())
            arr.pb(stol(str));
        LIS();
        cout<<"Max hits: "<<sol.size()<<endl;
        while(!sol.empty()) {
            cout<<sol.top()<<endl;
            sol.pop();
        }
        arr.clear();
    }
    return 0;
}
