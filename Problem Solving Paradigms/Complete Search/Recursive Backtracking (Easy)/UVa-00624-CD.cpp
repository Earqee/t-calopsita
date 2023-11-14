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

class Set {
    //For efficient O(1) operations
private:
    vct set, opt;
    ll sum, maximum, optimal;
public:
    Set(ll maximum) {
        this->sum = 0;
        this->maximum = maximum;
        this->optimal = INT_MAX;
    }
    void add(ll num) {
        sum += num;
        set.pb(num);
    }
    void remove() {
        sum -= set.back();
        set.pp();
    }
    void save() {
        if(sum > maximum)
            return;
        if(maximum-sum < optimal) {
            this->opt = this->set;
            optimal = abs(maximum-sum);
        }

    }
    void print() {
        for(ll i=0; i<opt.size();i++)
            cout << opt[i] << ' ';
        printf("sum:%d\n", maximum-optimal);
    }
};

void search(ll i, ll n, vct &arr, Set &set) {
    for(ll k=i; k<n; k++) {
        set.add(arr[k]);
        set.save();
        if(k+1 < n)
            search(k+1, n, arr, set);
        set.remove();
    }
}

int main() {
    ll N, K, num;
    string str;
    while(cin >> N) {
        cin >> K;
        vct arr(K);
        for(ll i=0; i<K; i++) {
            cin >> num;
            arr[i] = num;
        }
        Set set(N);
        search(0, arr.size(), arr, set);
        set.print();
    }
    return 0;
}
