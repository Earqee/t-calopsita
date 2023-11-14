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

class SegmentTree {
private:
    vct freq, arr, st;
public:
#define left(idx) (idx << 1)
#define right(idx) ((idx << 1)+1)
    ll freqCount(ll elem, ll L, ll R) {
        ll lower = lwb(arr.begin() + L, arr.begin() + R + 1, elem) - arr.begin();
        ll upper = upb(arr.begin() + L, arr.begin() + R + 1, elem) - arr.begin();
        return freq[upper-1] - freq[lower] + 1;
    }
    void freqInit() {
        freq.resize(arr.size());
        ll last = arr[0], counter = 1;
        for(ll i = 0; i < arr.size(); i++) {
            if(last != arr[i]) {
                counter = 1;
                last = arr[i];
            }
            freq[i] = counter++;
        }
    }
    void build(ll idx, ll L, ll R) {
        if(L == R) {
            st[idx] = 1;
        } else {
            ll mid = (L+R)/2;
            build(left(idx), L, mid);
            build(right(idx), mid+1, R);
            ll ans = max(st[left(idx)], st[right(idx)]);
            if(arr[mid] == arr[mid+1]) {
                ll alterAns = freqCount(arr[mid], L, R);
                ans = alterAns > ans ? alterAns : ans;
            }
            st[idx] = ans;
        }
    }
    ll RMQ(ll idx, ll i, ll j, ll L, ll R) {
        if(R < i || L > j) return -1;
        if(i <= L && R <= j) {
            return st[idx];
        }
        ll mid = (L+R)/2;
        ll left = RMQ(left(idx), i, j, L, mid);
        ll right = RMQ(right(idx), i, j, mid+1, R);
        ll ans = max(left, right);
        if(arr[mid] == arr[mid+1] && i <= mid && mid+1 <= j) {
            ll alterAns = freqCount(arr[mid], i, j);
            ans = alterAns > ans ? alterAns : ans;
        }
        return ans;
    }
    ll RMQ(ll i, ll j) {
        return RMQ(1, i, j, 0, arr.size()-1);
    }
    SegmentTree(vct &arr) {
        this->arr = arr;
        freqInit();
        st.assign(4 * arr.size(), 0);
        build(1, 0, arr.size()-1);
    }
};

int main() {
    ll N, Q, num, i, j;
    while(cin >> N >> Q) {
        vct arr;
        while(N--) {
            cin >> num;
            arr.pb(num);
        }
        SegmentTree st(arr);
        while(Q--) {
            cin >> i >> j;
            cout << st.RMQ(i-1, j-1) << endl;
        }
    }
    return 0;
}


