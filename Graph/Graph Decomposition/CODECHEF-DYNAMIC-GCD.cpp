//I'm at tjss@ic.ufal.br

#include <bits/stdc++.h>

#define pb push_back

using namespace std;
typedef int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vbo;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll GCD(ll a,ll b) {if(b>a) swap(a, b); return b==0 ? a:GCD(b, a%b);}
ll LCD(ll a, ll b) {return a*b/GCD(a,b);}
ll ABS(ll a) {return a>0?a:-a;}

vvll graph;

class SegmentTree {

private:
    vll leftmost, rightmost, lazy, gcd, st;
    ll arr_size;
public:
#define LEFT(idx) (idx<<1)
#define RIGHT(idx) ((idx<<1)|1)
#define MID(id,ix) ((id+ix)>>1)
    void update(ll idx) {
        //Store the leftmost value
        leftmost[idx] = leftmost[(LEFT(idx))] + lazy[idx];
        //Store the rightmost value
        rightmost[idx] = rightmost[RIGHT(idx)] + lazy[idx];
        //Store the non-inclusive gdc( (leftmore, rightmost) )
        gcd[idx] = GCD(gcd[LEFT(idx)], gcd[RIGHT(idx)]);
        //Store the inclusive gdc( children(leftmost-rightmost), (leftmost-rightmost) )
        gcd[idx] = GCD(gcd[idx], ABS(rightmost[LEFT(idx)]-leftmost[RIGHT(idx)]));
    }
    void build(ll idx, ll left, ll right, vll &arr) {
        if(left == right) {
            st[idx] = leftmost[idx] = rightmost[idx] = arr[left];
            return;
        }
        ll mid = MID(left,right);
        build(LEFT(idx), left, mid, arr);
        build(RIGHT(idx), mid+1, right, arr);
        update(idx);
    }
    void push(ll idx, ll left, ll right, ll L, ll R, ll val) {
        if(left > R || right < L)
            return;
        if(left >= L && right <= R) {
            leftmost[idx] += val;
            rightmost[idx] += val;
            lazy[idx] += val;
            return;
        }
        ll mid = MID(left, right);
        push(LEFT(idx), left, mid, L, R, val);
        push(RIGHT(idx), mid+1, right, L, R, val);
        update(idx);
    }
    ll query(ll idx, ll left, ll right, ll L, ll R, ll parent_lazy) {
        //Remember this: gcd(0, X) = gcd(X, 0) = X
        if(left > R || right < L)
            return 0;
        //Trick here: (this is non-trivial, ask me)
        //We won't actually update, never
        if(left >= L && right <= R)
            return GCD(leftmost[idx]+parent_lazy, gcd[idx]);
        parent_lazy += lazy[idx];
        ll mid = MID(left, right);
        return GCD( query(LEFT(idx), left, mid, L, R, parent_lazy),
                query(RIGHT(idx), mid+1, right, L, R, parent_lazy) );
    }
    void push(ll L, ll R, ll val) {
        if(L > R) swap(L, R);
        push(1, 0, arr_size-1, L, R, val);
    }
    ll query(ll L, ll R) {
        if(L > R) swap(L, R);
        return query(1, 0, arr_size-1, L, R, 0);
    }
public:
    SegmentTree(vll &arr) {
        arr_size = arr.size();
        st.assign(4*arr_size, 0);
        leftmost.assign(4*arr_size, 0);
        rightmost.assign(4*arr_size, 0);
        lazy.assign(4*arr_size, 0);
        gcd.assign(4*arr_size, 0);
        build(1, 0, arr_size-1, arr);
    }
};

class HLD {
private:
   ll number_of_chains;
   vll subtree_size, parent, heavy_child,
       chain_id, chain_pos, chain_depth, chain_root;
   vvll chain;
   vector<SegmentTree> st;
public:
    ll find_size(ll u, ll p) {
        subtree_size[u] = 1, parent[u] = p, heavy_child[u] = -1;
        ll sucessor_size = 0;
        for(ll v : graph[u]) {
            if(v == parent[u])
                continue;
            subtree_size[u] += find_size(v, u);
            if(subtree_size[v] > sucessor_size)
                heavy_child[u] = v, sucessor_size = subtree_size[v];
        }
        return subtree_size[u];
    }
    void chain_assign(ll u, ll chain_number, ll d, vll &arr) {
        chain_id[u] = chain_number;
        chain_pos[u] = chain[chain_number].size();
        chain[chain_number].pb(arr[u]);
        for(ll v : graph[u]) {
            if(v == parent[u]) {
                continue;
            } else if(v == heavy_child[u]) {
                chain_assign(v, chain_number, d, arr);
            } else {
                number_of_chains++;
                chain_root[number_of_chains] = u;
                chain_depth[number_of_chains] = d+1;
                chain_assign(v, number_of_chains, d+1, arr);
            }
        }
    }
    void decompose(ll u, vll &arr) {
        find_size(u, -1);
        number_of_chains = 0;
        chain_root[0] = 0;
        chain_depth[0] = 0;
        chain_assign(u, number_of_chains, 0, arr);
        for(ll i=0; i<=number_of_chains; i++)
            st.pb(SegmentTree(chain[i]));
    }
    HLD(ll u, ll N, vll &arr) {
        subtree_size.resize(N), parent.resize(N),
        heavy_child.resize(N), chain_id.resize(N),
        chain_pos.resize(N), chain_root.resize(N),
        chain_depth.resize(N), chain.resize(N);
        decompose(u, arr);
    }
    ll queryPath(ll u, ll v) {
        ll chain_u = chain_id[u], chain_v = chain_id[v];
        ll gcd = 0; // Our answer, remember GCD(X,0)=X
        while(chain_u != chain_v) {
            if(chain_depth[chain_u] > chain_depth[chain_v]) {
                gcd = GCD(gcd, st[chain_u].query(0, chain_pos[u]));
                u = chain_root[chain_u];
                chain_u = chain_id[u];
            }
            else {
                gcd = GCD(gcd, st[chain_v].query(0, chain_pos[v]));
                v = chain_root[chain_v];
                chain_v = chain_id[v];
            }
        }
        gcd = GCD(gcd, st[chain_u].query(chain_pos[u], chain_pos[v]));
        return gcd;
    }
    void updatePath(ll u, ll v, ll val) {
        ll chain_u = chain_id[u], chain_v = chain_id[v];
        while(chain_u != chain_v) {
            if(chain_depth[chain_u] > chain_depth[chain_v]) {
                st[chain_u].push(0, chain_pos[u], val);
                u = chain_root[chain_u];
                chain_u = chain_id[u];
            }
            else {
                st[chain_v].push(0, chain_pos[v], val);
                v = chain_root[chain_v];
                chain_v = chain_id[v];
            }
        }
        st[chain_u].push(chain_pos[u], chain_pos[v], val);
    }
};

int main() {
    ll N, Q, u, v, val;
    string str;
    //D-Allocation for now
    cin >> N;
    vll arr(N);
    graph.resize(N);
    //Read Tree of N-1 edges
    for(ll i=1; i<N;i++) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    for(ll i=0;i<N;i++)
        cin >> arr[i];
    //Generate HLD for Tree
    HLD hld(0, arr.size(), arr);
    //Process queries in O(log^2(N)) time
    cin >> Q;
    for(ll i=0;i<Q;i++) {
        cin >> str;
        if(str == "F") {
            cin >> u >> v;
            if(i) cout << endl;
            cout << hld.queryPath(u,v);
        }
        else  {
            cin >> u >> v >> val;
            hld.updatePath(u, v, val);
        }
    }
    return 0;
}
