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
typedef int ll;
typedef vector<ll> vct;
typedef vector< vct > vvct;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector< vii > ADL;
typedef bitset<1 << 20> VL;

vector<string> dic, rules, ans;

void mount(ll p, ll i){
    if(i == rules[p].size()) {
        for(ll m=0; m<ans.size(); m++)
            cout << ans[m];
        cout << endl;
        return;
    }

    if(rules[p][i] == '0') {
        for(ll m=0; m<10; m++) {
            ans.pb(to_string(m));
            mount(p, i+1);
            ans.pp();
        }
    }

    if(rules[p][i] == '#') {
        for(ll m=0; m<dic.size(); m++) {
            ans.pb(dic[m]);
            mount(p, i+1);
            ans.pp();
        }
    }
}

int main() {
    string str;
    ll N, M;
    while(cin >> N) {
        dic.clear();
        rules.clear();
        for(ll i=0; i<N; i++) {
            cin >> str;
            dic.pb(str);
        }
        cin >> M;
        for(ll i=0; i<M; i++) {
            cin >> str;
            rules.pb(str);
        }
        cout << "--" << endl;
        for(ll p=0; p<rules.size(); p++)
           mount(p, 0);
    }

    return 0;
}
