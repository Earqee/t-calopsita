#include <bits/stdc++.h>
#define pb push_back
#define res resize

using namespace std;
typedef long long ll;
typedef vector<ll> v1ct;
typedef vector<v1ct> v2ct;

bool possible = true;

class CD {
private:
public:
    long centroid;
    v2ct _tree, _sons;
    v1ct _level, _par, _size, _city;

    long subtsize(long u, long p) {
        _size[u] = 1;
        for(long v : _tree[u]) {
            if(v!=p && _level[v] < 0) {
                _size[u] += subtsize(v, u);
            }
        }
        return _size[u];
    }
    long findcentroid(long u, long p, long n) {
        for(long v : _tree[u])
             if(v!=p && _level[v]<0 && _size[v]>n/2)
                 return findcentroid(v, u, n);
        return u;
    }
    long decompose(long root, long par, long city) {
        if(city > 'Z') possible = false;
        subtsize(root, -1);
        long u = findcentroid(root, -1, _size[root]);
        _city[u] = city;
        _par[u] = par;
        _level[u] = par != -1 ? _level[par]+1 : 0;
        _size[u] = 1;
        for(long v : _tree[u]) {
            if(v!=par && _level[v]<0) {
                long k = decompose(v, u, city+1);
                _sons[u].pb(k);
                _size[u] += _size[k];
            }
        }
        return u;
    }
    CD (v2ct &tree, long root) {
        long N = tree.size();
        _tree=tree; _sons.resize(N);
        _size.res(N), _par.res(N), _city.res(N), _level.assign(N, -1);
        centroid = decompose(root, -1, 'A');
    }
    void print() {
        if(!possible) {
            cout << "Impossible!";
            return;
        }
        for(long i=0; i<_city.size();i++) {
            if(i) cout<< " ";
            printf("%c", _city[i]);
        }
    }
};

int main() {
    v2ct tree;
    ll N, v1, v2;
    cin >> N;
    tree.resize(N);
    for(long i=0;i<N-1; i++) {
        cin >> v1 >> v2;
        tree[--v1].pb(--v2);
        tree[v2].pb(v1);
    }
    CD cd(tree, 0);
    cd.print();
    return 0;
}
