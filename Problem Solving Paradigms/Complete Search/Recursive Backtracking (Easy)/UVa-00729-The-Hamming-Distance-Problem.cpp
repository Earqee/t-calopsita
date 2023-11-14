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

class Str {
    //For efficient O(1) operations
private:
    char *str;
    int set, size, H;
public:
    Str(ll N, ll H) {
        this->str = new char[N];
        this->set = this->size = 0;
        this->H = H;
    }
    void zero() {
        str[size] = '0';
        size++;
    }
    void one() {
        str[size] = '1';
        set++, size++;
    }
    void reduce() {
        if(str[size])
            set--;
        size--;
    }
    void print() {
        if(set == H) {
            for(ll i=0; i<size; i++)
                cout << str[i];
            cout << endl;
        }
    }
};

void solve(ll k, ll n, Str &str) {
    if(k >= n) {
        str.print();
        return;
    }
    str.zero();
    solve(k+1, n, str);
    str.reduce();

    str.one();
    solve(k+1, n, str);
    str.reduce();
}

int main() {
    ll T, N, H;
    cin >> T;
    for(ll i=0; i<T; i++) {
        if(i) cout << endl;
        cin >> N >> H;
        Str str(N, H);
        solve(0, N, str);
    }
    return 0;
}
