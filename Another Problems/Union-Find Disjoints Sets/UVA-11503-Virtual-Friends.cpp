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
    vct p, r, c;
    UnionFind(ll N) {
        p.resize(N);
        c.assign(N, 1), r.assign(N, 0);
        for(ll i=1; i<N; i++)
            p[i] = i;
    }
    ll findCount(ll i) {
        return c[findSet(i)];
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
        if(r[pi] > r[pj]) {
            p[pj] = pi;
            c[pi] += c[pj];
        } else {
            p[pi] = pj;
            c[pj] += c[pi];
            if(r[pi] == r[pj])
                r[pj]++;
        }
    }
    void sse() {
        for(ll i=1; i<c.size(); i++)
            cout << c[i] << " ";
        cout << endl;
        for(ll i=1; i<p.size(); i++)
            cout << p[i] << " ";
        cout << endl;
    }
};

int main() {
    ll T, N;
    cin >> T;
    while(T--) {
        cin >> N;
        map<string, ll> mapper;
        ll map_size = 0;
        UnionFind net((++N)--);
        while(N--) {
            string v1, v2;
            cin >> v1 >> v2;
            if(mapper[v1] == 0) mapper[v1] = ++map_size;
            if(mapper[v2] == 0) mapper[v2] = ++map_size;
            net.UnionSet(mapper[v1], mapper[v2]);
            cout << net.findCount(mapper[v1]) << endl;
        }
    }
    return 0;
}
