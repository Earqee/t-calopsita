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

#define MAX ((ll)1e6+1)

VL sieve_ls;
vct primes;
vii rever;

void Sieve() {
    sieve_ls.set();
    sieve_ls[0] = sieve_ls[1] = 0;
    for(ll i = 2; i < MAX; i++) {
        if(sieve_ls[i]) {
            for(ll j = i*i; j < MAX; j+=i)
                sieve_ls[j] = 0;
            primes.pb(i);
        }
    } return;
}

ll sumPF(ll N) {
    ll sqrtN = sqrt(N);
    ll sum = 0;
    for(ll i = 0; primes[i] <= sqrtN; i++) {
        while(N % primes[i] == 0) {
            N /= primes[i];
            sum++;
        }
    }
    if(N > 1)
        sum++;
    return sum;
}

ll findInv(ll N) {
    string my_str = to_string(N);
    string my_rev;
    for(ll i = my_str.size()-1; i >= 0; i--)
        my_rev.pb(my_str[i]);
    while(my_rev.size() <  7)
        my_rev += "0";
    return stoi(my_rev);
}

class FenwickTree {
private:
    vct ft;
public:
    FenwickTree(ll N) { ft.assign(N+1, 0); }
    ll RSQ(ll idx) {
        ll sum = 0;
        for(; idx; idx -= (idx & -idx)) sum += ft[idx];
        return sum;
    }
    ll RSQ(ll a, ll b) {
        return RSQ(b) - (a == 0? 0 : RSQ(a-1));
    }
    ll adjust(ll idx, ll val) {
        for(; idx < ft.size(); idx += (idx & -idx)) ft[idx] += val;
    }
    ll bin_s(ll a, ll b, ll search) {
        ll mid = (a + b)/2;
        ll rsq = RSQ(mid);
        if(search < rsq) {
            return bin_s(a, mid, search);
        } else if(search > rsq) {
            return bin_s(mid+1, b, search);
        } else
            return mid;
    }
};

ll bin_search(ll a, ll b, ll search, vii &arr) {
    ll mid = (a + b)/2;
    if(search > arr[mid].first)
        return bin_search(mid+1, b, search, arr);
    else if(search < arr[mid].first)
        return bin_search(a, mid, search, arr);
    else
        return mid;
}

FenwickTree buildFenTree() {
    for(ll i = 0; i < primes.size() && primes[i] < MAX; i++) {
        ll inv = findInv(primes[i]);
        if(inv > 1000000) {
            rever.pb(mp(inv, sumPF(inv)));
        }
    }
    sort(all(rever));
    FenwickTree ft(rever.size()+1);
    for(ll i = 1; i <= rever.size(); i++) {
        ft.adjust(i, rever[i-1].second);
    }
    return ft;
}

int main() {
    Sieve();
    FenwickTree ft = buildFenTree();
    FenwickTree dx(rever.size()+1);
    for(ll i = 1; i <= rever.size(); i++)
        dx.adjust(i, 1);
    string my_str; ll D;
    while(cin >> my_str >> D) {
        if(my_str == "q") {
            printf("%lld\n", ft.RSQ(dx.bin_s(0, rever.size(), D+1)));
        } else {
            ll idx = bin_search(0, rever.size(), D, rever);
            ft.adjust(idx+1, -rever[idx].second);
            dx.adjust(idx+1, -1);
        }
    } return 0;
}
