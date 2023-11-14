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


class FenwickTree {
private:
    vct ft;
public:
    ll at(ll idx) { return ft[idx]; }
    FenwickTree(ll N) { ft.assign(N+1, 0); }
    ll RSQ(ll idx) {
        ll sum = 0;
        for(; idx; idx -= (idx & -idx)) { sum += ft[idx]; }
        return sum;
    }
    ll RSQ(ll a, ll b) {
        return RSQ(b) - (a == 0 ? 0 : RSQ(a-1));
    }
    ll adjust(ll idx, ll val) {
        for(; idx < ft.size(); idx += (idx & -idx)) { ft[idx] += val; }
    }
};

int main() {
    string my_str;
    ll N, X, D, num, count = 0;
    while(cin >> N, N != 0) {
        if(count++) cout << endl;
        printf("Case %lld:\n", count);
        vct my_arr(N+1);
        FenwickTree ft(N+1);
        for(ll i = 1; i <= N; i++) {
            cin >> num;
            my_arr[i] = num;
            ft.adjust(i, num);
        }
        while(cin >> my_str, my_str != "END") {
            cin >> X >> D;
            if(my_str == "S") {
                ft.adjust(X, D - my_arr[X]);
                my_arr[X] = D;
            } else {
                printf("%lld\n", ft.RSQ(X, D));
            }
        }
    } return 0;
}
