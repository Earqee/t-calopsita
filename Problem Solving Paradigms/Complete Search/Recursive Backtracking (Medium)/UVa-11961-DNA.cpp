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

ll arr[] = {'A', 'C', 'G', 'T'};
vector<string> sol;
ll N, K;

void mount(string &seq, ll pos, ll mut) {
    if(mut == K) {
        sol.pb(seq);
        return;
    }
    if(pos == N)
        return;
    ll save = seq[pos];
    for(ll i=0; i<4; i++) {
        seq[pos] = arr[i];
        mount(seq, pos+1, mut+1);
        seq[pos] = save;
    }
    mount(seq, pos+1, mut);
}

int main() {
    string input;
    ll T;
    cin >> T;
    while(T--) {
        cin >> N >> K >> input;
        sol.pb(input);
        mount(input, 0, 0);
        sort(all(sol));
        ll size = sol.size();
        for(ll i=0; i+1<sol.size(); i++)
            if(sol[i] == sol[i+1])
                sol[i] = "", size--;
        cout << size << endl;
        for(ll i=0; i<sol.size(); i++) {
            if(sol[i].size())
                cout << sol[i] << endl;
        }
        sol.clear();
    }
    return 0;
}

