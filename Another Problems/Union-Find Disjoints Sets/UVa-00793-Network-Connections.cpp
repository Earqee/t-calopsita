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

class UnionFind {
private:
public:
    vct p, r;
    UnionFind(ll N) {
        p.resize(N);
        r.assign(N, 0);
        for(ll i=1; i<N; i++)
            p[i] = i;
    }
    ll findSet(ll i) {
        return p[i] == i ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(ll i, ll j) {
        return findSet(i) == findSet(j);
    }
    void UnionSet(ll i, ll j) {
        ll pi = findSet(i), pj = findSet(j);
        if(pi == pj)
            return;
        if(r[pi] > r[pj])
            p[pj] = pi;
        else {
            p[pi] = pj;
            if(r[pi] == r[pj])
                r[pj]++;
        }
    }
};

int main() {
    ll N, T;
    cin >> T;
    while(T--) {
        cin >> N; getchar();
        UnionFind set((++N)--);
        ll suc = 0, fail = 0;
        string input, op;
        while(getline(cin, input), !input.empty()) {
            ll v1, v2;
            istringstream ss(input);
            ss >> op >> v1 >> v2;
            if(op == "c")
                set.UnionSet(v1, v2);
            if(op == "q") {
                ll add = set.isSameSet(v1, v2) == true ? 1 : 0;
                suc += add;
                fail += 1 - add;
            }
        }
        printf("%lld,%lld\n", suc, fail);
        if(T) cout << endl;
    }
    return 0;
}
